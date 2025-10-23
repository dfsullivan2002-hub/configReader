//Input config file and this script will read it
#include <fstream>
#include <iostream>

int main () {

    std::ifstream inFile;

    inFile.open("settings.ini");

    if (inFile.is_open()) {
        std::string line;
        while(std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } 
    else {
        std::cout << "ERROR! File Not Found." << std::endl;
    }

    return 0;
}