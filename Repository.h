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
        Repo();
    };
}