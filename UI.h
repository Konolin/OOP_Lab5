#pragma once

#include "memory"
#include "Controller.h"

using std::shared_ptr, Controller::Ctr;

namespace UserInterface {
    class UI {
    private:
        shared_ptr<Ctr> controller;

    public:
        UI(shared_ptr<Ctr> ctrObj);

        void start();
    };
}