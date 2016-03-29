#include <iostream>
#include <fstream>
#include <string>
#include "st_card.hpp"
#include "st_game.hpp"
#include "st_player.hpp"

int main(int argc, char const *argv[]) {
    std::string cardsFileName;  // Holds the cards file name .
    std::ifstream inputFile;
    auto N_PLAYERS(0), N_CARDS(0);
    if (argc > 1) {
        cardsFileName = argv[1];
        N_PLAYERS = std::stoi(argv[2]);
        N_CARDS = std::stoi(argv[3]);
    }

    ST_Card carta("A1", "Boeing 737-2C3/Adv", "Cruzeiro - Brazil", 1967, 927, 4260, 30.53, 28.35);
    carta.displayCard();

    std::cout << cardsFileName << "\n";
    std::cout << N_PLAYERS << "\n";
    std::cout << N_CARDS << "\n";

    return EXIT_SUCCESS;
}

/*
int main (int argc, char *argv[]) {
    std::string cardsFileName; // Holds the cards file name .
    std::ifstream inputFile;
    // Stream object to handle the input file .
    // (1): Process any command line arguments .
    // (2): Create a game object .
    ST_Game myGame;
    if (!myGame.reaDeckFromFile(inputFile)) {
        // ERROR MESSAGE GOES HERE .
    }
    // (3): Show deck on screen .
    myGame.displayDeck();
    // (4): Create and add 3 players to the game object.
    myGame.addPlayer(new ST_Player("Player #1"));
    myGame.addPlayer(new ST_Player("Player #2"));
    myGame.addPlayer(new ST_Player("Player #3"));
    // (5): Deal the same amount of cards to all players .
    if (!myGame.dealCards(N_CARDS)) { // Deals N_CARDS to each player.
        // ERROR MESSAGE GOES HERE
    }
    // (6): Run a game with several rounds .
    auto nRounds = myGame.run();
    // (7): Get winner and display the winner .
    auto winner = myGame.winner();
    std::cout << "\n\n>>> The winner after " << nRounds
              << " rounds played is : \" " << winner->name() << " \"\n\n";
    return EXIT_SUCCESS;
}
*/
