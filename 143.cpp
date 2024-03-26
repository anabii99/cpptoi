#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::unique_ptr<ListNode> to_list(std::vector<int> &vec) {
    ListNode *current = nullptr;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        ListNode *node = new ListNode(*it);
        node->next = current;
        current = node;
    }
    return std::unique_ptr<ListNode>(current);
}

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        // Find the middle node using the two-pointer technique
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Merge the two lists
        ListNode *first = head;
        ListNode *second = prev;
        while (second) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto head = to_list(vec);

    Solution solution;
    solution.reorderList(head.get());

    // Print the reordered linked list
    ListNode *current = head.get();
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
