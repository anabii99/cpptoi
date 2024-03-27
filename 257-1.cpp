#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <memory>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::unique_ptr<TreeNode> to_binary_tree(std::vector<int>& vec) {
    if (vec.empty()) return nullptr;

    std::queue<TreeNode*> q;
    auto root = std::make_unique<TreeNode>(vec[0]);
    q.push(root.get());

    size_t i = 1;
    while (i < vec.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (vec[i] != -1) {
            current->left = new TreeNode(vec[i]);
            q.push(current->left);
        }
        ++i;

        // Right child
        if (i < vec.size() && vec[i] != -1) {
            current->right = new TreeNode(vec[i]);
            q.push(current->right);
        }
        ++i;
    }

    return root;
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};

        vector<TreeNode*> path;
        vector<string> res;
        dfs(root, path, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<TreeNode*>& path, vector<string>& res) {
        path.push_back(node);
        if (node->left == nullptr && node->right == nullptr) {
            string str = to_string(path[0]->val);
            for (int i = 1; i < path.size(); i++)
                str += "->" + to_string(path[i]->val);
            res.push_back(str);
        }

        if (node->left) dfs(node->left, path, res);
        if (node->right) dfs(node->right, path, res);

        path.pop_back();
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, -1, 5};

    Solution solution;
    auto root = to_binary_tree(vec).release();
    vector<string> result = solution.binaryTreePaths(root);

    for (const auto& path : result) {
        cout << path << endl;
    }

    return 0;
}

