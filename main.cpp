#include "InMemoryRepository.h"
#include "CSVFileRepository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"


using Repository::InMemoryRepository, Controller::Ctr, UserInterface::UI, Test::Tests, Repository::CSVRepository;


int main() {
//    Tests testsObj;
//    testsObj.testAll();

    UI ui;

    ui.startUI();

    return 0;
}
