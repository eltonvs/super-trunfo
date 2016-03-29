#include <iostream>
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
