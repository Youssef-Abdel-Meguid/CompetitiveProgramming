/*
 use 2D BIT ,,, if the direction is 0 (clockwise) add -1 to BIT else add 1
 learn more about 2D BIT -> http://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/
 
*/
#include<bits/stdc++.h>

using namespace std;

int BIT[1001][1001], a[1001][1001], n, m, q;
char dir[4] = {'N', 'W', 'S', 'E'};

int con(char c)
{
    if(c == 'N')
        return 0;
    if(c == 'W')
        return 1;
    if(c == 'S')
        return 2;
    return 3;
}

void add(int x, int y, int val)
{
    while(x <= n)
    {
        int yy = y;
        while(yy <= m)
        {
            BIT[x][yy] += val;
            yy += (yy & -yy);
        }
        x += (x & -x);
    }
}

int get_ans(int x, int y)
{
    int ret = 0;
    while(x > 0)
    {
        int yy = y;
        while(yy > 0)
        {
            ret += BIT[x][yy];
            yy -= (yy & -yy);
        }
        x -= (x & -x);
    }
    return ret;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        memset(BIT, 0, sizeof(BIT));
        for(int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            for(int j = 0; j < m; j++)
                a[i][j+1] = con(s[j]);
        }
        scanf("%d", &q);
        while(q--)
        {
            char c;
            cin >> c;
            if(c == 'C')
            {
                int x1, y1, x2, y2, d;
                scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &d);
                if(!d)
                    d = -1;
                add(x1, y1, d);
                add(x1, y2 + 1, -d);
                add(x2 + 1, y1, -d);
                add(x2 + 1, y2 + 1, d);
            }
            else
            {
                int x, y;
                scanf("%d%d", &x, &y);
                int ans = a[x][y] + get_ans(x, y);
                ans %= 4;
                if(ans < 0)
                    ans += 4;
                printf("%c\n", dir[ans]);
            }
        }
    }
    return 0;
}
