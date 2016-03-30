#ifndef _ST_Game_
#define _ST_Game_

#include <string>
#include <vector>
#include "st_player.hpp"
#include "st_card.hpp"

class ST_Game {
 public:
    // Methods
    int run(bool = false);
    ST_Player* winner();
    bool readDeckFromFile(std::ifstream &);
    void addPlayer(ST_Player *);
    bool dealCards(int);
    void displayDeck();
    void displayPlayers();
    void displayStatusRound();
    void displayCardsOnTable();

 private:
    int m_curr_player = 0;
    ST_Card::attribute_t m_chosen_attr;
    std::vector <ST_Player> m_players;
    std::vector <ST_Card> m_cards;
    std::vector <ST_Card> m_table_cards;
};

#endif