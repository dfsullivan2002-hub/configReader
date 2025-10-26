//Input config file and this script will read it
#include "configReader.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

std::string trim(const std::string& str) {
    std::string whitespace = " \t\n";
    size_t pos1 = str.find_first_not_of(whitespace);
    size_t pos2 = str.find_last_not_of(whitespace);
    if (pos1 == std::string::npos) return "";
    return str.substr(pos1, pos2 - pos1 + 1);
}


bool configReader::load(const std::string& filename) {
    
    std::ifstream inFile(filename);

    if (inFile.is_open()) {
        std::string line;
        while(std::getline(inFile, line)) {
            if (line.empty() || line[0] == '#') {
                continue;
            } else {

            int idx = line.find('=');
            std::string key = line.substr(0, idx);
            std::string value = line.substr(idx + 1);
            key = trim(key);
            value = trim(value);
            settings[key] = value;
            }
        }
        inFile.close();
        return true;
    } 
    else {
        std::cout << "ERROR! File Not Found." << std::endl;
        return false;
}
}

std::string configReader::get(const std::string& key) const {
    auto it = settings.find(key);
    if (it != settings.end()) {
         std::cout << it->first << " = " << it->second << std::endl;
        return it->second;
    } else {
        std::string bruh = "Could not find ";
        std::cout << bruh << key << " in settings" << std::endl;
        return bruh;
    }
}

