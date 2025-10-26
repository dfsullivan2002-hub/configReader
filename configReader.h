#pragma once
#include <map>
#include <string>

class configReader {
    private: 
        std::map<std::string, std::string> settings;

    public:
        bool load(const std::string& filename);
        std::string get(const std::string& key) const;
};