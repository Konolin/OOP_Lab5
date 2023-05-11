#pragma once


#include <vector>
#include "Scooter.h"


using std::vector, Domain::Scooter;


namespace Repository {
    class Repo {
    private:
        vector<Scooter> scooterVector{};

        // adds 10 items to the vector
        void generateDummyData();

    public:
        // constructor
        Repo();

        // adds the new scooter in the vector, returns the success of the operation
        bool addScooter(const Scooter& newScooter);

        // delete scooter from the vector, returns the success of the operation
        bool deleteScooter(const Scooter& deletedScooter);

        // edits the scooter, returns the success of the operation
        bool editScooter(Scooter& deletedScooter);

        // returns the scooter vector
        vector<Scooter> getAll();
    };
}