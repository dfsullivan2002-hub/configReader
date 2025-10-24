//Input config file and this script will read it
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main () {

    std::ifstream inFile;
    std::map <std::string, std::string> settings;

    inFile.open("settings.ini");

    if (inFile.is_open()) {
        std::string line;
        while(std::getline(inFile, line)) {
            if (line.empty() || line[0] == '#') {
                continue;
            } else {

            int idx = line.find('=');
            std::string key = line.substr(0, idx);
            std::string value = line.substr(idx + 1);
            settings[key] = value;
            std::cout << key << value << std::endl;

            }
        }
        inFile.close();
    } 
    else {
        std::cout << "ERROR! File Not Found." << std::endl;
    }
    return 0;
}