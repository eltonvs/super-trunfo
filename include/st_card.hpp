#ifndef _ST_Card_
#define _ST_Card_

#include <string>

class ST_Card {
 public:
    enum attribute_t {ID, NAME, ORIGIN, YEAR, SPEED, RANGE, LENGTH, WINGSPAN, N_ATTR};

    ST_Card(std::string, std::string, std::string, int, int, int, float, float);
    std::string getAttribute(int);
    void displayCard();

 private:
    std::string m_id;
    std::string m_name;
    std::string m_origin;
    int m_year;
    int m_speed;
    int m_range;
    float m_length;
    float m_wingspan;
};

#endif