#pragma once

#include "memory"
#include "Controller.h"

using std::shared_ptr, Controller::Ctr;

namespace UserInterface {
    enum UserRole {
        customer, owner
    };

    class UI {
    private:
        shared_ptr<Ctr> controller;
        UserRole userRole{};

        // prints the owner menu options
        static void ownerMenuUI();

        // gets the input for the owner menu options, calls the needed methods
        void ownerMenu();

        // prints the menu options
        static void customerMenuUI();

        // gets the input for the menu options, calls the needed methods
        void customerMenu();

    public:
        // constructor
        UI(shared_ptr<Ctr> ctrObj);

        // gets the role form the user and starts the menu
        void startUI();
    };
}