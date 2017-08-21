#include<bits/stdc++.h>

using namespace std;

class MatrixGame
{
public:
    vector <string> getMinimal(vector <string> matrix)
    {
        vector<string>ans;
        int a[matrix[0].size()],n=matrix[0].size();
        for(int i=0;i<matrix[0].size();i++)
            a[i]=i;
        ans=matrix;
        do
        {
            vector<string>tmp;
            for(int i=0;i<matrix.size();i++)
                tmp.push_back(matrix[0]);
            for(int i=0;i<matrix.size();i++)
                for(int j=0;j<matrix[0].size();j++)
                    tmp[i][a[j]]=matrix[i][j];
            sort(tmp.begin(),tmp.end());
            if(tmp<ans)
                ans=tmp;
        }while(next_permutation(a,a+n));
        return ans;
    }
};
