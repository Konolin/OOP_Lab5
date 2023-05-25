#include "User.h"


using Domain::User;


User::User(const string &_userType) {
    userType = _userType;
}

void User::addReservedScooter(const Scooter &reservedScooter) {
    reservedScooters.push_back(reservedScooter);
}

vector<Scooter> User::getAllUserReservedScooters() {
    return reservedScooters;
}

string User::getType() const { return userType; }

User::User() { userType = "NONE"; }
