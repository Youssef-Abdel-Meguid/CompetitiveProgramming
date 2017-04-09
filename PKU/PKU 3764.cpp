/*
  use trie tree to get the subgraph which has the max XOR ,,,, for deep understanding trace the code very well and step by step 
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stdio.h>
#include<string.h>

using namespace std;

int to[200000], cost[200000], nxt[200000], last[100000], sz;
int trie[100000 * 31][2], cnt, sum_xor[100000], n;

void initi()
{
    memset(trie, -1, sizeof(trie));
    memset(last, -1, sizeof(last));
    cnt = 1;
    sz = 0;
}

void add(int x)
{
    int pos = 0, k;
    for(int i = 30; i >= 0; i--)
    {
        if((1 << i) & x)
            k = 1;
        else
            k = 0;
        if(trie[pos][k] == -1)
            trie[pos][k] = cnt++;
        pos = trie[pos][k];
    }
}

void dfs(int cur, int parent, int x)
{
    sum_xor[cur] = x;
    add(x);
    for(int i = last[cur]; i != -1; i = nxt[i])
        if(to[i] != parent)
            dfs(to[i], cur, cost[i] ^ x);
}

int get_ans(int x)
{
    int pos = 0, ret = 0, k;
    for(int i = 30; i >= 0; i--)
    {
        if((1 << i) & x)
            k = 0;
        else
            k = 1;
        if(trie[pos][k] == -1)
            k ^= 1;
        else
            ret ^= (1 << i);
        pos = trie[pos][k];
    }
    return ret;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        initi();
        for(int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            to[sz] = v, cost[sz] = w, nxt[sz] = last[u], last[u] = sz++;
            to[sz] = u, cost[sz] = w, nxt[sz] = last[v], last[v] = sz++;
        }
        dfs(0, -1, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, get_ans(sum_xor[i]));
        printf("%d\n", ans);
    }
    return 0;
}
