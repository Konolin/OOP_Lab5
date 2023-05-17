//#include "Tests.h"
//#include "Scooter.h"
//#include "Repository.h"
//#include <iostream>
//#include <cassert>
//
//using Test::Tests, std::cout, Domain::Scooter, std::exception, Repository::Repo;
//
//void Tests::Tests::testAll() {
//    cout << "Starting all tests...\n\n";
//
//    testDomain();
//    testRepository();
//    testController();
//
//    cout << "All tests done!\n\n\n";
//}
//
//void Tests::testDomain() {
//    cout << "Starting domain test...\n";
//
//    Scooter scooter("IDK", "Mercedes", {1, 1, 2023}, 531,
//                    "Str. Academician David Prodan nr. 7", Domain::parked);
//
//    // test getters
//    assert(scooter.getId() == "IDK");
//    assert(scooter.getModel() == "Mercedes");
//    Domain::Date commissionDate = scooter.getCommissionDate();
//    assert(commissionDate.day == 1);
//    assert(commissionDate.month == 1);
//    assert(commissionDate.year == 2023);
//    assert(scooter.getMileage() == 531);
//    assert(scooter.getLastLocation() == "Str. Academician David Prodan nr. 7");
//    assert(scooter.getStatus() == Domain::parked);
//
//    // test setters: valid data
//    scooter.setId("yad");
//    assert(scooter.getId() == "yad");
//    scooter.setModel("BMW");
//    assert(scooter.getModel() == "BMW");
//    scooter.setCommissionDate({2, 2, 2022});
//    commissionDate = scooter.getCommissionDate();
//    assert(commissionDate.day == 2);
//    assert(commissionDate.month == 2);
//    assert(commissionDate.year == 2022);
//    scooter.setMileage(420);
//    assert(scooter.getMileage() == 420);
//    scooter.setLastLocation("GROAPAAA");
//    assert(scooter.getLastLocation() == "GROAPAAA");
//    scooter.setStatus(Domain::inUse);
//    assert(scooter.getStatus() == Domain::inUse);
//
//    // test setters: invalid data
//    try {
//        scooter.setId("1qw");
//        assert(false);
//    } catch (exception &e) {
//        assert(true);
//    }
//    try {
//        scooter.setModel("");
//        assert(false);
//    } catch (exception &e) {
//        assert(true);
//    }
//    try {
//        scooter.setCommissionDate({30, 2, 2023});
//        assert(false);
//    } catch (exception &e) {
//        assert(true);
//    }
//    try {
//        scooter.setMileage(-129);
//        assert(false);
//    } catch (exception &e) {
//        assert(true);
//    }
//    try {
//        scooter.setLastLocation("");
//        assert(false);
//    } catch (exception &e) {
//        assert(true);
//    }
//
//    cout << "Domain test done!\n\n";
//}
//
//void Tests::testRepository() {
//    cout << "Starting repository test...\n";
//
//    // check the original size of the vector from the array
//    Repo repository;
//    assert(repository.getAll().size() == 11);
//
//    // check the add method
//    Scooter scooter("IFW", "MyriaMM", {1, 1, 2022}, 931, "Centru", Domain::inUse);
//    repository.add(scooter);
//    assert(repository.getAll().size() == 12);
//    assert(repository.getAll().back() == scooter);
//
//    // check the getById method
//    assert(repository.getById(repository.getAll().size() - 1) == scooter);
//
//    // check the remove method
//    assert(repository.remove(repository.getAll().size() - 1) == scooter);
//    assert(repository.getAll().size() == 11);
//
//    // check the reserveScooter method
//    repository.add(Scooter("IFW", "MyriaMM", {1, 1, 2022}, 931, "Centru", Domain::parked));
//    repository.reserveScooter(repository.getAll().size() - 1);
//    scooter = repository.getById(repository.getAll().size() - 1);
//    assert(scooter.getStatus() == Domain::reserved);
//
//    // check the useScooter method
//    repository.useScooter(repository.getAll().size() - 1);
//    scooter = repository.getById(repository.getAll().size() - 1);
//    assert(scooter.getStatus() == Domain::inUse);
//
//    // check editMileage method
//    repository.editMileage(repository.getAll().size() - 1, 420);
//    scooter = repository.getById(repository.getAll().size() - 1);
//    assert(scooter.getMileage() == 420);
//
//    // check editLocation method
//    repository.editLocation(repository.getAll().size() - 1, "Str. Horea nr. 106");
//    scooter = repository.getById(repository.getAll().size() - 1);
//    assert(scooter.getLastLocation() == "Str. Horea nr. 106");
//
//    // check the editStatus method
//    repository.editStatus(repository.getAll().size() - 1, Domain::inMaintenance);
//    scooter = repository.getById(repository.getAll().size() - 1);
//    assert(scooter.getStatus() == Domain::inMaintenance);
//
//    // TODO - CATA SA VERIFICI :) PUP DULCE
//    // check the search by location method
//    // no ideea daca am facut bine dar ma plictiseam
//    vector<Scooter> scooters;
//    scooters = repository.search("Sibiu");
//    assert(scooters[0].getId()=="OCA");
//
//    // check the filter by date method
//    //again chiar no idea daca e bn si nu am cum sa rulez sa verific pentru ca laptopul meu nu vrea sa ma lase
//    scooters = repository.filterScooterDate({1, 1, 2021});
//    assert(scooters.size()==2);
//
//
//    cout << "Repository test done!\n\n";
//}
//
//void Tests::testController() {
//    cout << "Starting controller test...\n";
//
//    cout << "Controller test done!\n\n";
//}
