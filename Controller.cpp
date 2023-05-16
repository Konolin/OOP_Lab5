#include "Controller.h"
#include <utility>


using Controller::Ctr, std::invalid_argument, Domain::parked, Domain::reserved;


Ctr::Ctr(shared_ptr<Repo> repoObj) : repository(std::move(repoObj)) {}


void Ctr::dataCheck(const string &id, const string &model, Date commissionDate, int mileage,
                    const string &lastLocation, Status status) {
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

    // TODO check status cumva idk inca cum
}


bool Ctr::hasThreeLetters(const string &id) {
    int count = 0;
    for (char c: id)
        if (std::isalpha(c)) count++;
    return count == 3;
}


void Ctr::add(const string &id, const string &model, const Date &commissionDate, int mileage,
              const string &lastLocation, const Status &status) {
    Scooter scooter(id, model, commissionDate, mileage, lastLocation, status);
    //dataCheck(id, model, commissionDate, mileage, lastLocation, status);
    repository->add(scooter);
}


bool Ctr::remove(const string &id) {
    try {
        int index = find(id);
        repository->remove(index);
        return true;
    } catch (std::exception &e) {
        return false;
    }
}


int Ctr::find(const string &id) {
    vector<Scooter> scooterVector = repository->getAll();
    for (int i = 0; i < scooterVector.size(); i++) {
        if (scooterVector[i].getId() == id) {
            return i;
        }
    }
    throw std::runtime_error("Scooter not found");
}


void Ctr::editMileage(const string &id, int newMileage) {
    int scooterIndex = find(id);
    repository->editMileage(scooterIndex, newMileage);
}


void Ctr::editLocation(const string &id, const string &newLastLocation) {
    int scooterIndex = find(id);
    repository->editLocation(scooterIndex, newLastLocation);
}


void Ctr::editStatus(const string &id, Status &newStatus) {
    int scooterIndex = find(id);
    repository->editStatus(scooterIndex, newStatus);
}


vector<Scooter> Ctr::sortedByCommissionDate() {
    vector<Scooter> sortedVector = repository->getAll();
    std::sort(sortedVector.begin(), sortedVector.end(), dateAscending);
    return sortedVector;
}


bool Ctr::dateAscending(const Scooter &scooter1, const Scooter &scooter2) {
    if (scooter1.getCommissionDate().year != scooter2.getCommissionDate().year)
        return scooter1.getCommissionDate().year < scooter2.getCommissionDate().year;

    if (scooter1.getCommissionDate().month != scooter2.getCommissionDate().month)
        return scooter1.getCommissionDate().month < scooter2.getCommissionDate().month;

    return scooter1.getCommissionDate().day < scooter2.getCommissionDate().day;
}

bool Ctr::reserveScooter(const string &id) {
    try {
        int scooterIndex = find(id);
        Scooter scooter = repository->getScooter(scooterIndex);

        if (scooter.getStatus() == parked) {
            repository->reserveScooter(scooterIndex);
            return true;
        }
        return false;
    } catch (std::exception &e) {
        return false;
    }
}

bool Controller::Ctr::useScooter(const string &id) {
    try {
        int scooterIndex = find(id);
        Scooter scooter = repository->getScooter(scooterIndex);

        if (scooter.getStatus() == parked) {
            repository->useScooter(scooterIndex);
            return true;
        }
        return false;
    } catch (std::exception &e) {
        return false;
    }
}

vector<Scooter> Ctr::search(const string& input){
    return repository->search(input);
}

vector<Scooter> Ctr::filterScooterDate(Date data){
    return repository->filterScooterDate(data);
}
vector<Scooter> Ctr::filterScooterMileage(int mileage){
    return repository->filterScooterMileage(mileage);
}
