#include <iostream>
#include <string>
#include "st_card.hpp"

ST_Card::ST_Card(std::string _id, std::string _name,
    std::string _origin, int _year, int _speed,
    int _range, float _length, float _wingspan) {

    this->m_id       = _id;
    this->m_name     = _name;
    this->m_origin   = _origin;
    this->m_year     = _year;
    this->m_speed    = _speed;
    this->m_range    = _range;
    this->m_length   = _length;
    this->m_wingspan = _wingspan;
}


void ST_Card::displayCard() {
    /*
    std::cout << "ID: " << this->m_id
              << "\nName: "<< this->m_name
              << "\nfabricante e pais de origem: " << this->m_origin
              << "\nAno: " << this->m_year
              << "\ncomprimento: " << this->m_length
              << "\nEnvergadura: " << this->m_wingspan << std::endl;
    */
}
