#ifndef _ST_Game_
#define _ST_Game_

#include <string>
#include <vector>
#include "st_player.hpp"

class ST_Game {
 public:
    // Methods
    int run();
    std::string winner();
    bool readDeckFromFile(std::ifstream &);
    void addPlayer(ST_Player);
    void dealCards(int);
    void displayDeck();
    void displayPlayers();
    void displayStatusRound();
    void displayCardsOnTable();

 private:
    std::vector <ST_Player> m_players;
};

#endif