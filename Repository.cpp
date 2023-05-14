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
    scooterVector.push_back(Scooter("SWF", "Tesla", {3, 1, 2021}, 51, "Somes", inUse));
    scooterVector.push_back(Scooter("FXC", "NuStiu", {25, 5, 2022}, 94, "Buna Ziua", outOfService));
    scooterVector.push_back(Scooter("DWS", "Tesla", {1, 8, 2020}, 134, "Bulgaria", parked));
    scooterVector.push_back(Scooter("DAZ", "BMW", {16, 6, 2021}, 501, "Tarnava", outOfService));
    scooterVector.push_back(Scooter("OCA", "Oscar", {11, 7, 2022}, 632, "Sibiu...", parked));
    scooterVector.push_back(Scooter("DWA", "Tesla", {6, 4, 2023}, 421, "Congo", inUse));
    scooterVector.push_back(Scooter("KOF", "Paak", {8, 9, 2022}, 123, "E60", inUse));
    scooterVector.push_back(Scooter("XIQ", "BMW", {25, 11, 2020}, 140, "La cineva acasa", inMaintenance));
    scooterVector.push_back(Scooter("IWN", "Tesla", {11, 12, 2021}, 941, "uhaaaaa", reserved));

}


void Repo::add(const Scooter &new_scooter) {
    scooterVector.push_back(new_scooter);
}


Scooter Repo::remove(int index) {
    Scooter removedScooter = scooterVector[index];
    scooterVector.erase(scooterVector.begin() + index);
    return removedScooter;
}


vector<Scooter> Repo::getAll() {
    return scooterVector;
}


Scooter Repo::getScooter(int index) {
    if (index > 0 && index < scooterVector.size())
        return scooterVector[index];
    else throw invalid_argument("Invalid index.");
}


void Repo::reserveScooter(int scooterIndex) {
    scooterVector[scooterIndex].setStatus(reserved);
}


void Repo::useScooter(int scooterIndex) {
    scooterVector[scooterIndex].setStatus(inUse);
}


void Repo::editMileage(int index, int newMileage) {
    scooterVector[index].setMileage(newMileage);
}


void Repo::editLocation(int index, const string &newLocation) {
    scooterVector[index].setLastLocation(newLocation);
}


void Repo::editStatus(int index, const Status &newStatus) {
    scooterVector[index].setStatus(newStatus);
}

