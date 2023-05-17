#include "Repository.h"
#include <iostream>


using Repository::Repo, Domain::inUse, Domain::inMaintenance, Domain::reserved, Domain::outOfService, Domain::parked,
        std::invalid_argument;


Repo::Repo() {
    generateDummyData();
}


void Repo::generateDummyData() {
    scooterVector.push_back(Scooter("IDK", "Myria", {1, 1, 2022}, 901, "Centru", inUse));
    scooterVector.push_back(Scooter("THA", "BMW", {2, 12, 2022}, 451, "Sectia 6", reserved));
    scooterVector.push_back(Scooter("SWF", "Tesla", {3, 1, 2021}, 51, "Somes", inMaintenance));
    scooterVector.push_back(Scooter("FXC", "NuStiu", {25, 5, 2022}, 94, "Buna Ziua", outOfService));
    scooterVector.push_back(Scooter("DWS", "Tesla", {1, 8, 2020}, 134, "Bulgaria", parked));
    scooterVector.push_back(Scooter("DAZ", "BMW", {16, 6, 2021}, 501, "Tarnava", outOfService));
    scooterVector.push_back(Scooter("OCA", "Oscar", {11, 7, 2022}, 632, "Sibiu...", parked));
    scooterVector.push_back(Scooter("DWA", "Tesla", {6, 4, 2023}, 421, "Congo", inUse));
    scooterVector.push_back(Scooter("KOF", "Paak", {8, 9, 2022}, 123, "E60", inUse));
    scooterVector.push_back(Scooter("XIQ", "BMW", {25, 11, 2020}, 140, "La cineva acasa", inMaintenance));
}


void Repo::add(const Scooter &new_scooter) {
    scooterVector.push_back(new_scooter);
}


void Repo::remove(const Scooter &scooter) {
    scooterVector.erase(std::remove(scooterVector.begin(), scooterVector.end(), scooter), scooterVector.end());
}


vector<Scooter> Repo::getAll() {
    return scooterVector;
}


Scooter Repo::getById(const string &id) {
    for (auto &scooter: getAll())
        if (scooter.getId() == id)
            return scooter;
    throw std::runtime_error("Scooter was not found");
}


void Repo::updateEntity(const Scooter &updatedEntity) {
    for (auto & scooter : scooterVector)
        if (scooter.getId() == updatedEntity.getId()) {
            scooter = updatedEntity;
            return;
        }
}