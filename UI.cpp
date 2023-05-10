#include "UI.h"
#include <utility>
#include <iostream>


using UserInterface::UI, std::cout, std::cin, Controller::admin, Controller::customer;


UI::UI(shared_ptr<Ctr> ctrObj) : controller(std::move(ctrObj)) {}


void UI::startUI() {
    string userInput;

    cout << "Select a role (admin / customer): ";
    cin >> userInput;

    // TODO - wrong input check
    if (userInput == "admin") userRole = admin;
    else userRole = customer;

    mainMenu();
}


void UI::mainMenuUI() {
    cout << "~~~~~ Main menu: ~~~~~\n\n";
    cout << "2. Exit\n\n";
    cout << "Choose an option: ";
}


void UI::mainMenu() {
    string optionStr;
    int optionInt;

    while (true) {
        cout << string(30, '\n');
        mainMenuUI();
        cin >> optionStr;
        cout << string(30, '\n');

        try {
            optionInt = std::stoi(optionStr);
        } catch (std::exception &e) {
            optionInt = -1;
        }

        switch (optionInt) {
            case 1:
                // Todo - ceva
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 2:
                break;
            default:
                cin.ignore();
                cout << "Invalid input, try again\n\n";
                cout << "Press any key to continue...";
                cin.get();
                continue;
        }
        break;
    }
}
