#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "st_game.hpp"

// Methods
int ST_Game::run() {
    int n_rounds = 0;

    while (false && this->m_players.size() > 1) {
        // Do something
        n_rounds++;
    }

    return n_rounds;
}

ST_Player* ST_Game::winner() {
    return (this->m_players.size() == 1) ? &this->m_players[0] : NULL;
}

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

void ST_Game::addPlayer(ST_Player *_p) {
    this->m_players.push_back(*_p);
}

bool ST_Game::dealCards(int k) {
    auto n_players = this->m_players.size();
    // Run tests
    if (this->m_cards.size() < k*n_players)
        return false;

    for (int i = 0; i < k; i++)
        for (auto j(0u); j < n_players; j++)
            this->m_players[j].addCard(this->m_cards[i*n_players+j]);

    return true;
}

void ST_Game::displayDeck() {
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

void ST_Game::displayPlayers (){
    for (auto i(0u); i < this->m_players.size(); i++) {
        if (this->m_players[i].get_nCards() > 0) {
            std::cout << "Player " << '"' << this->m_players[i].name() << '"'
                      << " still active, have " << this->m_players[i].get_nCards()
                      << " cards in hand, and they are:\n";
            this->m_players[i].displayCards();
            std::cout << std::endl;
        }
    }
}
