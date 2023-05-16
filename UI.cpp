#include "UI.h"
#include <utility>
#include <iostream>


using UserInterface::UI, std::cout, std::cin, UserInterface::owner, UserInterface::customer, std::to_string,
        Domain::inUse, Domain::inMaintenance, Domain::parked, Domain::reserved, Domain::outOfService, std::exception;


UI::UI(shared_ptr<Ctr> ctrObj) : controller(std::move(ctrObj)) {}

// TODO - la unele optiuni trebuie dat enter de mai multe ori pentru a iesi din meniu

void UI::startUI() {
    cout << string(30, '\n');

    string userInput;

    cout << "Select a role (owner / customer): ";
    cin >> userInput;

    if (userInput == "owner") {
        userRole = owner;
        ownerMenu();
    } else if (userInput == "customer"){
        userRole = customer;
        customerMenu();
    } else {
        cin.ignore();
        cout << "Invalid input, try again.\n";
        cout << "Press any key to continue...";
        cin.get();
        startUI();
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
            optionInt = stoi(optionStr);
        } catch (exception &e) {
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
            optionInt = stoi(optionStr);
        } catch (exception &e) {
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
    cout << "~~~~~  Adding a scooter  ~~~~~\n\n";

    string id, model, lastLocation, user_input;
    int year, month, day, mileage;
    Status status;

    cin.ignore();

    cout << "Type the ID of the new scooter (3 letters):";
    getline(cin, id);

    cout << "Type the model of the new scooter:";
    getline(cin, model);

    cout << "Type the commission date of the new scooter:\n";
    cout << "Year:";
    getline(cin, user_input);
    year = stoi(user_input);
    cout << "Month:";
    getline(cin, user_input);
    month = stoi(user_input);
    cout << "Day:";
    getline(cin, user_input);
    day = stoi(user_input);

    cout << "Type the mileage of the new scooter:";
    getline(cin, user_input);
    mileage = stoi(user_input);

    cout << "Type the last location of the new scooter:";
    getline(cin, lastLocation);

    cout << "Type the status of the new scooter (parked, reserved, in use, in maintenance, out of service):";
    getline(cin, user_input);

    if (user_input == "parked") {
        status = parked;
    } else if (user_input == "reserved") {
        status = reserved;
    } else if (user_input == "in use") {
        status = inUse;
    } else if (user_input == "in maintenance") {
        status = inMaintenance;
    } else if (user_input == "out of service") {
        status = outOfService;
    }

    controller->add(id, model, {year, month, day}, mileage, lastLocation, status);

    cout << "\nThe scooter has been added to the repository!\n\n";
}


void UI::deleteScooter() {
    cout << "~~~~~  Removing a scooter  ~~~~~\n\n";

    string id;
    cout << "Type the id of the scooter to be removed:";
    cin.ignore();
    getline(cin, id);

    if (controller->remove(id))
        cout << "\nThe scooter has been removed!\n";
    else
        cout << "\nNo scooter id matched your input!\n";
}


void UI::editScooter() {
    // TODO - la location si mileage nu se salveaza primul caracter (ex ptr 123 -> 23)
    cout << "~~~~~  Editing a scooter  ~~~~~\n\n";

    string id, newLastLocation, user_input, choice;
    int newMileage;
    Status newStatus;

    cout << "Type the id of the scooter:";
    cin.ignore();
    getline(cin, id);
    Scooter scooter = controller->repository->getScooter(controller->find(id));

    cout << "Here is the selected scooter:\n\n";
    cout << "Scooter ID: " << id << '\n';
    cout << "Model: " << scooter.getModel() << '\n';
    cout << "Commission Date: " << scooter.getCommissionDate().year << "/" <<
         scooter.getCommissionDate().month << "/" << scooter.getCommissionDate().day << '\n';
    cout << "Mileage: " << scooter.getMileage() << '\n';
    cout << "Last Location: " << scooter.getLastLocation() << '\n';
    cout << "Status: " << statusToString(scooter.getStatus()) << "\n\n";

    cout << "What would you like to edit to this scooter? (Mileage / Last Location / Status):";
    getline(cin, choice);


    // TODO - switch
    if (choice == "Mileage") {
        cout << "Type the new mileage of the scooter:";
        cin.ignore();
        getline(cin, user_input);   //ar trebui aici un data validation, actually la toate
        newMileage = stoi(user_input);
        controller->editMileage(id, newMileage);
    }
    if (choice == "Last Location") {
        cout << "Type the new last location of the scooter:";
        cin.ignore();
        getline(cin, newLastLocation);
        controller->editLocation(id, newLastLocation);
    }
    if (choice == "Status") {
        // TODO - de ce is 2 input-uri?
        cout << "Type the new status of the scooter:";
        cin.ignore();
        getline(cin, user_input);
        cout << "Type the new status of the new scooter (parked, reserved, in use, in maintenance, out of service):";
        getline(cin, user_input);

        if (user_input == "parked") {
            newStatus = parked;
        } else if (user_input == "reserved") {
            newStatus = reserved;
        } else if (user_input == "in use") {
            newStatus = inUse;
        } else if (user_input == "in maintenance") {
            newStatus = inMaintenance;
        } else if (user_input == "out of service") {
            newStatus = outOfService;
        }
        controller->editStatus(id, newStatus);
    }
}


void UI::searchByLocation() {
    // TODO - implementation
}


void UI::filterScooters() {
    // TODO - implementation
}


void UI::viewScooters() {
    cout << string(30, '\n');
    cout << "~~~~ View scooters sorted by commission date ~~~~\n\n";

    vector<Scooter> sortedScooters = controller->sortedByCommissionDate();

    for (int index = 0; index < sortedScooters.size(); index++) {
        cout << index + 1 << ". " << scooterToString(sortedScooters[index]) << "\n";
    }

    cout << '\n';
}


void UI::reserveScooter() {
    cout << "~~~~ Reserve a scooter ~~~~\n\n";

    string id;
    cin.ignore();
    cout << "Enter the id of the scooter you want to reserve: ";
    cin >> id;

    if (controller->reserveScooter(id))
        cout << "Scooter successfully reserved\n\n";
    else
        cout << "Scooter could not be reserved.\n\n";
}


void UI::useScooter() {
    cout << "~~~~ Use a scooter ~~~~\n\n";

    string id;
    cin.ignore();
    cout << "Enter the id of the scooter you want to use: ";
    cin >> id;

    if (controller->useScooter(id))
        cout << "Scooter is now successfully in use.\n\n";
    else
        cout << "Scooter can not be used right now.\n\n";
}


string UI::scooterToString(const Scooter &scooter) {
    string id = scooter.getId();
    string model = scooter.getModel();
    string commissionDate = dateToString(scooter.getCommissionDate());
    string mileage = to_string(scooter.getMileage());
    string lastLocation = scooter.getLastLocation();
    string status = statusToString(scooter.getStatus());

    string scooterString =
            id + ", " + model + ", " + commissionDate + ", " + mileage + ", " + lastLocation + ", " + status;

    return scooterString;
}


string UI::dateToString(const Date &date) {
    return '{' + to_string(date.day) + ':' + to_string(date.month) + ':' + to_string(date.year) + '}';
}


string UI::statusToString(const Status &status) {
    switch (status) {
        case parked:
            return "parked";
        case reserved:
            return "reserved";
        case inUse:
            return "in use";
        case inMaintenance:
            return "in maintenance";
        case outOfService:
            return "out of service";
        default:
            return "unknown";
    }
}
