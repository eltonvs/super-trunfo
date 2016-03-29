#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "st_game.hpp"

// Methods
bool ST_Game::readDeckFromFile(std::ifstream &_file) {
    if (!_file.is_open())
        return false;


    while (!_file.eof()) {
        std::vector <std::string> attr(ST_Card::N_ATTR);
        std::string buf;
        
        std::getline(_file, attr[ST_Card::ID]);
        std::getline(_file, attr[ST_Card::NAME]);
        std::getline(_file, attr[ST_Card::COMPANY]);
        std::getline(_file, attr[ST_Card::YEAR]);
        std::getline(_file, attr[ST_Card::SPEED]);
        std::getline(_file, attr[ST_Card::RANGE]);
        std::getline(_file, attr[ST_Card::LENGTH]);
        std::getline(_file, attr[ST_Card::WINGSPAN]);
        std::getline(_file, buf);
        
        this->m_cards.push_back(attr);
    }

    return true;
}
