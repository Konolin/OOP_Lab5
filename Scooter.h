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

        string getId() const;

        string getModel() const;

        Date getCommissionDate() const;

        int getMileage() const;

        string getLastLocation() const;

        Status getStatus() const;

        void setId(const string& newId);

        void setModel(const string& newModel);

        void setCommissionDate(const Date &newCommissionDate);

        void setMileage(int newMileage);

        void setLastLocation(const string &newLastLocation);

        void setStatus(const Status &newStatus);

        // overload for the == operator
        bool operator==(const Scooter &other);

        // overload for the != operator
        bool operator!=(const Scooter &other);
    };
}