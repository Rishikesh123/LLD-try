#include <bits/stdc++.h>
using namespace std;

class player
{
public:
    int id;
    char shape;
    player(int id, char shape)
    {
        this->id = id;
        this->shape = shape;
    }
};
class cell
{
public:
    int id;
    char shape;
    cell()
    {
        this->shape = '.';
        this->id = -1;
    }

    bool operator!=(cell a)
    {
        return !(this->id == a.id && this->shape == a.shape);
    }
};
class board
{
public:
    int n;
    vector<vector<cell>> cells;

    board(int n)
    {
        this->n = n;
        this->cells.resize(n, vector<cell>(n));
    }

    int getWinner()
    {
        // rows
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            cell prev = cells[i][0];
            for (int j = 1; j < n; j++)
            {
                if (prev != cells[i][j])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                return prev.id;
            }
        }

        // column
        for (int i = 0; i < n; i++)
        {
            bool flag = false;
            cell prev = cells[0][i];
            for (int j = 1; j < n; j++)
            {
                if (prev != cells[j][i])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
            {
                return prev.id;
            }
        }

        // diagonal
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (cells[i][i] != cells[0][0])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            return cells[0][0].id;
        }

        return -1;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << cells[i][j].shape;
            }
            cout << endl;
        }
    }
};

int main()
{
    player p1 = player(1, 'X');
    player p2 = player(2, 'O');
    int n;
    cin >> n;
    board gameboard = board(n);
    queue<player> q;
    q.push(p1);
    q.push(p2);
    int winner = -1;
    while (winner == -1)
    {
        gameboard.print();
        int x, y;
        cin >> x >> y;
        player curr = q.front();
        q.pop();
        q.push(curr);

        gameboard.cells[x][y].shape = curr.shape;
        gameboard.cells[x][y].id = curr.id;

        winner = gameboard.getWinner();
    }
    cout << winner << endl;
}