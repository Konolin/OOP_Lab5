#pragma once


#include <memory>
#include "Repository.h"
#include "Scooter.h"


using std::shared_ptr, Repository::Repo, Domain::Date, Domain::Status;


namespace Controller {
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
    };
}