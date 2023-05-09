#pragma once


#include <string>


using std::string;


namespace Domain {
    enum Status {
        parked, reserved, inUse, inMaintenance, outOfService
    };

    struct Date {
        int day, month, year;
    };


    class Scooter {
    private:
        string id, model, lastLocation;
        Date commissionDate{};
        int mileage{};
        Status status;

    public:
        // constructor
        Scooter(const string &_id, const string &_model, Date _commissionDate, int _mileage,
                const string &_lastLocation, Status _status);
    };

}