#include "Controller.h"
#include <utility>


using Controller::Ctr, std::invalid_argument;


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
        throw std::invalid_argument("Commission date day is not valid.");
    if (commissionDate.day == 31 && commissionDate.month % 2 == 0)
        throw std::invalid_argument("Commission date day is not valid.");
    if (commissionDate.day > 28 && commissionDate.month == 2 && commissionDate.year % 4 != 0)
        throw std::invalid_argument("Commission date day is not valid.");
    if (commissionDate.day > 29 && commissionDate.month == 2 && commissionDate.year % 4 == 0)
        throw std::invalid_argument("Commission date day is not valid.");
    if (commissionDate.month < 1 || commissionDate.month > 12)
        throw std::invalid_argument("Commission date month is not valid.");
    if (commissionDate.year > 2023)
        throw std::invalid_argument("Expiration date year is not valid.");

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
    for (char c : id)
        if (std::isalpha(c)) count++;
    return count == 3;
}
