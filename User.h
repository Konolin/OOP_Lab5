#pragma once


#include "Domain.h"
#include "Scooter.h"
#include <string>
#include <vector>


using std::string, Domain::Scooter, std::vector, Domain::User;


namespace Domain {
    class User {
    private:
        string userType{};
        vector<Scooter> reservedScooters{};

    public:
        User(const string &userType);

        User();

        [[nodiscard]] string getType() const;

        void addReservedScooter(const Scooter &reservedScooter);
        
        vector<Scooter> getAllUserReservedScooters();
    };
}
