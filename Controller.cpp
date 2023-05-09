#include "Controller.h"

#include <utility>

using Controller::Ctr;

Controller::Ctr::Ctr(shared_ptr<Repo> repoObj) : repository(std::move(repoObj)){}
