#include "CSVFileRepository.h"
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using Repository::CSVRepository, std::to_string;


CSVRepository::CSVRepository(const string &_fileName) {
    fileName = _fileName;
}

void CSVRepository::add(const Scooter &newObject) {
    // Open the file in append mode
    std::ofstream file(fileName, std::ios::app);

    if (file.is_open()) {
        // Write the scooter data in CSV format
        file << newObject.getId() << ","
             << newObject.getModel() << ","
             << newObject.getCommissionDate().day << ","
             << newObject.getCommissionDate().month << ","
             << newObject.getCommissionDate().year << ","
             << newObject.getMileage() << ","
             << newObject.getLastLocation() << ","
             << static_cast<int>(newObject.getStatus()) << "\n";

        file.close();
    } else {
        throw std::runtime_error("File could not be opened to open for writing.");
    }
}


void CSVRepository::remove(const Scooter &removedObject) {
    // Open the input file for reading
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("File could not be open for reading.");
        return;
    }

    // Open a temporary output file for writing
    std::ofstream tempFile("temp.csv");
    if (!tempFile.is_open()) {
        throw std::runtime_error("File could not be open for removal.");
        inputFile.close();
        return;
    }

    string line;
    bool found = false;
    while (getline(inputFile, line)) {
        // Parse the line to retrieve the object data
        // Assuming the CSV format: id, model, commissionDate, mileage, lastLocation, status
        string id, model, commissionDate, mileageStr, lastLocation, statusStr;
        std::stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, model, ',');
        getline(ss, commissionDate, ',');
        getline(ss, mileageStr, ',');
        getline(ss, lastLocation, ',');
        getline(ss, statusStr, ',');

        // Compare the ID of the current object with the removedObject
        if (id == removedObject.getId()) {
            found = true;
            continue;  // Skip writing this line to the temporary file
        }

        // Write the line to the temporary file
        tempFile << line << "\n";
    }

    // Close the files
    inputFile.close();
    tempFile.close();

    if (found) {
        // Replace the original file with the temporary file
        if (std::rename("temp.csv", fileName.c_str()) != 0) {
            throw std::runtime_error("Unable to replace the original file.");
        }
    } else {
        std::remove("temp.csv");  // Remove the temporary file
        throw std::runtime_error("Object not found in the file.");
    }
}


vector<Scooter> CSVRepository::getAll() {
    vector<Scooter> scooters;

    // Open the CSV file for reading
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        // Handle the error if the file cannot be opened
        throw std::runtime_error("Unable to open file for reading.");
    }

    std::string line;
    while (getline(inputFile, line)) {
        // Parse the line to retrieve the object data
        string id, model, commissionDateDay, commissionDateMonth, commissionDateYear, mileageStr, lastLocation, statusStr;
        std::stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, model, ',');
        getline(ss, commissionDateDay, ',');
        getline(ss, commissionDateMonth, ',');
        getline(ss, commissionDateYear, ',');
        getline(ss, mileageStr, ',');
        getline(ss, lastLocation, ',');
        getline(ss, statusStr, ',');

        // Convert the extracted fields to appropriate types
        Domain::Date commissionDateObj{};
        commissionDateObj.day = stoi(commissionDateDay);
        commissionDateObj.month = stoi(commissionDateMonth);
        commissionDateObj.year = stoi(commissionDateYear);
        int mileage = stoi(mileageStr); // Convert mileageStr to integer
        static const std::map<std::string, Domain::Status> statusMap{
                {"parked",        Domain::Status::parked},
                {"reserved",      Domain::Status::reserved},
                {"inUse",         Domain::Status::inUse},
                {"inMaintenance", Domain::Status::inMaintenance},
                {"outOfService",  Domain::Status::outOfService},

        };
        Domain::Status status = statusMap.find(statusStr)->second;

        // Create a Scooter object and add it to the vector
        Scooter scooter(id, model, commissionDateObj, mileage, lastLocation, status);
        scooters.push_back(scooter);
    }

    inputFile.close();

    return scooters;
}


Scooter CSVRepository::getById(const string &objectId) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        // Error: Unable to open file for reading
        throw std::runtime_error("Error: Unable to open file for reading.");
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        string id, model, commissionDateDay, commissionDateMonth, commissionDateYear, mileageStr, lastLocation, statusStr;
        std::stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, model, ',');
        getline(ss, commissionDateDay, ',');
        getline(ss, commissionDateMonth, ',');
        getline(ss, commissionDateYear, ',');
        getline(ss, mileageStr, ',');
        getline(ss, lastLocation, ',');
        getline(ss, statusStr, ',');


        if (id == objectId) {
            // Convert the extracted fields to appropriate types
            Domain::Date commissionDateObj{};
            commissionDateObj.day = std::stoi(commissionDateDay);
            commissionDateObj.month = std::stoi(commissionDateMonth);
            commissionDateObj.year = std::stoi(commissionDateYear);
            int mileage = std::stoi(mileageStr);
            static const std::map<std::string, Domain::Status> statusMap{
                    {"parked",        Domain::Status::parked},
                    {"reserved",      Domain::Status::reserved},
                    {"inUse",         Domain::Status::inUse},
                    {"inMaintenance", Domain::Status::inMaintenance},
                    {"outOfService",  Domain::Status::outOfService},

            };
            Domain::Status status = statusMap.find(statusStr)->second;

            // Create and return the Scooter object
            return Scooter(id, model, commissionDateObj, mileage, lastLocation, status);
        }
    }

    // Error: Object with the specified ID not found
    throw std::runtime_error("Error: Object not found in the file.");

}


void CSVRepository::update(const Scooter &updatedEntity) {
    // Open the input file for reading
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Unable to open file for reading.");
    }

    // Open a temporary output file for writing
    std::ofstream tempFile("temp.csv");
    if (!tempFile.is_open()) {
        inputFile.close();
        throw std::runtime_error("Unable to open temporary file for writing.");
    }

    std::string line;
    bool found = false;
    while (std::getline(inputFile, line)) {
        string id, model, commissionDateDay, commissionDateMonth, commissionDateYear, mileageStr, lastLocation, statusStr;
        std::stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, model, ',');
        getline(ss, commissionDateDay, ',');
        getline(ss, commissionDateMonth, ',');
        getline(ss, commissionDateYear, ',');
        getline(ss, mileageStr, ',');
        getline(ss, lastLocation, ',');
        getline(ss, statusStr, ',');
        getline(ss, statusStr, ',');

        if (id == updatedEntity.getId()) {
            // Update the fields with the new values
            string updatedLine = updatedEntity.getId() + ","
                                      + updatedEntity.getModel() + ","
                                      + to_string(updatedEntity.getCommissionDate().day) + ","
                                      + to_string(updatedEntity.getCommissionDate().month) + ","
                                      + to_string(updatedEntity.getCommissionDate().year) + ","
                                      + to_string(updatedEntity.getMileage()) + ","
                                      + updatedEntity.getLastLocation() + ","
                                      + // Convert updatedEntity.getStatus() to string
                                      +"\n";
            tempFile << updatedLine;
            found = true;
        } else {
            // Write the original line to the temporary file
            tempFile << line << "\n";
        }
    }

    // Close the files
    inputFile.close();
    tempFile.close();

    if (found) {
        // Replace the original file with the temporary file
        if (std::rename("temp.csv", fileName.c_str()) != 0) {
            throw std::runtime_error("Unable to replace the original file.");
        }
    } else {
        std::remove("temp.csv");  // Remove the temporary file
        throw std::runtime_error("Object not found in the file.");
    }
}

