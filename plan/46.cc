#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path1, path2;
        if (root == nullptr)
            return nullptr;

        if (!getPath(root, p->val, path1) || !getPath(root, q->val, path2))
            return nullptr;

        int s = min(path1.size(), path2.size());
        TreeNode *result = nullptr;
        for (int i = 0; i < s; i++)
        {
            if (path1[i]->val == path2[i]->val)
            {
                result = path1[i];
            }
            else
            {
                break;
            }
        }
        return result;
    }

  private:
    bool getPath(TreeNode *root, int val, vector<TreeNode *> &result)
    {
        if (root == nullptr)
            return false;

        while (root != nullptr)
        {
            result.push_back(root);
            if (root->val == val)
            {
                return true;
            }
            else if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }

        return false;
    }
};

int main()
{
    return 0;
}