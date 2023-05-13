#pragma once


#include <vector>
#include "Scooter.h"


using std::vector, Domain::Scooter;


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
    };
}
