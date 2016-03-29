#include <iostream>
#include <iomanip>
#include "st_player.hpp"

// Constructor
ST_Player::ST_Player(std::string name) {
    this->m_name = name;
}

// Getters
std::string ST_Player::get_name() {
    return this->m_name;
}
int ST_Player::get_nCards() {
    return this->m_cards.size();
}

// Setters
void ST_Player::addCard(ST_Card _card) {
    this->m_cards.push_back(_card);
}

// Methods
void ST_Player::displayCards() {
        std::cout << "====+================================+"
              << "==============================+==========+"
              << "=======+=======+========+=========\n";
    std::cout << std::fixed << std::left
              << "ID  | "
              << std::setw(30) << "NAME" << " | "
              << std::setw(28) << "COMPANY"<< " | "
              << std::setw(8) << "MFR_YEAR" << " | "
              << std::setw(5) << "SPEED" << " | "
              << std::setw(5) << "RANGE" << " | "
              << std::setw(6) << "LENGTH" << " | "
              << std::setw(6) << "WINGSPAN" << std::endl;
    std::cout << "====+================================+"
              << "==============================+==========+"
              << "=======+=======+========+=========\n";
    for (auto i(0u); i < this->m_cards.size(); i++)
        this->m_cards[i].displayCard();
    std::cout << "----+--------------------------------+"
              << "------------------------------+----------+"
              << "-------+-------+--------+---------\n";
}
