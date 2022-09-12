// poker_sim.cpp
#include "poker_sim.h"

int myrandom(int i)
{
  return rand()%i;
}

Card::Card(string rank, string suit)
{
  this->rank = rank;
  this->suit = suit;
}
Poker_sim::Poker_sim()
{


}
/*
int Poker_sim::poker_evaluate(vector<Card> card_deck)
{
  return 0;
}
*/
void Poker_sim::print_deck()
{
  for (auto const &i : card_deck)
  {
    // cout << i.rank << i.suit << " ";
  }
}
// shuffles vector of card objects 
void Poker_sim::shuffle_desk()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = default_random_engine(seed);

    std::shuffle(begin(card_deck), end(card_deck), rng); // explain how shuffle works
}
// takes 5 cards from top of Card deck and pushes them into flop
void Poker_sim::deal_flop()
{
  flop.clear(); // clean flop , rebuild
  for (int i = 0; i < 5; i++)
  {
    //// cout << card_deck.back() << endl;
    flop.push_back(card_deck.back()); // retrieve last element in flop
    card_deck.pop_back(); // remove last element
  }
  //// cout<< "printing flop: " << endl;
  /*for (auto const &i : flop)
  {
    // cout << "flop element: "<< i.rank << i.suit << " " << endl;
  }
  */
}
// Was used previously to deal random cards to players
// In the project we assign players specific hole cards
// So this function is obsolete
void Poker_sim::deal_players()
{
  villian_hand.push_back(card_deck.back()); // get last card
  card_deck.pop_back(); // get rid of dealt card
  villian_hand.push_back(card_deck.back());
  card_deck.pop_back();

  hero_hand.push_back(card_deck.back());
  card_deck.pop_back();
  hero_hand.push_back(card_deck.back());
  card_deck.pop_back();

  for (auto const &i : villian_hand)
  {
    // cout << "villian hand" << i.rank << i.suit << " " << endl;

  }

  for (auto const &i : hero_hand)
  {
    // cout << "hero hand" << i.rank << i.suit << " " << endl;
    
  }
}
// Evaluate function determines a winner using
// Passed in hole cards and flop
// using the 7 cards we can determine a rank for the hero and villian
bool Poker_sim::poker_evaluate()
{
  //// cout << "test1" << endl;
  string flop_element1 = flop[0].rank + flop[0].suit;
  string flop_element2 = flop[1].rank + flop[1].suit;
  string flop_element3 = flop[2].rank + flop[2].suit;
  string flop_element4 = flop[3].rank + flop[3].suit;
  string flop_element5 = flop[4].rank + flop[4].suit;
  //// cout << "test2" << endl;
  string hero_element1 = hero_hand[0].rank + hero_hand[0].suit; // hero first card
  string hero_element2 = hero_hand[1].rank + hero_hand[1].suit; // second card
  //// cout << "test3" << endl;
  string villian_element1 = villian_hand[0].rank + villian_hand[0].suit; // villian first card
  string villian_element2 = villian_hand[1].rank + villian_hand[1].suit; // second card
  
  //// cout << "flop: " << endl;
  // cout << flop_element1 << flop_element2 << flop_element3 << flop_element4 << flop_element5 << endl;

  //// cout << "hero hand: " << hero_element1 << hero_element2 << endl;
  //// cout << "villian hand: " << villian_element1 << villian_element2 << endl;
  //// cout << "test4" << endl;
  phevaluator::Rank hero_rank = phevaluator::EvaluateCards(flop_element1,flop_element2,flop_element3,flop_element4,flop_element5, hero_element1, hero_element2);  // evalute flop and hero hands
  phevaluator::Rank villian_rank = phevaluator::EvaluateCards(flop_element1,flop_element2,flop_element3,flop_element4,flop_element5,villian_element1,villian_element2); // evaluate flop and villian hand
  //// cout << "test5" << endl;
  if(hero_rank > villian_rank)
  {
    // cout << "hero winner: with "<< hero_rank.describeCategory() << endl;
    return true;
  }
  else if ( hero_rank == villian_rank )
  {
    // cout << "split pot: with "<< hero_rank.describeCategory() << endl;
    return false;
  }
  else
  {
    // cout << "villian winner: with "<< villian_rank.describeCategory() << endl;
    return false;
  }
}

// Remove passed in hole cards from current deck
// This is done to prevent repeated cards
void Poker_sim::adjust_deck(vector<string> entries)
{
   //int i = 0; i < card_deck.size(); i++
  for( auto i = card_deck.begin(); i != card_deck.end(); ) // i can be less than vector size when adjustments are made
  {
    //// cout << "card size: " << card_deck.size()<< "i: " << i << endl;
    //// cout << "current card: " << i->rank << i->suit << endl;
    if(i->rank == entries[0] && i->suit == entries[1])
    {
      // found first hand, remove from deck.
      hero_hand.push_back(*i); // give card to hero
      //// cout << "card at i: " << i->rank << i->suit << endl;
      i = card_deck.erase(i); //  remove card from deck
    }
    else if (i->rank == entries[2] && i->suit == entries[3])
    {
      // found second hand
      hero_hand.push_back(*i); // give card to hero
      //// cout << "card at i: " << i->rank << i->suit << endl;
      i = card_deck.erase(i); //  remove card from deck
    }
    else if (i->rank == entries[4] && i->suit == entries[5])
    {
      // found second hand
      villian_hand.push_back(*i); // give card to hero
      //// cout << "card at i: " << i->rank << i->suit << endl;
      i = card_deck.erase(i); //  remove card from deck
    }
    else if (i->rank == entries[6] && i->suit == entries[7])
    {
      // found second hand
      villian_hand.push_back(*i); // give card to hero
      //// cout << "card at i: " << i->rank << i->suit << endl;
      i = card_deck.erase(i); //  remove card from deck
    }
    else
    {
      i++;
    }
  }
}
// clears hero and villian hole cards
void Poker_sim::clear_hands()
{
  villian_hand.clear();
  hero_hand.clear();
}

