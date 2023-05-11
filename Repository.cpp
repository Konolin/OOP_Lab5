#include "Repository.h"


using Repository::Repo;


Repo::Repo() {
    generateDummyData();
}


void Repo::generateDummyData() {
    // TODO - add 10 default scooters
}


bool Repo::addScooter(const Scooter& newScooter) {
    // TODO - implementation
}


bool Repo::deleteScooter(const Scooter &deletedScooter) {
    // TODO - implementation
}


bool Repo::editScooter(Scooter &deletedScooter) {
    // TODO - implementation
}


vector<Scooter> Repo::getAll() { return scooterVector; }
