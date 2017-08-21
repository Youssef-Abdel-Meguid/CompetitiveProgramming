#include<bits/stdc++.h>

using namespace std;

class CardsCheating
{
public:
    int numberOfShuffles(vector <int> cards, vector <int> shuffle)
    {
        int n=cards.size(),ans=0;
        vector<int>vec1,vec2(n);
        for(int i=0;i<n;i++)
            vec1.push_back(i);
        while(1)
        {
            bool flag=true;
            for(int i=0;i<n&&flag;i++)
                if(cards[vec1[i]]!=i%3)
                    flag=false;
            if(flag)
                return ans;
            for(int i=0;i<n;i++)
                vec2[shuffle[i]]=vec1[i];
            vec1=vec2;
            bool flag1=true;
            for(int i=0;i<n;i++)
                if(i!=vec1[i])
                    flag1=false;
            if(flag1)
                return -1;
            ans++;
        }
        return ans;
    }
};
