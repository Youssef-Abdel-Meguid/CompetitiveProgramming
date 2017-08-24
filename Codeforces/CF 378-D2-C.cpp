#include<bits/stdc++.h>

using namespace std;

int n,m,k,c,l,r;
string a[501];

void dfs(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m||!c||a[i][j]!='.')
        return;
    c--;
    a[i][j]='X';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            for(int j=0;j<m;j++)
                if(a[i][j]=='.')
                    c++,l=i,r=j;
        }
    c-=k;
    dfs(l,r);
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            if(a[i][j]=='X')
                printf(".");
            else if(a[i][j]=='.')
                printf("X");
            else
                printf("#");
            printf("\n");
        }

    return 0;
}
