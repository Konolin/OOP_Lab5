#include "UI.h"
#include "User.h"
#include <utility>
#include <iostream>


using UserInterface::UI, std::cout, std::cin, std::to_string, Domain::User, Domain::inUse, Domain::inMaintenance,
        Domain::parked, Domain::reserved, Domain::outOfService, std::exception, Domain::User;


UI::UI(shared_ptr<Ctr> ctrObj) : controller(std::move(ctrObj)) {}


void UI::startUI() {
    cout << string(30, '\n');

    string userInput;

    cout << "Select a repository type (csv / memory): ";
    cin >> userInput;

    cout << "Select a role (owner / customer): ";
    cin >> userInput;

    user = User(userInput);

    if (user.getType() == "owner")
        ownerMenu();
    else if (user.getType() == "customer")
        customerMenu();
    else {
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
    cout << "5. Filter scooters by age or mileage\n";
    cout << "6. View all scooters\n";
    cout << "7. Return to user choice\n";
    cout << "8. Exit\n\n";
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
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 2:
                deleteScooter();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 3:
                editScooter();
                cout << "Press any key to continue...";
                cin.get();
                continue;
            case 4:
                searchByLocation();
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
                startUI();
            case 8:
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
    cout << "5. Return to user choice\n";
    cout << "6. Exit\n\n";
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
                startUI();
            case 6:
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

    if(controller->add(id, model, {year, month, day}, mileage, lastLocation, status))
        cout << "\nThe scooter has been added to the repository!\n\n";
    else
        cout << "\nFailed to add the scooter!\n\n";
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
    cout << "~~~~~  Editing a scooter  ~~~~~\n\n";

    string id, newMileage, user_input, choice;

    cout << "Type the id of the scooter:";
    cin.ignore();
    getline(cin, id);
    Scooter scooter = controller->repository->getById(id);

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

    if (choice == "Mileage"){
        cout << "Enter the new mileage:";
        getline(cin, user_input);
        if (controller->edit(id, "mileage", user_input))
            cout << "Mileage updated successfully\n!";
        else
            cout << "Failed to update the mileage!\n";
    }else if (choice == "Last Location"){
        cout << "Enter the last location:";
        getline(cin, user_input);
        if (controller->edit(id, "lastLocation", user_input))
            cout << "Last location updated successfully!\n";
        else
            cout << "Failed to update the last location!\n";
    }else if (choice == "Status"){
        cout << "Enter the new status:";
        getline(cin, user_input);
        if (controller->edit(id, "status", user_input))
            cout << "Status updated successfully!\n";
        else
            cout << "Failed to update the status!\n";
    }
}


void UI::searchByLocation() {
    string location;
    cout << "~~~~ Search by location ~~~~\n\n";
    cout << "Enter the location you want to search scooters in: ";
    cin.ignore();
    getline(cin, location);
    cout << '\n';

    vector<Scooter> filteredVector = controller->searchByLocation(location);
    if (!filteredVector.empty())
        printScooterVector(filteredVector);
    else
        cout << "No scooter with specified location was found.\n";
}


void UI::filterScooters() {
    int input, mileage;
    vector<Scooter> filteredVector;
    Date commissionDate{};

    cin.ignore();
    cout << "~~~~ Filter scooters ~~~~\n";
    cout << "Would you like to filter scooters by: \n\n1. Commission date\n2. Mileage\n\n";
    cout << "Choose an option: ";
    cin >> input;

    switch (input) {
        case 1:
            cout << "\nFilter all the scooters with the commission date before: \n\tDay: ";
            cin >> commissionDate.day;
            cout << "\tMonth: ";
            cin >> commissionDate.month;
            cout << "\tYear: ";
            cin >> commissionDate.year;
            filteredVector = controller->filterScooterDate(commissionDate);
            break;
        case 2:
            cout << "\nFilter all the scooters with the mileage under: ";
            cin >> mileage;
            filteredVector = controller->filterScooterMileage(mileage);
            break;
        default:
            cout << "Invalid input, try again...";
            cin.get();
            filterScooters();
    }

    printScooterVector(filteredVector);
}


void UI::viewScooters() {
    cout << string(30, '\n');
    cout << "~~~~ View scooters sorted by commission date ~~~~\n\n";

    vector<Scooter> sortedScooters = controller->sortedByCommissionDate();
    printScooterVector(sortedScooters);
}


void UI::reserveScooter() {
    cout << "~~~~ Available scooters ~~~~\n\n";
    vector<Scooter> availableScooters = controller->findAvailableScooters();

    if (!availableScooters.empty()) {
        printScooterVector(availableScooters);

        cout << "\n~~~~ Reserve a scooter ~~~~\n\n";

        string id;
        cin.ignore();
        cout << "Enter the id of the scooter you want to reserve: ";
        cin >> id;

        if (controller->reserveScooter(id))
            cout << "\nScooter successfully reserved\n\n";
        else
            cout << "\nScooter could not be reserved.\n\n";
    } else {
        cout << "No scooters are available at this moment.\n\n";
    }
}


void UI::useScooter() {
    cout << "~~~~ Available scooters ~~~~\n\n";
    vector<Scooter> availableScooters = controller->findAvailableScooters();

    if (!availableScooters.empty()) {
        printScooterVector(availableScooters);

        cout << "\n~~~~ Use a scooter ~~~~\n\n";
        string id;
        cin.ignore();
        cout << "Enter the id of the scooter you want to use: ";
        cin >> id;

        if (controller->useScooter(id))
            cout << "\nScooter is now successfully in use.\n\n";
        else
            cout << "\nScooter can not be used right now.\n\n";
    } else {
        cout << "No scooters are available at this moment.\n\n";
    }
}


void UI::printScooterVector(const vector<Scooter> &scooterVector) {
    cout << '\n';
    int index = 1;
    for (const auto &scooter: scooterVector) {
        cout << index << ". " << scooter.scooterToString() << '\n';
        index++;
    }
    cout << '\n';
}

