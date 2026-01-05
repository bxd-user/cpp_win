#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;
const vector<string> rank_card = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
const vector<string> color = {"Hearts", "Diamonds", "Clubs", "Spades"};
struct card
{
    int rk;
    int col;
};
bool cmp(const card &a, const card &b)
{
    if (a.rk != b.rk)
        return a.rk < b.rk;
    return a.col < b.col;
}
ostream &operator<<(ostream &os, const card &c)
{
    os << rank_card[c.rk] << " of " << color[c.col];
    return os;
}
card random_card()
{
    random_device rd;
    mt19937 gen(rd());
    static uniform_int_distribution<> rank_dis(0, 12);
    static uniform_int_distribution<> color_dis(0, 3);
    card c;
    c.rk = rank_dis(gen);
    c.col = color_dis(gen);
    return c;
}
int main()
{
    vector<card> cards;
    for (int i = 0; i < 5; i++)
    {
        cards.push_back(random_card());
    }
    for (const auto &c : cards)
    {
        cout << c << endl;
    }
    sort(cards.begin(), cards.end(), cmp);
    cout << endl;
    for (const auto &c : cards)
    {
        cout << c << endl;
    }
    return 0;
}
