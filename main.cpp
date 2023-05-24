#include "InMemoryRepository.h"
#include "CSVFileRepository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"
#include <iostream>


using Repository::InMemoryRepository, Controller::Ctr, UserInterface::UI, Test::Tests, Repository::CSVRepository, std::make_shared;


int main() {
    Tests testsObj;
    testsObj.testAll();

    string repoType;
    std::cout << "Choose the repository type (inMemo/csv): ";
    std::cin >> repoType;

    shared_ptr<IRepository> repo;
    if (repoType == "csv") {
        repo = make_shared<CSVRepository>();
    } else {
        repo = make_shared<InMemoryRepository>();
    }

   shared_ptr<Ctr> controller = make_shared<Ctr>(repo);
    UI ui(controller);
    ui.startUI();

    return 0;
}

