#pragma once

#include <memory>

namespace Test {
    class Tests{
    private:
        void testDomain();

        void testRepository();

        void testController();

    public:
        void testAll();
    };
}
