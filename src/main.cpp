#include <stdio.h>
#include <string>

#include "flog.h"

int main() {
    flog::debug("We do a little debugging");
    flog::info("Some useless information");
    flog::warn("This is a warning");
    flog::error("Something's fucked");

    return 0;
}