#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include "st_player.hpp"

// Constructor
ST_Player::ST_Player(const std::string& name) {
    this->m_name = name;
}

// Getters
std::string ST_Player::name() const {
    return this->m_name;
}
int ST_Player::get_nCards() const {
    return this->m_cards.size();
}

// Setters
void ST_Player::addCard(const ST_Card &_card) {
    this->m_cards.push_back(_card);
}

// Methods
ST_Card ST_Player::pop_card() {
    std::vector<std::string> card;
    for (auto i(0u); i < ST_Card::N_ATTR; i++)
        card.push_back(this->m_cards[0].getAttribute((ST_Card::attribute_t)i));
    ST_Card r(card);

    this->m_cards.erase(this->m_cards.begin());

    return r;
}

ST_Card::attribute_t ST_Player::chooseRandomAttrib() const {
    std::random_device r;
    int random_int = abs(r());
    return (ST_Card::attribute_t)((random_int%4) + 4);
}

void ST_Player::displayCards() const {
    std::cout << std::string(4, ' ')
              << std::string(4, '=')  << "+" << std::string(32, '=') << "+"
              << std::string(30, '=') << "+" << std::string(10, '=') << "+"
              << std::string(7, '=')  << "+" << std::string(7, '=')  << "+"
              << std::string(8, '=')  << "+" << std::string(9, '=')  << "\n";
    std::cout << std::string(4, ' ')
              << std::fixed << std::left
              << "ID  | "
              << std::setw(30) << "NAME"     << " | "
              << std::setw(28) << "COMPANY"  << " | "
              << std::setw(8)  << "MFR_YEAR" << " | "
              << std::setw(5)  << "SPEED"    << " | "
              << std::setw(5)  << "RANGE"    << " | "
              << std::setw(6)  << "LENGTH"   << " | "
              << std::setw(6)  << "WINGSPAN" << std::endl;
    std::cout << std::string(4, ' ')
              << std::string(4, '=')  << "+" << std::string(32, '=') << "+"
              << std::string(30, '=') << "+" << std::string(10, '=') << "+"
              << std::string(7, '=')  << "+" << std::string(7, '=')  << "+"
              << std::string(8, '=')  << "+" << std::string(9, '=')  << "\n";
    for (auto i(0u); i < this->m_cards.size(); i++)
        this->m_cards[i].displayCard();
    std::cout << std::string(4, ' ')
              << std::string(4, '-')  << "+" << std::string(32, '-') << "+"
              << std::string(30, '-') << "+" << std::string(10, '-') << "+"
              << std::string(7, '-')  << "+" << std::string(7, '-')  << "+"
              << std::string(8, '-')  << "+" << std::string(9, '-')  << "\n";
}

void ST_Player::chooseCardAI(const ST_Card::attribute_t &attrib) {
    // Define best option
    auto position(0u);

    double max_val = std::stod(this->m_cards[0].getAttribute(attrib));
    for (auto i(1u); i < this->m_cards.size(); i++)
        if (std::stod(this->m_cards[i].getAttribute(attrib)) > max_val)
            position = i,
            max_val  = std::stod(this->m_cards[i].getAttribute(attrib));

    // Verify ST card
    for (auto i(0u); i < this->m_cards.size(); i++)
        if (this->m_cards[i].getAttribute(ST_Card::ID) == "ST")
            position = i;

    // Swap the cards with your first card of deck
    std::swap(this->m_cards[0], this->m_cards[position]);
}
