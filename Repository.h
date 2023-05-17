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

        // removes a scooter from the vector, returns false if the entity wasn't found
        void remove(const Scooter &scooter);

        // returns the vector of scooters
        vector<Scooter> getAll();

        // returns the scooter with the corresponding index
        Scooter getById(const string &id);

        // updates the specified entity, returns false if the entity wasn't found
        void updateEntity(const Scooter &updatedEntity);
    };
};
