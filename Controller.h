#pragma once


#include <memory>
#include "Repository.h"
#include "Scooter.h"

using std::shared_ptr, Repository::Repo, Domain::Date, Domain::Status;


namespace Controller {
    enum UserRole {
        customer, admin
    };

    class Ctr {
    private:
        // check if the data given as parameter is valid
        static void dataCheck(const string &id, const string &model, Date commissionDate, int mileage,
                              const string &lastLocation, Status status);

        static bool dateAscending(const Scooter& scooter1, const Scooter& scooter2);

    public:
        shared_ptr<Repo> repository;

        // constructor
        Ctr(shared_ptr<Repo> repoObj);

        static bool hasThreeLetters(const string &id);

        void add(const string &id, const string &model, const Date &commissionDate, int mileage,
                 const string &lastLocation, const Status &status);

        bool remove(const string &id);

        int find(const string &id);

        void editMileage(const string &id, const int &newMileage);

        void editLocation(const string &id, const string &newLastLocation);

        void editStatus(const string &id, Status &newStatus);

        vector<Scooter> getAll();

        vector<Scooter> sortedByCommissionDate();

        bool reserveScooter(const string &id);

        bool useScooter(const string &id);
    };
}
