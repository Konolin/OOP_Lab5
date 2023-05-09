#include "Repository.h"
#include "Controller.h"
#include "UI.h"


using Repository::Repo, Controller::Ctr, UserInterface::UI;


int main() {
    auto repository = std::make_shared<Repo>();
    auto controller = std::make_shared<Ctr>(repository);
    UI ui(controller);

    ui.startUI();

    return 0;
}
