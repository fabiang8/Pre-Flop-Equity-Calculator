### Purpose:
The `poker_sim.cpp` file contains classes and functions to simulate a poker game. It provides functionalities to shuffle a deck of cards, deal cards to players, evaluate hands, and calculate win rates based on multiple simulations.

### Functions and Classes:

1. `int myrandom(int i)`: A helper function used to generate random numbers for shuffling the deck.

2. `Card` Class:
   - **Constructor:** Initializes a card with a given rank and suit.

3. `Poker_sim` Class:
   - **Constructor:** Initializes a poker simulator object.

   - `void print_deck()`: Prints the current state of the deck (used for debugging purposes).

   - `void shuffle_desk()`: Shuffles the deck using the Fisher-Yates shuffle algorithm.

   - `void deal_flop()`: Deals five cards from the top of the deck into the flop.

   - `void deal_players()`: Deals cards to players (obsolete for the current project).

   - `bool poker_evaluate()`: Evaluates the hands of the hero and villain players by using the `phevaluator` library.

   - `void adjust_deck(vector<string> entries)`: Removes specified hole cards from the deck to prevent re-dealing.

   - `void clear_hands()`: Clears the hero and villain hands.

   - `void rebuild_deck()`: Rebuilds a fresh deck of 52 cards comprising hearts, diamonds, spades, and clubs.

### Main Function:
The `main()` function serves as the driver function for the poker simulation. It:
- Seeds the random number generator.
- Reads input for hole cards and the number of iterations (n).
- Runs a Monte Carlo simulation using OpenMP parallelization.
- Simulates poker games, evaluates win rates, and measures elapsed time.

### Notes:
- The code uses the `phevaluator` library to evaluate poker hands.
- OpenMP parallelization is employed to run multiple simulations concurrently.
- The code focuses on simulating and evaluating poker hands using a deck of cards and specified player entries.


This documentation outlines the functionality and structure of the `poker_sim.cpp` file, highlighting its key components and functionalities for simulating poker games.

Video below demonstrates program usage and speed comparison between sequential and parallel versions.


https://user-images.githubusercontent.com/68124971/189760735-c4ce1fad-d79b-4fd5-adb1-12648755bcf0.mp4

