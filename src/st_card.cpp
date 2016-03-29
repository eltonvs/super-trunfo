#include <iostream>
#include <iomanip>
#include <string>
#include "st_card.hpp"

ST_Card::ST_Card(std::string _id, std::string _name,
    std::string _company, int _year, int _speed,
    int _range, float _length, float _wingspan) {

    this->m_id       = _id;
    this->m_name     = _name;
    this->m_company  = _company;
    this->m_year     = _year;
    this->m_speed    = _speed;
    this->m_range    = _range;
    this->m_length   = _length;
    this->m_wingspan = _wingspan;
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
