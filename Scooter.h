#pragma once

#include "Domain.h"
#include <string>

using Domain::Scooter, std::string;

namespace Domain {
    class Scooter {
    private:
        enum Status {
            parked, resereved, inUse, inMaintenance, outOfService
        };

        struct Date {
            int day, month, year;
        };

        string id, model, lastLocation;
        Date commissionDate{};
        int mileage{};
        Status status;

    public:
        Scooter(const string &_id, const string &_model, Date _commissionDate, int _mileage, const string &_lastLocation,
                Status _status);
    };

}