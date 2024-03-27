#include <iostream>
#include <memory>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> to_vector(TreeNode *root) {
    std::vector<int> result;
    if (!root)
        return result;

    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1); // Placeholder for null node
        }
    }

    // Remove trailing null nodes
    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }

    return result;
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr)
            return {};

        vector<TreeNode *> path;
        vector<string> res;
        dfs(root, path, res);
        return res;
    }

private:
    void dfs(TreeNode *node, vector<TreeNode *> &path, vector<string> &res) {
        path.push_back(node);
        if (node->left == nullptr && node->right == nullptr) {
            string str = to_string(path[0]->val);
            for (int i = 1; i < path.size(); i++)
                str += "->" + to_string(path[i]->val);
            res.push_back(str);
        }

        if (node->left)
            dfs(node->left, path, res);
        if (node->right)
            dfs(node->right, path, res);

        path.pop_back();
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);

    for (const auto &path : result) {
        cout << path << endl;
    }

    return 0;
}
