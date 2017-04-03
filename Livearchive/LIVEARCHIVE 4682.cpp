/*
The idea is pretty simple :
use binary tree (trie) with depth 31 (cuz i have 32 bits form 0 to 31) each left child has the value of bit which appers 1 in binary 
i.e let x = 3 (decimal) so binary is 011 the value of bits 1 is (1, 2) ,,, so the left child will hold the value 1 and 2 while the right
child hold the value 4 ,,,,, and then get the sum of values which appers 1 and maxmize the answer
Complexity -> O(n log(n))
*/

#include<bits/stdc++.h>

using namespace std;

struct Tree
{
    Tree *leftchild, *rightchild;
    Tree(): leftchild(NULL), rightchild(NULL) {}
};

void build(Tree *root, int x, int depth)
{
    if(depth < 0)
        return;
    if((1 << depth) & x)
    {
        if(root -> leftchild == NULL)
            root -> leftchild = new Tree();
        build(root -> leftchild, x, depth - 1);
    }
    else
    {
        if(root -> rightchild == NULL)
            root -> rightchild = new Tree();
        build(root -> rightchild, x, depth - 1);
    }
}

int get_ans(Tree *root, int x, int depth)
{
    if(depth < 0)
        return 0;
    if(((1 << depth) & x ) == 0)
    {
       // cout << "Left: " <<(1 << depth) << endl;
        if(root -> leftchild != NULL)
            return (1 << depth) + get_ans(root -> leftchild, x, depth - 1);
        return get_ans(root -> rightchild, x, depth - 1);
    }
    else
    {
       // cout << "Right: " <<(1 << depth) << endl;
        if(root -> rightchild != NULL)
            return (1 << depth) + get_ans(root -> rightchild, x, depth - 1);
        return get_ans(root -> leftchild, x, depth - 1);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int n;
        scanf("%d", &n);
        Tree *root = new Tree();
        build(root, 0, 31);
        int ans = 0, XOR = 0;
        while(n--)
        {
            int x;
            scanf("%d", &x);
            XOR ^= x;
            ans = max(ans, get_ans(root, XOR, 31));
            ans = max(ans, x);
            build(root, XOR, 31);
        }
        printf("%d\n", ans);
    }
    return 0;
}
