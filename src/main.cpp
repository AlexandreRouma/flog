#include <stdio.h>
#include <string>
#include "utils/event.h"

void test1(std::string str, int test) {
    printf("Test1: '%s', %d\n", str.c_str(), test);
}

void test2(std::string str, int test) {
    printf("Test2: '%s', %d\n", str.c_str(), test);
}

class TestClass {
public:
    TestClass(std::string str) {
        inst = str;
    }

    void test(std::string str, int test) {
        printf("[%s]: '%s', %d\n", inst.c_str(), str.c_str(), test);
    };

private:
    std::string inst;
};

int main() {
    TestClass tc("ClassThing");

    Event<std::string, int> onBruh;

    onBruh.bind(test1);
    onBruh.bind(test2);
    onBruh.bind(&TestClass::test, &tc);


    return 0;
}