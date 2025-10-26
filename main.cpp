#include <iostream>
#include "configReader.h"

int main() {
    configReader config;

    if (config.load("settings.ini")) {
        std::cout << "File loaded successfully..." << std::endl;
    }

    config.get("username");
    return 0;
}