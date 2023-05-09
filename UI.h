#pragma once

#include "memory"
#include "Controller.h"

using std::shared_ptr, Controller::Ctr, Controller::UserRole;

namespace UserInterface {
    class UI {
    private:
        shared_ptr<Ctr> controller;
        UserRole userRole{};

        // prints the menu options
        void mainMenuUI();

        // gets the input for the menu options, calls the needed methods
        void mainMenu();

    public:
        // constructor
        UI(shared_ptr<Ctr> ctrObj);

        // gets the role form the user and starts the menu
        void startUI();
    };
}