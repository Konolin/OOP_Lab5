#pragma once


#include "Domain.h"
#include "Scooter.h"
#include <string>
#include <vector>


using std::string, Domain::Scooter, std::vector;


namespace Domain {
    class User {
    private:
        string userType{};
        vector<Scooter> reservedScooters{};

    public:
        User(const string &userType);

        [[nodiscard]] string getType() const;

        void addReservedScooter(const Scooter &reservedScooter);
    };
}