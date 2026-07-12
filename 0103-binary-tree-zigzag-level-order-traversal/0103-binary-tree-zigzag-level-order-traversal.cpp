/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();

            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i;
                level[index] = current->val;

                if (current->left)
                    q.push(current->left);

                if (current->right)
                    q.push(current->right);
            }

            ans.push_back(level);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};