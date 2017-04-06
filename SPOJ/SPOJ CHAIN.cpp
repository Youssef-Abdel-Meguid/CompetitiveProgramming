/*
Idea -> http://wjmzbmr.com/archives/spoj_1442_strange_food_chain/
*/

#include <bits/stdc++.h>

using namespace std;

int rankk[100001+10], parent[100001+10], n, k;

void initi()
{
	for(int i =0; i < n; i++)
	{
		parent[i] = i;
		rankk[i] = 0;
	}
}

int find_set(int x)
{
	if(parent[x] == x)
		return x;
    find_set(parent[x]);
    rankk[x] += rankk[parent[x]];
    rankk[x] %= 3;
	return parent[x] = parent[parent[x]];
}


bool union_set(int x, int y, int t)
{
    int fx = find_set(x);
    int fy = find_set(y);
    if(fx == fy)
        return rankk[x] == (rankk[y] + t) % 3;
    parent[fx] = fy;
    rankk[fx] = (t - rankk[x] + rankk[y]) + 9;
    rankk[fx] %= 3;
    return true;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &n, &k);
        initi();
        int ans = 0;
        while(k--)
        {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
            t--, x--, y--;
            if(x >= n || y >= n)
            {
                ans++;
                continue;
            }
            ans += !union_set(x, y, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
