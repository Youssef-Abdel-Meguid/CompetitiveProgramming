#include <bits/stdc++.h>

using namespace std;

class MoreNim
{
public:
    long long bestSet(vector <string> heaps)
    {
        vector<long long>a,b;
        for(int i=0;i<heaps.size();i++)
        {
            stringstream ss;
            ss<<heaps[i];
            long long x;
            ss>>x;
            a.push_back(x);
            b.push_back(x);
        }
        sort(a.rbegin(),a.rend()); /*sorted in the reverse order cuz i need the min*/
        sort(b.rbegin(),b.rend());
        long long ret=0;
        for(int i=0;i<a.size();i++)
        {
            if(!a[i]) /*removing the heap which make the first player in losing position ,,, i.e xor with this value will lead to 0 whcih make hom lose*/
            {
                ret+=b[i];
                continue;
            }
            long long last_bit=(a[i]&-a[i]);
            for(int j=i+1;j<a.size();j++)
                if(a[j]&last_bit)
                    a[j]^=a[i]; /*regular nim just to help the first player to choose which heap will make him in a losing position*/
        }
        return ret;
    }
};
