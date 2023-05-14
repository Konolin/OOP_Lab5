#pragma once


#include <vector>
#include "Scooter.h"


using std::vector, Domain::Scooter, Domain::Status;


namespace Repository {
    class Repo {
    private:
        vector<Scooter> scooterVector{};

        void generateDummyData();

    public:
        // constructor
        Repo();

        // adds a scooter to the vector
        void add(const Scooter &new_scooter);

        // removes a scooter from the vector, returns the removed scooter
        Scooter remove(int index);

        // returns the vector of scooters
        std::vector<Scooter> getAll();

        // returns the scooter with the corresponding index
        Scooter getScooter(int index);

        // changes the current status of a scooter to reserved
        void reserveScooter(int scooterIndex);

        // changes the current status of a scooter to inUse
        void useScooter(int scooterIndex);

        // changes the mileage of a scooter
        void editMileage(int index, int newMileage);

        // changes the currentLocation of a scooter
        void editLocation(int index, const string &newLocation);

        // changes the status of a scooter
        void editStatus(int index, const Status &newStatus);
    };
}
