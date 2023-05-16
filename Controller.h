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

        static bool dateAscending(const Scooter &scooter1, const Scooter &scooter2);

    public:
        shared_ptr<Repo> repository;

        // constructor
        Ctr(shared_ptr<Repo> repoObj);

        // checks if a string contains 3 letters
        static bool hasThreeLetters(const string &id);

        // creates a new object and adds it to the repository
        void add(const string &id, const string &model, const Date &commissionDate, int mileage,
                 const string &lastLocation, const Status &status);

        // removes a scooter
        bool remove(const string &id);

        // finds a scooters index in the vector
        int find(const string &id);

        // edits the mileage of a scooter
        void editMileage(const string &id, int newMileage);

        // edits the location of a scooter
        void editLocation(const string &id, const string &newLastLocation);

        // edits the status of a scooter
        void editStatus(const string &id, Status &newStatus);

        // sorts the vector by the commission date in ascending order
        vector<Scooter> sortedByCommissionDate();

        // changes the status of a scooter to reserved
        bool reserveScooter(const string &id);

        // changes the status of a scooter to inUse
        bool useScooter(const string &id);

        // returns a vector of scooters that contain the specified string in their location
        vector<Scooter> search(const string &input);

        // returns a vector of scooters with the commissionDate older than specified date
        vector<Scooter> filterScooterDate(Date data);

        // returns a vector of scooters that have a lower mileage than the one specified
        vector<Scooter> filterScooterMileage(int mileage);
    };
}
