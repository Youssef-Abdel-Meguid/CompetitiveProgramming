/*
use binary tree (trie) with depth 20 (cuz i just need to 1000000 max vlaue of K we don't need more than that) each left child has the value of bit which appers 1 in binary 
i.e let x = 3 (decimal) so binary is 011 the value of bits 1 is (1, 2) ,,, so the left child will hold the value 1 and 2 while the right
child hold the value 4 ,,,,, and each node has two varialbes countleft and countright to count how many nodes this parent has and the answer
is the sum of countleft + countright
Complexity -> O(n log(n))
*/

#include<bits/stdc++.h>

using namespace std;

struct Tree
{
    Tree *leftchild, *rightchild;
    int countleft, countright;
    Tree(): leftchild(NULL), rightchild(NULL), countleft(0), countright(0) {}
};

void build(Tree *root, int x, int depth)
{
    if(depth < 0)
        return;
    if((1 << depth) & x)
    {
        root -> countleft++;
        if(root -> leftchild == NULL)
            root -> leftchild = new Tree();
        build(root -> leftchild, x, depth - 1);
    }
    else
    {
        root -> countright++;
        if(root -> rightchild == NULL)
            root -> rightchild = new Tree();
        build(root -> rightchild, x, depth - 1);
    }
}

int get_ans(Tree *root, int x, int depth, int k)
{
    if(depth < 0 || root == NULL)
        return 0;
    if((1 << depth) & k)
    {
        ///cout << "a: " <<" "<< root -> countleft << " " << root -> countright  << " " << ((1 << depth) & x) << endl;
        if((1 << depth) & x)
            return root -> countleft + get_ans(root -> rightchild, x, depth - 1, k);
        return root -> countright + get_ans(root -> leftchild, x, depth - 1, k);
    }
    else
    {
        ///cout << "!a: " << " " << ((1 << depth) & x) << endl;
        if((1 << depth) & x)
            return get_ans(root -> leftchild, x, depth - 1, k);
        return get_ans(root -> rightchild, x, depth - 1, k);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        Tree *root = new Tree();
        build(root, 0, 20);
        long long ans = 0;
        int XOR = 0;
        while(n--)
        {
            int x;
            scanf("%d", &x);
            XOR ^= x;
            ans += get_ans(root, XOR, 20, k);
            build(root, XOR, 20);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
