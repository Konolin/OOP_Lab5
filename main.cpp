#include "InMemoryRepository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"


using Repository::InMemoryRepository, Controller::Ctr, UserInterface::UI, Test::Tests;


int main() {
//    Tests testsObj;
//    testsObj.testAll();

    auto repository = std::make_shared<InMemoryRepository>();
    auto controller = std::make_shared<Ctr>(repository);
    UI ui(controller);

    ui.startUI();

    return 0;
}
