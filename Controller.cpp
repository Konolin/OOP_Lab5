#include "Controller.h"
#include <utility>
#include <exception>


using Controller::Ctr, std::invalid_argument, Domain::compareDateAscending, std::exception;


Ctr::Ctr(shared_ptr<Repo> repoObj) : repository(std::move(repoObj)) {}


void Ctr::dataCheck(const string &id, const string &model, Date commissionDate, int mileage,
                    const string &lastLocation) {
    // check if the id has exactly 3 letters
    if (id.length() != 3 || !hasThreeLetters(id))
        throw invalid_argument("The id is not valid.");

    // check if model is valid
    if (model.empty())
        throw invalid_argument("Model can not be an empty string.");

    // check if the commission date is valid
    if (commissionDate.day < 1 || commissionDate.day > 31)
        throw invalid_argument("Commission date day is not valid.");
    if (commissionDate.day == 31 && commissionDate.month % 2 == 0)
        throw invalid_argument("Commission date day is not valid.");
    if (commissionDate.day > 28 && commissionDate.month == 2 && commissionDate.year % 4 != 0)
        throw invalid_argument("Commission date day is not valid.");
    if (commissionDate.day > 29 && commissionDate.month == 2 && commissionDate.year % 4 == 0)
        throw invalid_argument("Commission date day is not valid.");
    if (commissionDate.month < 1 || commissionDate.month > 12)
        throw invalid_argument("Commission date month is not valid.");
    if (commissionDate.year > 2023)
        throw invalid_argument("Commission date year is not valid.");

    // check if mileage is valid
    if (mileage < 0)
        throw invalid_argument("Mileage can not be negative.");

    // check if lastLocation is valid
    if (lastLocation.empty())
        throw invalid_argument("The last location can not be an empty string.");
}


bool Ctr::add(const string &id, const string &model, const Date &commissionDate, int mileage,
              const string &lastLocation, const Status &status) {
    try {
        dataCheck(id, model, commissionDate, mileage, lastLocation);
    } catch (std::exception &e) {
        return false;
    }

    Scooter scooter(id, model, commissionDate, mileage, lastLocation, status);
    repository->add(scooter);
    return true;
}


bool Ctr::remove(const string &id) {
    if (!hasThreeLetters(id) && id.size() != 3)
        throw invalid_argument("Id is invalid.");

    for (auto &scooter: repository->getAll())
        if (scooter.getId() == id) {
            repository->remove(scooter);
            return true;
        }
    return false;
}


bool Ctr::editMileage(const string &id, int newMileage) {
    try {
        Scooter scooter = repository->getById(id);
        scooter.setMileage(newMileage);
        repository->updateEntity(scooter);
        return true;
    } catch (exception &e) {
        return false;
    }
}


bool Ctr::editLocation(const string &id, const string &newLastLocation) {
    try {
        Scooter scooter = repository->getById(id);
        scooter.setLastLocation(newLastLocation);
        repository->updateEntity(scooter);
        return true;
    } catch (exception &e) {
        return false;
    }
}


void Ctr::editStatus(const string &id, Status &newStatus) {
    try {
        Scooter scooter = repository->getById(id);
        scooter.setStatus(newStatus);
        repository->updateEntity(scooter);
    } catch (exception &e) {
        return;
    }
}


vector<Scooter> Ctr::sortedByCommissionDate() {
    vector<Scooter> sortedVector = repository->getAll();

    std::sort(sortedVector.begin(), sortedVector.end(), [](const Scooter &s1, const Scooter &s2) {
        return compareDateAscending(s1.getCommissionDate(), s2.getCommissionDate());
    });

    return sortedVector;
}


bool Ctr::reserveScooter(const string &id) {
    try {
        Scooter scooter = repository->getById(id);

        if (scooter.getStatus() == Domain::parked) {
            scooter.setStatus(Domain::reserved);
            repository->updateEntity(scooter);
            return true;
        }
        return false;
    } catch (std::exception &e) {
        return false;
    }
}


bool Ctr::useScooter(const string &id) {
    try {
        Scooter scooter = repository->getById(id);

        if (scooter.getStatus() == Domain::parked) {
            scooter.setStatus(Domain::inUse);
            repository->updateEntity(scooter);
            return true;
        }
        return false;
    } catch (std::exception &e) {
        return false;
    }
}


bool Ctr::hasThreeLetters(const string &id) {
    int count = 0;
    for (char c: id)
        if (std::isalpha(c)) count++;
    return count == 3;
}


vector<Scooter> Ctr::findAvailableScooters() {
    vector<Scooter> availableScooters;

    for (const auto &scooter: repository->getAll())
        if (scooter.getStatus() == Domain::parked)
            availableScooters.push_back(scooter);

    return availableScooters;
}


vector<Scooter> Ctr::searchByLocation(const string &location) {
    vector<Scooter> allScooters = repository->getAll();
    vector<Scooter> filteredScooters;

    for (const auto &scooter: allScooters)
        if (scooter.getLastLocation().find(location) != string::npos)
            filteredScooters.push_back(scooter);

    return filteredScooters;
}

vector<Scooter> Ctr::filterScooterDate(const Date &date) {
    vector<Scooter> allScooters = repository->getAll();
    vector<Scooter> filteredScooters;

    for (const auto &scooter: allScooters) {
        Date scooterDate = scooter.getCommissionDate();

        if (scooterDate.year == date.year && scooterDate.month == date.month && scooterDate.day < date.day ||
            scooterDate.year == date.year && scooterDate.month < date.month || scooterDate.year < date.year)
            filteredScooters.push_back(scooter);
    }

    return filteredScooters;
}

vector<Scooter> Ctr::filterScooterMileage(int mileage) {
    vector<Scooter> allScooters = repository->getAll();
    vector<Scooter> filteredScooters;

    for (const auto &scooter: allScooters)
        if (scooter.getMileage() < mileage)
            filteredScooters.push_back(scooter);

    return filteredScooters;
}


