#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::unique_ptr<ListNode> to_list(std::vector<int>& vec) {
    ListNode* current = nullptr;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        ListNode* node = new ListNode(*it);
        node->next = current;
        current = node;
    }
    return std::unique_ptr<ListNode>(current);
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; ++i) { 
            fast = fast->next;
        }

        if (!fast) return slow->next;

        while (fast->next) { 
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto head = to_list(vec);

    Solution solution;
    int n = 2; // Example value of n
    auto result = solution.removeNthFromEnd(head.get(), n);

    // Print the result
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
