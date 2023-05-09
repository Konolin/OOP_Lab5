#include "UI.h"

#include <utility>
#include "Tests.h"

using UserInterface::UI, Test::Tests;

UI::UI(shared_ptr<Ctr> ctrObj) : controller(std::move(ctrObj)) {}

void UI::start() {
    Tests testsObj;
    testsObj.testAll();
}
