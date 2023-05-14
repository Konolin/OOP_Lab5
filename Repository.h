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

        void add(const Scooter &new_scooter);

        bool remove(const std::string &id);

        std::vector<Scooter> getAll();

        Scooter getScooter(int scooterIndex);

        void reserveScooter(int scooterIndex);

        void useScooter(int scooterIndex);

        void editMileage(int index, int newMileage);

        void editLocation(int index, const string &newLocation);

        void editStatus(int index, const Status &newStatus);
    };
}
