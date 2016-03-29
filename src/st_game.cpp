#include <iostream>
#include <string>
#include <fstream>
#include "st_game.hpp"

// Methods
bool ST_Game::readDeckFromFile(std::ifstream &_file) {
    if (!_file.is_open())
        return false;

    while (!_file.eof()) {
        std::string buffer;
        std::vector <std::string> attr(ST_Card::N_ATTR);
        
        std::getline(_file, attr[ST_Card::ID]);
        std::getline(_file, attr[ST_Card::NAME]);
        std::getline(_file, attr[ST_Card::COMPANY]);
        std::getline(_file, attr[ST_Card::YEAR]);
        std::getline(_file, attr[ST_Card::SPEED]);
        std::getline(_file, attr[ST_Card::RANGE]);
        std::getline(_file, attr[ST_Card::LENGTH]);
        std::getline(_file, attr[ST_Card::WINGSPAN]);
        std::getline(_file, buffer);
        
        std::cout << "N_ATTR = " << ST_Card::N_ATTR << "\n";
        std::cout << "ID = " << attr[ST_Card::ID] << "\n";
        std::cout << "NAME = " << attr[ST_Card::NAME] << "\n";
        std::cout << "COMPANY = " << attr[ST_Card::COMPANY] << "\n";
        std::cout << "YEAR = " << attr[ST_Card::YEAR] << "\n";
        std::cout << "SPEED = " << attr[ST_Card::SPEED] << "\n";
        std::cout << "RANGE = " << attr[ST_Card::RANGE] << "\n";
        std::cout << "LENGTH = " << attr[ST_Card::LENGTH] << "\n";
        std::cout << "WINGSPAN = " << attr[ST_Card::WINGSPAN] << "\n";
        
        this->m_cards.push_back(attr);
    }
    return true;
}
