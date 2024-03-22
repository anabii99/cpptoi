
#include <iostream>
#include <vector>
#include <stack>
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
    ListNode* reverseList(ListNode* head) {
        stack<int> s;
        ListNode* p = head;
        while(p != NULL) {
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while(p != NULL) {
            p->val = s.top();
            s.pop();
            p = p->next;
        }
        return head;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    auto head = to_list(vec);

    Solution solution;
    auto reversedHead = solution.reverseList(head.get());

    // Print the reversed linked list
    while (reversedHead) {
        std::cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }
    std::cout << std::endl;

    return 0;
}
