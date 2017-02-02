#include <bits/stdc++.h>

using namespace std;

map<vector<int>,string>ma;
string ans;

void init(vector<int>&vec)
{
    vec.push_back(0);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(0);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(7);
    vec.push_back(8);
    vec.push_back(7);
    vec.push_back(0);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
}

vector<int>rotate(vector<int>vec,int type)
{
    if(type==1)
    {
        int tmp1=vec[10];
        int tmp2=vec[11];
        for(int i=11;i>=2;i--)
            vec[i]=vec[i-2];
        vec[0]=tmp1;
        vec[1]=tmp2;
        vec[21]=vec[9];
        vec[22]=vec[10];
        vec[23]=vec[11];
    }
    else if(type==3)
    {
        int tmp1=vec[0];
        int tmp2=vec[1];
        for(int i=2;i<=11;i++)
            vec[i-2]=vec[i];
        vec[10]=tmp1;
        vec[11]=tmp2;
        vec[21]=vec[9];
        vec[22]=vec[10];
        vec[23]=vec[11];
    }
    else if(type==2)
    {
        int tmp1=vec[12];
        int tmp2=vec[13];
        for(int i=14;i<=23;i++)
            vec[i-2]=vec[i];
        vec[22]=tmp1;
        vec[23]=tmp2;
        vec[9]=vec[21];
        vec[10]=vec[22];
        vec[11]=vec[23];
    }
    else
    {
        int tmp1=vec[22];
        int tmp2=vec[23];
        for(int i=23;i>=14;i--)
            vec[i]=vec[i-2];
        vec[12]=tmp1;
        vec[13]=tmp2;
        vec[9]=vec[21];
        vec[10]=vec[22];
        vec[11]=vec[23];
    }
    return vec;
}

void solve1(int last,vector<int>vec,int moves,string s)
{
    if(moves==9)
        return;
    if(!ma.count(vec)||ma[vec].size()>s.size()||(ma[vec].size()==s.size()&&ma[vec]>s))
        ma[vec]=s;
    if(last!=3)
        solve1(1,rotate(vec,1),moves+1,'3'+s);
    if(last!=4)
        solve1(2,rotate(vec,2),moves+1,'4'+s);
    if(last!=1)
        solve1(3,rotate(vec,3),moves+1,'1'+s);
    if(last!=2)
        solve1(4,rotate(vec,4),moves+1,'2'+s);
}

void solve2(int last,vector<int>vec,int moves,string s)
{
    if(moves==9)
        return;
    if(ma.count(vec))
    {
        if(ans=="0"||ans.size()>ma[vec].size()+s.size()||(ma[vec].size()==ma[vec].size()+s.size()&&ma[vec]>s))
            ans=s+ma[vec];
    }
    if(last!=3)
        solve2(1,rotate(vec,1),moves+1,s+'1');
    if(last!=4)
        solve2(2,rotate(vec,2),moves+1,s+'2');
    if(last!=1)
        solve2(3,rotate(vec,3),moves+1,s+'3');
    if(last!=2)
        solve2(4,rotate(vec,4),moves+1,s+'4');
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    int cases;
    cin>>cases;
    vector<int>vec,final;
    init(vec);
    final=vec;
    solve1(0,vec,0,"");
    while(cases--)
    {
        vector<int>vec1;
        for(int i=0;i<24;i++)
        {
            int x;
            cin>>x;
            vec1.push_back(x);
        }
        if(final==vec1)
            printf("PUZZLE ALREADY SOLVED\n");
        else
        {
            ans="0";
            solve2(0,vec1,0,"");
            if(ans=="0")
                printf("NO SOLUTION WAS FOUND IN 16 STEPS\n");
            else
                cout<<ans<<endl;
        }
    }    
    return 0;
}
