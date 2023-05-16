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

        // converts a scooterObject to string
        static string scooterToString(const Scooter &scooter);

        // converts the date to string
        static string dateToString(const Date &date);

        // converts the status to string
        static string statusToString(const Status &status);

    public:
        // constructor
        UI(shared_ptr<Ctr> ctrObj);

        // gets the role form the user and starts the menu
        void startUI();

        void printScooter(Scooter scooter);
    };
}