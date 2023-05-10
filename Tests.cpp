#include "Tests.h"
#include "Scooter.h"
#include <iostream>
#include <cassert>

using Test::Tests, std::cout, Domain::Scooter, std::exception;

void Tests::Tests::testAll() {
    cout << "Starting all tests...\n\n";

    testDomain();
    testRepository();
    testController();

    cout << "All tests done!\n\n\n";
}

void Tests::testDomain() {
    cout << "Starting domain test...\n";

    Scooter scooter("IDK", "Mercedes", {1, 1, 2023}, 531,
                    "Str. Academician David Prodan nr. 7", Domain::parked);

    // test getters
    assert(scooter.getId() == "IDK");
    assert(scooter.getModel() == "Mercedes");
    Domain::Date commissionDate = scooter.getCommissionDate();
    assert(commissionDate.day == 1);
    assert(commissionDate.month == 1);
    assert(commissionDate.year == 2023);
    assert(scooter.getMileage() == 531);
    assert(scooter.getLastLocation() == "Str. Academician David Prodan nr. 7");
    assert(scooter.getStatus() == Domain::parked);

    // test setters: valid data
    scooter.setId("yad");
    assert(scooter.getId() == "yad");
    scooter.setModel("BMW");
    assert(scooter.getModel() == "BMW");
    scooter.setCommissionDate({2, 2, 2022});
    commissionDate = scooter.getCommissionDate();
    assert(commissionDate.day == 2);
    assert(commissionDate.month == 2);
    assert(commissionDate.year == 2022);
    scooter.setMileage(420);
    assert(scooter.getMileage() == 420);
    scooter.setLastLocation("GROAPAAA");
    assert(scooter.getLastLocation() == "GROAPAAA");
    scooter.setStatus(Domain::inUse);
    assert(scooter.getStatus() == Domain::inUse);

    // test setters: invalid data
    try {
        scooter.setId("1qw");
        assert(false);
    } catch (exception &e) {
        assert(true);
    }
    try {
        scooter.setModel("");
        assert(false);
    } catch (exception &e) {
        assert(true);
    }
    try {
        scooter.setCommissionDate({30, 2, 2023});
        assert(false);
    } catch (exception &e) {
        assert(true);
    }
    try {
        scooter.setMileage(-129);
        assert(false);
    } catch (exception &e) {
        assert(true);
    }
    try {
        scooter.setLastLocation("");
        assert(false);
    } catch (exception &e) {
        assert(true);
    }
    // TODO - check invalid status

    cout << "Domain test done!\n\n";
}

void Tests::testRepository() {
    cout << "Starting repository test...\n";

    cout << "Repository test done!\n\n";
}

void Tests::testController() {
    cout << "Starting controller test...\n";

    cout << "Controller test done!\n\n";
}
