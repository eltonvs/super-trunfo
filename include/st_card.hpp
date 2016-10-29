#ifndef _ST_Card_
#define _ST_Card_

#include <string>
#include <vector>

extern const std::vector <std::string> attr_names;

class ST_Card {
 public:
    enum attribute_t {ID, NAME, COMPANY, YEAR, SPEED, RANGE, LENGTH, WINGSPAN, N_ATTR};

    // Constructors
    ST_Card(const std::string&, const std::string&, const std::string&,
    	    const std::string&, const std::string&, const std::string&,
    	    const std::string&, const std::string&);
    ST_Card(const std::vector<std::string>&);

    // Getter
    std::string getAttribute(const attribute_t&) const;

    // Method
    void displayCard() const;

 private:
    std::vector <std::string> m_attr;
};

#endif
