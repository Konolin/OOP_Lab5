#include "UI.h"
#include "Tests.h"
#include <utility>
#include <iostream>


using UserInterface::UI, Test::Tests, std::cout, std::cin, Controller::admin, Controller::customer;


UI::UI(shared_ptr<Ctr> ctrObj) : controller(std::move(ctrObj)) {}


void UI::startUI() {
    string userInput;

    cout << "Select a role (admin / customer): ";
    cin >> userInput;

    if (userInput == "admin") userRole = admin;
    else userRole = customer;

    mainMenu();
}


void UI::mainMenuUI() {
    cout << "1. ";
}


void UI::mainMenu() {
    while (true) {

    }
    Tests testsObj;
    testsObj.testAll();
}
