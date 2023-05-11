#include "UI.h"
#include <utility>
#include <iostream>


using UserInterface::UI, std::cout, std::cin, UserInterface::owner, UserInterface::customer;


UI::UI(shared_ptr<Ctr> ctrObj) : controller(std::move(ctrObj)) {}


void UI::startUI() {
    string userInput;

    cout << "Select a role (owner / customer): ";
    cin >> userInput;

    // TODO - wrong input check
    if (userInput == "admin") {
        userRole = owner;
        ownerMenu();
    } else {
        userRole = customer;
        customerMenu();
    }

}


void UI::ownerMenuUI() {
    cout << "~~~~~ Main menu: ~~~~~\n\n";
    cout << "1. Add scooter\n";
    cout << "2. Delete scooter\n";
    cout << "3. Edit scooter\n";
    cout << "4. Search scooter by location\n";
    cout << "5. Filter scooters scooters\n";
    cout << "6. View all scooters\n";
    cout << "7. Exit\n\n";
    cout << "Choose an option: ";
}


void UI::ownerMenu() {
    string optionStr;
    int optionInt;

    while (true) {
        cout << string(30, '\n');
        ownerMenuUI();
        cin >> optionStr;
        cout << string(30, '\n');

        try {
            optionInt = std::stoi(optionStr);
        } catch (std::exception &e) {
            optionInt = -1;
        }

        switch (optionInt) {
            case 1:
                addScooter();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 2:
                deleteScooter();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 3:
                editScooter();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 4:
                searchByLocation();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 5:
                filterScooters();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 6:
                viewScooters();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 7:
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


void UI::customerMenuUI() {
    cout << "~~~~~ Main menu: ~~~~~\n\n";
    cout << "1. Search scooter by location\n";
    cout << "2. Filter scooters scooters\n";
    cout << "3. Reserve a scooter\n";
    cout << "4. Use a scooter\n";
    cout << "5. Exit\n\n";
    cout << "Choose an option: ";
}


void UI::customerMenu() {
    string optionStr;
    int optionInt;

    while (true) {
        cout << string(30, '\n');
        customerMenuUI();
        cin >> optionStr;
        cout << string(30, '\n');

        try {
            optionInt = std::stoi(optionStr);
        } catch (std::exception &e) {
            optionInt = -1;
        }

        switch (optionInt) {
            case 1:
                searchByLocation();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 2:
                filterScooters();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 3:
                reserveScooter();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 4:
                useScooter();
                cin.ignore();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 5:
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


void UI::addScooter() {
    // TODO - implementation
}


void UI::deleteScooter() {
    // TODO - implementation
}


void UI::editScooter() {
    // TODO - implementation
}


void UI::searchByLocation() {
    // TODO - implementation
}


void UI::filterScooters() {
    // TODO - implementation
}


void UI::viewScooters() {
    // TODO - implementation
}


void UI::reserveScooter() {
    // TODO - implementation
}


void UI::useScooter() {
    // TODO - implementation
}
