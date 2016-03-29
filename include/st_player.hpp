#ifndef _ST_Player_
#define _ST_Player_

#include <string>
#include "st_card.hpp"

class ST_Player {
 public:
    // Constructor
    ST_Player(std::string name);
    // Getters
    std::string get_name();
    int get_nCards();
    // Setters
    void addCard();
    // Methods
    ST_Card pop_card();
    int chooseRandomAttrib();
    void displayCards();

 private:
    std::string m_name;
    std::vector <ST_Card> m_cards;
};

#endif
