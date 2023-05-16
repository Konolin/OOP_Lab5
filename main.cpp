#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"

//haha
using Repository::Repo, Controller::Ctr, UserInterface::UI, Test::Tests;


int main() {
    Tests testsObj;
    testsObj.testAll();

    auto repository = std::make_shared<Repo>();
    auto controller = std::make_shared<Ctr>(repository);
    UI ui(controller);

    ui.startUI();

    return 0;
}
