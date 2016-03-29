#include <iostream>
#include <iomanip>
#include <string>
#include "st_card.hpp"

// Constructors
ST_Card::ST_Card(std::string _id, std::string _name,
    std::string _company, int _year, int _speed,
    int _range, float _length, float _wingspan) {

    this->m_attr[ST_Card::ID]       = _id;
    this->m_attr[ST_Card::NAME]     = _name;
    this->m_attr[ST_Card::COMPANY]  = _company;
    this->m_attr[ST_Card::YEAR]     = _year;
    this->m_attr[ST_Card::SPEED]    = _speed;
    this->m_attr[ST_Card::RANGE]    = _range;
    this->m_attr[ST_Card::LENGTH]   = _length;
    this->m_attr[ST_Card::WINGSPAN] = _wingspan;
}
ST_Card::ST_Card(std::vector<std::string> _attr) {
    for (int i = 0; i < ST_Card::N_ATTR; i++)
        this->m_attr.push_back(_attr[i]);
}

// Getter
std::string ST_Card::getAttribute(ST_Card::attribute_t _at) {
    return this->m_attr[_at];
}

// Methods
void ST_Card::displayCard() {
    std::cout << std::fixed << std::left
              << this->m_attr[ST_Card::ID] << "  | "
              << std::setw(30) << this->m_attr[ST_Card::NAME] << " | "
              << std::setw(28) << this->m_attr[ST_Card::COMPANY]<< " | "
              << std::setw(8) << this->m_attr[ST_Card::YEAR] << " | "
              << std::setw(5) << this->m_attr[ST_Card::SPEED] << " | "
              << std::setw(5) << this->m_attr[ST_Card::RANGE] << " | "
              << std::setw(6) << std::setprecision(2) << this->m_attr[ST_Card::LENGTH] << " | "
              << std::setw(6) << std::setprecision(2) << this->m_attr[ST_Card::WINGSPAN] << std::endl;
}
