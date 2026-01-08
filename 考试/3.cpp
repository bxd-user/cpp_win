#include <array>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

struct Card
{
    int rk;
    int col;
};

static constexpr array<const char *, 13> kRanks{
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
static constexpr array<const char *, 4> kSuits{
    "Hearts", "Diamonds", "Clubs", "Spades"};

ostream &operator<<(ostream &os, const Card &c)
{
    os << kRanks[c.rk] << " of " << kSuits[c.col];
    return os;
}

Card random_card(mt19937 &gen)
{
    static uniform_int_distribution<> rank_dis(0, 12);
    static uniform_int_distribution<> suit_dis(0, 3);
    return {rank_dis(gen), suit_dis(gen)};
}

int main()
{
    random_device rd;
    mt19937 gen(rd());

    vector<Card> cards;
    cards.reserve(5);
    for (int i = 0; i < 5; ++i)
    {
        cards.emplace_back(random_card(gen));
    }

    for (const auto &c : cards)
    {
        cout << c << '\n';
    }

    sort(cards.begin(), cards.end(), [](const Card &a, const Card &b)
         { return (a.rk == b.rk) ? (a.col < b.col) : (a.rk < b.rk); });

    cout << '\n';
    for (const auto &c : cards)
    {
        cout << c << '\n';
    }
    return 0;
}
