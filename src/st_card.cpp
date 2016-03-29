#include <iostream>
#include <iomanip>
#include <string>
#include "st_card.hpp"

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

void ST_Card::displayCard() {
    std::cout << std::fixed << std::left << this->m_id << "  | "
              << std::setw(30) << this->m_name << " | "
              << std::setw(28) << this->m_company << " | "
              << std::setw(8) << this->m_year << " | "
              << std::setw(5) << this->m_speed << " | "
              << std::setw(5) << this->m_range << " | "
              << std::setw(6) << std::setprecision(2) << this->m_length << " | "
              << std::setw(6) << std::setprecision(2) << this->m_wingspan << std::endl;
}
