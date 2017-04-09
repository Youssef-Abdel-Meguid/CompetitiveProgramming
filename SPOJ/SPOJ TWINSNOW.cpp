/*
take the 6 vaiables ,,, push them in vector ,,, sort that vector ,,, insert it in a set ,,,, then check if the size of set is equal to n
then No two snowflakes are alike. else Twin snowflakes found. ,,,, use scanf & printf to gurantee the solution will fit in the time limit
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        set< vector<int> > se;
        vector<int> vec;
        for(int i = 0; i < n; i++)
        {
            int a, b, c, x, y, z;
            scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
            vec.push_back(a);
            vec.push_back(b);
            vec.push_back(c);
            vec.push_back(x);
            vec.push_back(y);
            vec.push_back(z);
            sort(vec.begin(), vec.end());
            se.insert(vec);
            vec.clear();
        }
        if(se.size() == n)
            printf("No two snowflakes are alike.\n");
        else
            printf("Twin snowflakes found.\n");
    }
    return 0;
}
