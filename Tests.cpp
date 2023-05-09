#include "Tests.h"
#include <iostream>

using Test::Tests, std::cout;

void Tests::Tests::testAll() {
    cout << "Starting all tests...\n\n";

    testDomain();
    testRepository();
    testController();

    cout << "All tests done!\n";
}

void Tests::Tests::testDomain() {
    cout << "Starting domain test...\n";

    cout << "Domain test done!\n\n";
}

void Tests::Tests::testRepository() {
    cout << "Starting repository test...\n";

    cout << "Repository test done!\n\n";
}

void Tests::Tests::testController() {
    cout << "Starting controller test...\n";

    cout << "Controller test done!\n\n";
}