// rebuild fresh deck
void Poker_sim::rebuild_deck()
{
  if(!card_deck.empty())
  {  
  card_deck.clear(); // clear card_deck
  //card_deck.resize(52);
  }

  vector<Card> hearts = {Card("A","h"), Card("2","h"), Card("3","h"), Card("4","h"), Card("5","h"), Card("6","h"),Card("7","h"),Card("8","h"),Card("9","h"),Card("T","h"),Card("J","h"),Card("Q","h"),Card("K","h")};

  vector<Card> diamonds = {Card("A","d"), Card("2","d"), Card("3","d"), Card("4","d"), Card("5","d"), Card("6","d"),Card("7","d"),Card("8","d"),Card("9","d"),Card("T","d"),Card("J","d"),Card("Q","d"),Card("K","d")};
  vector<Card> spades = {Card("A","s"), Card("2","s"), Card("3","s"), Card("4","s"), Card("5","s"), Card("6","s"),Card("7","s"),Card("8","s"),Card("9","s"),Card("T","s"),Card("J","s"),Card("Q","s"),Card("K","s")};
  vector<Card> clubs = {Card("A","c"), Card("2","c"), Card("3","c"), Card("4","c"), Card("5","c"), Card("6","c"),Card("7","c"),Card("8","c"),Card("9","c"),Card("T","c"),Card("J","c"),Card("Q","c"),Card("K","c")};

  card_deck = hearts;
  card_deck.insert(card_deck.end(), diamonds.begin(), diamonds.end());
  card_deck.insert(card_deck.end(), spades.begin(), spades.end());
  card_deck.insert(card_deck.end(), clubs.begin(), clubs.end()); // rebuild clean deck
}



int main()
{
  srand( unsigned ( time(0) ) );
  /*
  vector<string> hearts = {"A_h", "2_h", "3_h", "4_h", "5_h", "6_h","7_h","8_h","9_h","10_h","J_h","Q_h","K_h"};
  vector<string> diamonds = {"A_d", "2_d", "3_d", "4_d", "5_d", "6_d","7_d","8_d","9_d","10_d","J_d","Q_d","K_d"};
  vector<string> spades = {"A_s", "2_s", "3_s", "4_s", "5_s", "6_s","7_s","8_s","9_s","10_s","J_s","Q_s","K_s"};
  vector<string> clubs = {"A_c", "2_c", "3_c", "4_c", "5_c", "6_c","7_c","8_c","9_c","10_c","J_c","Q_c","K_c"};
  */
  Poker_sim simulate_poker;

  /*
  simulate_poker.card_deck = hearts;
  simulate_poker.card_deck.insert(simulate_poker.card_deck.end(), diamonds.begin(), diamonds.end());
  simulate_poker.card_deck.insert(simulate_poker.card_deck.end(), spades.begin(), spades.end());
  simulate_poker.card_deck.insert(simulate_poker.card_deck.end(), clubs.begin(), clubs.end());
  */ // moved to function rebuild_deck()


  // functions to see how it works
  //simulate_poker.shuffle_desk();
  //simulate_poker.print_deck();
  //simulate_poker.deal_flop();
  //simulate_poker.adjust_deck();

  // Entries for hole cards 8 entries for 4 suits, 4 ranks
  int entries_num = 8; // 4 different cards
  vector<string> entries;
  string cur_entry;
  for ( int i = 0; i < entries_num ; i++)
  {
    // cout << "Enter Rank, then suit: " << endl;
    if(cin >> cur_entry)
    {
      entries.push_back(cur_entry);
    }
    //// cout << entries[i] << endl;
  } 
  int n;
  // cout << "Enter number of iterations n: " << endl;
  cin >> n;

  // Parallel portion
  // openMp reduction on winrate variable
  // Monte Carlo loop

  struct timespec start, end;
  uint64_t diff;
  clock_gettime(CLOCK_MONOTONIC, &start);    /* mark start time */

  int win_rate = 0;
  for(int i = 0; i < n; i++)
  {
    // cout <<" new deck " << "i: " << i << endl;
    simulate_poker.rebuild_deck(); // clean deck up
    //simulate_poker.print_deck();
    simulate_poker.adjust_deck(entries);
    simulate_poker.shuffle_desk(); // shuffle deck
    simulate_poker.deal_flop();  // deal flop
    bool result = simulate_poker.poker_evaluate();
    if(result)
    {
      win_rate++;
    }
    simulate_poker.clear_hands();
  }
  float fin = win_rate / float(n);
  cout << "Hero Win Rate is: " << fin << endl;
  clock_gettime(CLOCK_MONOTONIC, &end);    /* mark the end time */

  diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
  printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

  return 0;
  } 
    /*
    simulate_poker.deal_flop();  // deal flop
    
  float fin = win_rate / 5;
  // cout << "Hero Win Rate is: " << fin << endl;
  */

  



