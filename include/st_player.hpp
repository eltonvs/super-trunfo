#ifndef _ST_Player_
#define _ST_Player_

#include <string>
#include "st_card.hpp"

class ST_Player {
 public:
    // Constructor
    ST_Player(std::string name);
    // Getters
    std::string name();
    int get_nCards();
    // Setters
    void addCard(ST_Card);
    // Methods
    ST_Card pop_card();
    ST_Card::attribute_t chooseRandomAttrib();
    void displayCards();
    void chooseCardAI(ST_Card::attribute_t);

 private:
    std::string m_name;
    std::vector <ST_Card> m_cards;
};

#endif
