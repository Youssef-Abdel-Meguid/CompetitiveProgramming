/*
just simulate the mine sweeper game
*/

#include<bits/stdc++.h>

int n;

bool valid(int x, int y)
{
    return x >=0 && x < n && y >=0 && y < n;
}

using namespace std;

int dx[8] = {0, 1, -1,   0, 1, -1, -1,  1};
int dy[8] = {1, 0,  0,  -1, 1, -1,  1, -1};

int main()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        cin >> n;
        char a[n][n];
        bool m[n][n];
        memset(m, false, sizeof(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                char c;
                cin >> c;
                if(c == '*')
                    m[i][j] = true;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        bool busted = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int cnt = 0;
                if(a[i][j] == 'x')
                {
                    if(!m[i][j])
                    {
                        for(int k = 0; k < 8; k++)
                        {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            if(valid(x, y) && m[x][y])
                                cnt++;
                        }
                        a[i][j] = (cnt + '0');
                    }
                    else
                        busted = true;
                }
            }
        }
        if(busted)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(m[i][j])
                        a[i][j] = '*';
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j];
            cout << endl;
        }
        if(cases)
            cout << endl;

    }
    return 0;
}
