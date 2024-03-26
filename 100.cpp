#include <iostream>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::unique_ptr<TreeNode> to_binary_tree(std::vector<int> &vec) {
    if (vec.empty())
        return nullptr;

    std::queue<TreeNode *> q;
    auto root = std::make_unique<TreeNode>(vec[0]);
    q.push(root.get());

    size_t i = 1;
    while (i < vec.size()) {
        TreeNode *current = q.front();
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ((p == nullptr) && (q == nullptr))
            return true;
        if ((p == nullptr) || (q == nullptr))
            return false;
        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {1, 2, 3};

    auto p = to_binary_tree(vec1).release();
    auto q = to_binary_tree(vec2).release();

    Solution solution;
    bool result = solution.isSameTree(p, q);
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}
