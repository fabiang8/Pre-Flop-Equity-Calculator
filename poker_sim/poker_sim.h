// poker_sim.h
#ifndef POKER_SIM_H
#define POKER_SIM_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <chrono>
#include <phevaluator/phevaluator.h> // hand evaluator library
#include <cctype>
#include <time.h>
#include <stdint.h>
#define BILLION 1000000000L


using std::vector;
using namespace std;

class Card
{
  public:
    string rank;
    string suit;

    Card(string rank, string suit);
   
};
class Poker_sim
{
  public:

    Poker_sim();
    vector<Card> card_deck; // deck of cards
    vector<Card> villian_hand;
    vector<Card> hero_hand;
    vector<Card> flop;
    bool poker_evaluate(); // return true of false if hero one
    void print_deck();
    void shuffle_desk();
    void set_hero();
    void deal_flop();
    void deal_players();
    void rebuild_deck();
    void adjust_deck(vector<string> entries);

    void clear_hands();

};


#endif
