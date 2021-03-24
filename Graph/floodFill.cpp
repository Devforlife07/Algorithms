#include <bits/stdc++.h>
#define M 8
#define N 8
using namespace std;
void util(int screen[M][N], int x, int y, int newChar, int curr_char)
{
    if (x < 0 or x >= M or y < 0 or y >= N)
        return;
    if (screen[x][y] != curr_char)
        return;
    screen[x][y] = newChar;
    util(screen, x + 1, y, newChar, curr_char);
    util(screen, x - 1, y, newChar, curr_char);
    util(screen, x, y + 1, newChar, curr_char);
    util(screen, x, y - 1, newChar, curr_char);
    //Applying At Diagonals Also
    util(screen, x + 1, y + 1, newChar, curr_char);
    util(screen, x + 1, y - 1, newChar, curr_char);
    util(screen, x - 1, y + 1, newChar, curr_char);
    util(screen, x - 1, y + 1, newChar, curr_char);
}
void replace(int screen[M][N], int x, int y, int newChar)
{
    int curr_char = screen[x][y];
    util(screen, x, y, newChar, curr_char);
}
void displayGraph(int screen[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << screen[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    int screen[M][N] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };
    int x, y;
    cin >> x >> y;
    int newChar;
    cin >> newChar;
    cout << "INITIAL GRAPH" << endl;
    displayGraph(screen);
    cout << "AFTER ALGORITHM APPLICATION" << endl;
    replace(screen, x, y, newChar);
    displayGraph(screen);

    return 0;
}