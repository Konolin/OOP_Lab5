#pragma once


#include "memory"
#include "Controller.h"


using std::shared_ptr, Controller::Ctr;


namespace UserInterface {
    class UI {
    private:
        shared_ptr<Ctr> controller;

        // prints the owner menu options
        static void ownerMenuUI();

        // gets the input for the owner menu options, calls the needed methods
        void ownerMenu();

        // prints the menu options
        static void customerMenuUI();

        // gets the input for the menu options, calls the needed methods
        void customerMenu();

        // gets the information for a new scooter
        void addScooter();

        // gets the information to delete a scooter
        void deleteScooter();

        // gets the new information to edit a scooter
        void editScooter();

        // gets the location and prints the filtered scooters
        void searchByLocation();

        // prints the filtered scooters (by abe/ mileage)
        void filterScooters();

        // prints scooters by age in ascending order
        void viewScooters();

        // gets the information of a scooter that the user wants to reserve
        void reserveScooter();

        // gets the information of a scooter that the user wants to use
        void useScooter();

        // prints the vector of scooters
        static void printScooterVector(const vector<Scooter> &scooterVector);

    public:
        // constructor
        UI(shared_ptr<Ctr> ctrObj);

        // gets the role form the user and starts the menu
        void startUI();
    };
}