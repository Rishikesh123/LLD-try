#include <bits/stdc++.h>
using namespace std;
class player
{
public:
    int id;
    int loc;
    player(int id, int loc)
    {
        this->id = id;
        this->loc = loc;
    }
};
class dice
{
public:
    int n;
    dice(int n)
    {
        this->n = n;
    }
    int getnext()
    {
        return (rand() % n) + 1;
    }
};
class cell
{
public:
    bool hasladder;
    int ladder_loc;
    cell(bool hasladder, int ladder_loc)
    {
        this->hasladder = hasladder;
        this->ladder_loc = ladder_loc;
    }
};

class board
{
public:
    int n;
    vector<cell> cells;
    board(int n)
    {
        this->n = n;
        this->cells.resize(n, cell(false, NULL));
    }
    void addladder(int i, int j)
    {
        cells[i].hasladder = true;
        cells[i].ladder_loc = j;
    }
};

int main()
{
    player p1(1, 0), p2(2, 0);
    queue<player> q;
    q.push(p1), q.push(p2);
    int winner = -1;
    dice dice(6);
    board gameboard(101);
    // add ladders
    gameboard.addladder(1, 10);
    gameboard.addladder(2, 10);
    gameboard.addladder(3, 10);
    gameboard.addladder(4, 10);
    gameboard.addladder(5, 10);
    gameboard.addladder(6, 10);
    gameboard.addladder(98, 2);
    gameboard.addladder(99, 2);
    gameboard.addladder(97, 2);
    while (winner == -1)
    {
        player curr = q.front();
        q.pop();
        int next = dice.getnext();
        cout << curr.id << " " << next << " " << curr.loc << endl;
        curr.loc += next;
        if (curr.loc >= 100)
        {
            cout << curr.id << endl;
            return curr.id;
        }
        if (gameboard.cells[curr.loc].hasladder)
        {
            curr.loc = gameboard.cells[curr.loc].ladder_loc;
            if (curr.loc >= 100)
            {
                cout << curr.id << endl;
                return curr.id;
            }
        }
        q.push(curr);
    }

    return 0;
}