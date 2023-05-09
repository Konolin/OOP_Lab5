#pragma once


#include <memory>
#include "Repository.h"


using std::shared_ptr, Repository::Repo;


namespace Controller {
    enum UserRole {
        customer, admin
    };


    class Ctr {
    private:
        shared_ptr<Repo> repository;

    public:
        // constructor
        Ctr(shared_ptr<Repo> repoObj);
    };
}