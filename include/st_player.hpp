#ifndef _ST_Player_
#define _ST_Player_

#include <string>
#include "st_card.hpp"

class ST_Player {
 public:
    // Constructor
    ST_Player(const std::string&);
    // Getters
    std::string name() const;
    int get_nCards() const;
    // Setters
    void addCard(const ST_Card&);
    // Methods
    ST_Card pop_card();
    ST_Card::attribute_t chooseRandomAttrib() const;
    void displayCards() const;
    void chooseCardAI(const ST_Card::attribute_t&);

 private:
    std::string m_name;
    std::vector<ST_Card> m_cards;
};

#endif
