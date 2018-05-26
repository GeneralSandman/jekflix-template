#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>

#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int count = 0;

        int leftHeight = 0;
        int rightHeight = 0;

        TreeNode *l = root->left;
        TreeNode *r = root->right;

        while (l != nullptr)
        {
            l = l->left;
            leftHeight++;
        }

        while (r != nullptr)
        {
            r = r->right;
            rightHeight++;
        }

        if (leftHeight == rightHeight)
        {
            return pow(2, leftHeight + 1) - 1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

int main()
{
    return 0;
}
