#include "InMemoryRepository.h"
#include "CSVFileRepository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"


using Repository::InMemoryRepository, Controller::Ctr, UserInterface::UI, Test::Tests, Repository::CSVRepository;


int main() {
//    Tests testsObj;
//    testsObj.testAll();

//    auto repository = std::make_shared<InMemoryRepository>();
    auto repository = std::make_shared<CSVRepository>();
    auto controller = std::make_shared<Ctr>(repository);
    UI ui(controller);

    ui.startUI();

    return 0;
}
