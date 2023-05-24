#include "InMemoryRepository.h"
#include "CSVFileRepository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"
#include <iostream>


using Repository::InMemoryRepository, Controller::Ctr, UserInterface::UI, Test::Tests, Repository::CSVRepository;


int main() {
    Tests testsObj;
    testsObj.testAll();

    string repoType;
    std::cout << "Choose the repository type(inMemo/ csv): ";
    std::cin >> repoType;

    if (repoType == "csv") {
        shared_ptr<IRepository> repo = std::make_shared<CSVRepository>();
        shared_ptr<Ctr> controller = std::make_shared<Ctr>(repo);
        UI ui(controller);
        ui.startUI();
    } else {
        shared_ptr<IRepository> repo = std::make_shared<InMemoryRepository>();
        shared_ptr<Ctr> controller = std::make_shared<Ctr>(repo);
        UI ui(controller);
        ui.startUI();
    }

    return 0;
}
