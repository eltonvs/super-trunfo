#ifndef _ST_Card_
#define _ST_Card_

class ST_Card {
 public:
 	void Construtor();

 	std::string getAttribute();

 	void displayCard();

 private:

 	std::string card {std::string id, std::string name, std::string origem, int year, float comprimento, float envergadura};

};

#endif