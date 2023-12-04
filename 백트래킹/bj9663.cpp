#include <iostream>

using namespace std;

int n;
int ans = 0;
int row[16];

bool checkPos(int nowRow, int nowCol)
{
    for (int i = 0; i < nowRow; i++)
    {
        if ((nowCol - row[i]) / (nowRow - i) == 1 || (nowCol - row[i]) / (nowRow - i) == -1 || nowCol == row[i])
            return false;
    }
    return true;
}

void solveNqueen(int nowRow)
{
    if (nowRow == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (checkPos(nowRow, i))
        {
            row[nowRow] = i;
            solveNqueen(nowRow + 1);
            row[nowRow] = -1;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        row[i] = -1;
    solveNqueen(0);
    printf("%d", ans);
    return 0;
}