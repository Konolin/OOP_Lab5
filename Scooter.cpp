#include "Scooter.h"
#include "Controller.h"


using Domain::Scooter, Domain::Date, Domain::Status, Controller::Ctr, std::invalid_argument;


Scooter::Scooter(const string &_id, const string &_model, Date _commissionDate, int _mileage,
                 const string &_lastLocation, Status _status) {
    id = _id;
    model = _model;
    commissionDate = _commissionDate;
    mileage = _mileage;
    lastLocation = _lastLocation;
    status = _status;
}


string Scooter::getId() const { return id; }


string Scooter::getModel() const { return model; }


Date Scooter::getCommissionDate() const { return commissionDate; }


int Scooter::getMileage() const { return mileage; }


string Scooter::getLastLocation() const { return lastLocation; }


Status Scooter::getStatus() const { return status; }


void Scooter::setId(const string &newId) {
    if (Ctr::hasThreeLetters(newId) && newId.size() == 3)
        id = newId;
    else throw invalid_argument("The id does not respect the convention (3 letters).");
}


void Scooter::setModel(const string &newModel) {
    if (!newModel.empty()) model = newModel;
    else throw invalid_argument("Model can not be empty.");
}


void Scooter::setCommissionDate(const Date &newCommissionDate) {
    if (newCommissionDate.day < 1 || newCommissionDate.day > 31)
        throw std::invalid_argument("Commission date day is not valid.");
    if (newCommissionDate.day == 31 && newCommissionDate.month % 2 == 0)
        throw std::invalid_argument("Commission date day is not valid.");
    if (newCommissionDate.day > 28 && newCommissionDate.month == 2 && newCommissionDate.year % 4 != 0)
        throw std::invalid_argument("Commission date day is not valid.");
    if (newCommissionDate.day > 29 && newCommissionDate.month == 2 && newCommissionDate.year % 4 == 0)
        throw std::invalid_argument("Commission date day is not valid.");
    if (newCommissionDate.month < 1 || newCommissionDate.month > 12)
        throw std::invalid_argument("Commission date month is not valid.");
    if (newCommissionDate.year > 2023)
        throw std::invalid_argument("Expiration date year is not valid.");

    commissionDate = newCommissionDate;
}


void Scooter::setMileage(int newMileage) {
    if (newMileage > 0) mileage = newMileage;
    else throw invalid_argument("Mileage can not be negative.");
}


void Scooter::setLastLocation(const string &newLastLocation) {
    if (!newLastLocation.empty()) lastLocation = newLastLocation;
    else throw invalid_argument("The last location can not be empty.");
}


void Scooter::setStatus(const Status &newStatus) {
    status = newStatus;
}


bool Scooter::operator==(const Scooter &other) {
    if (id != other.id) return false;
    if (model != other.model) return false;
    if (commissionDate.day != other.commissionDate.day) return false;
    if (commissionDate.month != other.commissionDate.month) return false;
    if (commissionDate.year != other.commissionDate.year) return false;
    if (mileage != other.mileage) return false;
    if (lastLocation != other.lastLocation) return false;
    if (status != other.status) return false;

    return true;
}


bool Scooter::operator!=(const Scooter &other) {
    return !operator==(other);
}


bool Domain::compareDateAscending(const Date &date1, const Date &date2) {
    if (date1.year != date2.year)
        return date1.year < date2.year;

    if (date1.month != date2.month)
        return date1.month < date2.month;

    return date1.day < date2.day;
}
