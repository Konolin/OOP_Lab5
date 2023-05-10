#pragma once

#include <memory>

namespace Test {
    class Tests{
    private:
        static void testDomain();

        void testRepository();

        void testController();

    public:
        void testAll();
    };
}
