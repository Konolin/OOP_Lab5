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
        shared_ptr<Repo> repository;

        // check if the data given as parameter is valid
        static void dataCheck(const string &id, const string &model, Date commissionDate, int mileage,
                       const string &lastLocation, Status status);

    public:
        // constructor
        Ctr(shared_ptr<Repo> repoObj);
        static bool hasThreeLetters(const string &id);
        void add(const std::string& id, const std::string& model, const Date& commissionDate, int mileage,
                 const std::string& lastLocation, const Status& status);
        bool remove(const std::string& id);
        Scooter& find(const std::string& id);
        void editMileage(const std::string& id, const int& newMileage);
        void editLocation(const std::string& id, const std::string& newLastLocation);
        void editStatus(const std::string& id, Status& newStatus);
        std::vector<Scooter> get_all();
    };
}
