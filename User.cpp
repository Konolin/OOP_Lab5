#include "User.h"


using Domain::User;


User::User(const string &_userType) {
    userType = _userType;
}

void User::addReservedScooter(const Scooter &reservedScooter) {
    reservedScooters.push_back(reservedScooter);
}

string User::getType() const { return userType; }

User::User() { userType = "NONE"; }
