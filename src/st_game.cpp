#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include "st_game.hpp"

// Methods
int ST_Game::run(const bool &IA) {
    int n_rounds = 0;
    int round_winner = 0;

    while (this->m_players.size() > 1) {
        std::cout << std::string(100, '=') << "\n"
                  << ">>> Round #" << n_rounds + 1 << "\n\n";

        // Define choosen attribute
        this->m_chosen_attr = this->m_players[round_winner].chooseRandomAttrib();

        this->displayStatusRound();

        std::cout << std::string(4, ' ') << "Players' hand at the BEGINNING of the round:\n\n";

        this->displayPlayers();
        
        for (auto i(0u); i < this->m_players.size(); i++) {
            if (IA)
                this->m_players[i].chooseCardAI(this->m_chosen_attr);
            this->m_table_cards.push_back(this->m_players[i].pop_card());
        }

        this->displayCardsOnTable();

        // Define winner
        round_winner = 0;
        double max_val = std::stod(this->m_table_cards[0].getAttribute(this->m_chosen_attr));
        for (auto i(1u); i < this->m_table_cards.size(); i++)
            if (std::stod(this->m_table_cards[i].getAttribute(this->m_chosen_attr)) > max_val)
                round_winner = i,
                max_val = std::stod(this->m_table_cards[i].getAttribute(this->m_chosen_attr));

        // Verify ST card
        for (auto i(0u); i < this->m_table_cards.size(); i++) {
            if (this->m_table_cards[i].getAttribute(ST_Card::ID) == "ST") {
                round_winner = i;
                max_val = 0;
                for (auto j(0u); j < this->m_table_cards.size(); j++)
                    if (j != i && this->m_table_cards[j].getAttribute(ST_Card::ID)[1] == '1'
                        && std::stod(this->m_table_cards[j].getAttribute(this->m_chosen_attr)) > max_val)
                        round_winner = j,
                        max_val = std::stod(this->m_table_cards[j].getAttribute(this->m_chosen_attr));
            }
        }

        std::cout << std::string(4, ' ') << "*** The winner of this round is player \""
                  << this->m_players[round_winner].name() << "\" ***\n\n";

        // Pass all cards on table to winner
        for (auto i(0u); i < this->m_table_cards.size(); i++)
            this->m_players[round_winner].addCard(this->m_table_cards[i]);

        for (auto i(0u); i < this->m_players.size(); i++)
            if (this->m_players[i].get_nCards() == 0) {
                this->m_players.erase(this->m_players.begin() + i);
                i--;
            }

        // Clear table
        this->m_table_cards.clear();

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

bool ST_Game::dealCards(const int &k) {
    auto n_players = this->m_players.size();
    // Run tests
    if (this->m_cards.size() < k*n_players)
        return false;

    // Creates a auxiliar vetor to receive the shuffled vector
    auto cards = this->m_cards;
    // Creates a real random number
    std::random_device r;
    // Shuffle vector content using the random number as seed
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(r()));

    for (int i = 0; i < k; i++)
        for (auto j(0u); j < n_players; j++)
            this->m_players[j].addCard(cards[i*n_players+j]);

    return true;
}

void ST_Game::displayDeck() const {
    std::cout << ">>> The deck of ST cards read from file:\n";
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
    std::cout << ">>> Deck size is: " << this->m_cards.size() << "\n\n";
}

void ST_Game::displayPlayers () const {
    for (auto i(0u); i < this->m_players.size(); i++) {
        if (this->m_players[i].get_nCards() > 0) {
            std::cout << std::string(4, ' ') << "Player " << '"'
                      << this->m_players[i].name() << '"'
                      << " still active, have " << this->m_players[i].get_nCards()
                      << " cards in hand, and they are:\n";
            this->m_players[i].displayCards();
            std::cout << std::endl;
        }
    }
}

void ST_Game::displayStatusRound() const {
    std::cout << std::string(4, ' ') << "Players still playing: "
              << this->m_players.size() << "\n"
              << std::string(4, ' ') << "Current player is : \""
              << this->m_players[this->m_curr_player].name() << "\"\n"
              << std::string(4, ' ') << "Attribute chosen: \""
              << attr_names[this->m_chosen_attr] << "\".\n\n";
}

void ST_Game::displayCardsOnTable() const {
    std::cout << std::string(4, ' ')
              << "Cards put down on the table for this round:\n";
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
    for (auto i(0u); i < this->m_table_cards.size(); i++)
        this->m_table_cards[i].displayCard();
    std::cout << std::string(4, ' ')
              << std::string(4, '-')  << "+" << std::string(32, '-') << "+"
              << std::string(30, '-') << "+" << std::string(10, '-') << "+"
              << std::string(7, '-')  << "+" << std::string(7, '-')  << "+"
              << std::string(8, '-')  << "+" << std::string(9, '-')  << "\n\n";
}
