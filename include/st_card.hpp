#ifndef _ST_Card_
#define _ST_Card_

#include <string>
#include <vector>

class ST_Card {
 public:
    enum attribute_t {ID, NAME, COMPANY, YEAR, SPEED, RANGE, LENGTH, WINGSPAN, N_ATTR};

    // Constructors
    ST_Card(std::string, std::string, std::string, int, int, int, float, float);
    ST_Card(std::vector<std::string>);

    // Getter
    std::string getAttribute(attribute_t);

    // Method
    void displayCard();

 private:
    std::vector<std::string> m_attr;
};

#endif
