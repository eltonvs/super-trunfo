#include <iostream>
#include <fstream>
#include <string>
#include "st_card.hpp"
#include "st_game.hpp"
#include "st_player.hpp"

const std::vector <std::string> attr_names = {"ID", "NAME", "COMPANY", "YEAR", "SPEED", "RANGE", "LENGTH", "WINGSPAN"};

int main(int argc, char const *argv[]) {
    std::string cardsFileName;  // Holds the cards file name.
    auto N_PLAYERS(0), N_CARDS(0);
    if (argc > 3) {
        cardsFileName = argv[1];
        N_PLAYERS     = std::stoi(argv[2]);
        N_CARDS       = std::stoi(argv[3]);
    } else {
        std::cerr << "No file specified\n";
        exit(EXIT_FAILURE);
    }

    if (N_PLAYERS <= 0 || N_CARDS <= 0) {
        std::cerr << "The number of cards/players cannot be less than 1\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream inputFile("data/" + cardsFileName);
    ST_Game myGame;
    if (!myGame.readDeckFromFile(inputFile)) {
        std::cerr << "The informed file cannot be opened\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "\nWelcome to Super Trunfo! copyright DIMAp/IMD, 2016.\n"
              << "# of players: " << N_PLAYERS << "\n"
              << "# of cards per player: " << N_CARDS << "\n\n";

    // (3): Show deck on screen.
    myGame.displayDeck();

    // (4): Create and add N_PLAYERS players to the game object.
    for (int i = 0; i < N_PLAYERS; i++)
        myGame.addPlayer(new ST_Player("Player #" + std::to_string(i + 1)));

    // (5): Deal the same amount of cards to all players.
    if (!myGame.dealCards(N_CARDS)) { // Deals N_CARDS to each player.
        std::cerr << "Error at dealCards()\n";
        exit(EXIT_FAILURE);
    }

    // (6): Run a game with several rounds.
    auto nRounds = myGame.run();

    // (7): Get winner and display the winner.
    auto winner = myGame.winner();
    std::cout << ">>> The winner after " << nRounds
              << " rounds played is : \"" << winner->name() << "\"\n\n";

    return EXIT_SUCCESS;
}
