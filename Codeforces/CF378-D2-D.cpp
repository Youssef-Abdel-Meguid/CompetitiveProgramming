/*
one single bug can be fixed by a lot of students ,,, so we concern about minimizing the sum of passes to all students who fix the bugs
so do binary seach in how many bugs one singel student (the lowest passe) can do 
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, s, ans[100000];
pair<int, int>a[100000];
pair<pair<int, int>, int>b[100000];

bool check(int mid)
{
    set<pair<int, int> >se;
    int i = n - 1, j = m - 1;
    long long passed = 0;
    while(j >= 0)
    {
        while(i >= 0 && b[i].first.first >= a[j].first)
        {
            se.insert(make_pair(b[i].first.second, b[i].second));
            i--;
        }
        if(se.empty())
            return false;
        passed += (*se.begin()).first;
        for(int k = 0; k < mid; k++)
            if(j - k >=0)
                ans[a[j - k].second] = (*se.begin()).second;
        j -= mid;
        se.erase(se.begin());
    }
    return passed <= s;
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].first.first);
        b[i].second = i;
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i].first.second);
    sort(a, a + m);
    sort(b, b + n);
    int l = 1, r = m, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    if(l == m + 1)
        printf("NO\n");
    else
    {
        bool x = check(l);
        printf("YES\n");
        for(int i = 0; i < m; i++)
            printf("%d ", ans[i]+1);
        printf("\n");
    }
    return 0;
}
