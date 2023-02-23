#include <stdio.h>
#include "log.h"

class TestClass {
public:
    operator std::string() const {
        return "Bruh I do be cast";
    }
};

enum TestEnum {
    TEST_1,
    TEST_2
};

int main() {
    TestClass test;

    TestEnum testEn = TEST_2;

    rlog::info("Hello World!", 10, 42.0, "lol", test, (int)testEn, 'A');
}