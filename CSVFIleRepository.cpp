#include "CSVFileRepository.h"
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using Repository::CSVRepository, std::to_string;


CSVRepository::CSVRepository() {
    fileName = "Scooters.csv";
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
             << statusToString(newObject.getStatus()) << "\n";

        file.close();
    } else {
        throw std::runtime_error("File could not be opened to open for writing.");
    }
}


void CSVRepository::remove(const Scooter &removedObject) {
    // Open the input file for reading
    std::ifstream inputFile(fileName);

    // Open a temporary output file for writing
    std::ofstream tempFile("temp.csv");

    std::string line;
    bool found = false;
    while (std::getline(inputFile, line)) {
        std::string id, model, commissionDateDay, commissionDateMonth, commissionDateYear, mileageStr, lastLocation, statusStr;
        std::stringstream ss(line);
        std::getline(ss, id, ',');
        std::getline(ss, model, ',');
        std::getline(ss, commissionDateDay, ',');
        std::getline(ss, commissionDateMonth, ',');
        std::getline(ss, commissionDateYear, ',');
        std::getline(ss, mileageStr, ',');
        std::getline(ss, lastLocation, ',');
        std::getline(ss, statusStr, ',');

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
        // Open the temporary file for reading
        std::ifstream tempInputFile("temp.csv");

        // Open the original file for writing
        std::ofstream outputFile(fileName, std::ofstream::trunc);

        // Overwrite the original file with the content of the temporary file
        outputFile << tempInputFile.rdbuf();

        // Close the files
        tempInputFile.close();
        outputFile.close();

        std::remove("temp.csv");  // Remove the temporary file
    } else {
        std::remove("temp.csv");
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

    // Open a temporary output file for writing
    std::ofstream tempFile("temp.csv");

    std::string line;
    bool found = false;
    while (std::getline(inputFile, line)) {
        std::string id, model, commissionDateDay, commissionDateMonth, commissionDateYear, mileageStr, lastLocation, statusStr;
        std::stringstream ss(line);
        std::getline(ss, id, ',');
        std::getline(ss, model, ',');
        std::getline(ss, commissionDateDay, ',');
        std::getline(ss, commissionDateMonth, ',');
        std::getline(ss, commissionDateYear, ',');
        std::getline(ss, mileageStr, ',');
        std::getline(ss, lastLocation, ',');
        std::getline(ss, statusStr, ',');
        std::getline(ss, statusStr, ',');

        if (id == updatedEntity.getId()) {
            // Update the fields with the new values
            std::string updatedLine = updatedEntity.getId() + ","
                                      + updatedEntity.getModel() + ","
                                      + std::to_string(updatedEntity.getCommissionDate().day) + ","
                                      + std::to_string(updatedEntity.getCommissionDate().month) + ","
                                      + std::to_string(updatedEntity.getCommissionDate().year) + ","
                                      + std::to_string(updatedEntity.getMileage()) + ","
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
        // Open the temporary file for reading
        std::ifstream tempInputFile("temp.csv");

        // Open the original file for writing
        std::ofstream outputFile(fileName, std::ofstream::trunc);

        // Overwrite the original file with the content of the temporary file
        outputFile << tempInputFile.rdbuf();

        // Close the files
        tempInputFile.close();
        outputFile.close();

        std::remove("temp.csv");  // Remove the temporary file
    } else {
        std::remove("temp.csv");
        throw std::runtime_error("Object not found in the file.");
    }
}

