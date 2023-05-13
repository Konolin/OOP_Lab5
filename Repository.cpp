#include "Repository.h"

using Repository::Repo;

Repo::Repo() {
    generateDummyData();
}

void Repo::add(const Scooter& new_scooter){
    scooterVector.push_back(new_scooter);
}

bool Repo::remove (const std::string& id){
    for (auto itr = scooterVector.begin(); itr < scooterVector.end(); itr++){
        if (itr->getId() == id){
            scooterVector.erase(itr);
            return true;
        }
    }
    return false;
}

std::vector<Scooter> Repo::get_all(){
    return scooterVector;
}

void Repo::generateDummyData() {
    // TODO - add 10 default scooters
}
