#include <iostream>
#include <iomanip>
#include "st_card.hpp"

// Constructors
ST_Card::ST_Card(const std::string &_id, const std::string &_name,
    const std::string &_company, const std::string &_year, const std::string &_speed,
    const std::string &_range, const std::string &_length, const std::string &_wingspan) {

    this->m_attr.resize(ST_Card::N_ATTR);

    this->m_attr[ST_Card::ID]       = _id;
    this->m_attr[ST_Card::NAME]     = _name;
    this->m_attr[ST_Card::COMPANY]  = _company;
    this->m_attr[ST_Card::YEAR]     = _year;
    this->m_attr[ST_Card::SPEED]    = _speed;
    this->m_attr[ST_Card::RANGE]    = _range;
    this->m_attr[ST_Card::LENGTH]   = _length;
    this->m_attr[ST_Card::WINGSPAN] = _wingspan;
}

ST_Card::ST_Card(const std::vector<std::string> &_attr) {
    this->m_attr.resize(ST_Card::N_ATTR);

    this->m_attr[ST_Card::ID]       = _attr[ST_Card::ID];
    this->m_attr[ST_Card::NAME]     = _attr[ST_Card::NAME];
    this->m_attr[ST_Card::COMPANY]  = _attr[ST_Card::COMPANY];
    this->m_attr[ST_Card::YEAR]     = _attr[ST_Card::YEAR];
    this->m_attr[ST_Card::SPEED]    = _attr[ST_Card::SPEED];
    this->m_attr[ST_Card::RANGE]    = _attr[ST_Card::RANGE];
    this->m_attr[ST_Card::LENGTH]   = _attr[ST_Card::LENGTH];
    this->m_attr[ST_Card::WINGSPAN] = _attr[ST_Card::WINGSPAN];
}

// Getter
std::string ST_Card::getAttribute(const ST_Card::attribute_t &_at) const {
    return this->m_attr[_at];
}

// Methods
void ST_Card::displayCard() const {
    std::cout << std::string(4, ' ')
              << std::fixed << std::left << std::setprecision(2)
              << this->m_attr[ST_Card::ID] << "  | "
              << std::setw(30) << this->m_attr[ST_Card::NAME]     << " | "
              << std::setw(28) << this->m_attr[ST_Card::COMPANY]  << " | "
              << std::setw(8)  << this->m_attr[ST_Card::YEAR]     << " | "
              << std::setw(5)  << this->m_attr[ST_Card::SPEED]    << " | "
              << std::setw(5)  << this->m_attr[ST_Card::RANGE]    << " | "
              << std::setw(6)  << this->m_attr[ST_Card::LENGTH]   << " | "
              << std::setw(6)  << this->m_attr[ST_Card::WINGSPAN] << std::endl;
}
