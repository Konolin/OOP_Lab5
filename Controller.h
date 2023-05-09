#pragma once

#include <memory>
#include "Repository.h"

using std::shared_ptr, Repository::Repo;

namespace Controller {
    class Ctr {
    private:
        shared_ptr<Repo> repository;

    public:
        Ctr(shared_ptr<Repo> repoObj);
    };
}