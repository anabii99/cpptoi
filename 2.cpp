#include <iostream>
#include <stack>
#include <memory>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode dummy(0);
        ListNode* next = nullptr;
        int carry = 0;
        
        while (!s1.empty() || !s2.empty() || carry) {
            next = dummy.next;
            
            if (!s1.empty()) {
                carry += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top();
                s2.pop();
            }
            
            dummy.next = new ListNode(carry % 10);
            carry /= 10;
            dummy.next->next = next;
        }
        
        return dummy.next;
    }
};

int main() {
    std::vector<int> vec1 = {2, 4, 3};
    std::vector<int> vec2 = {5, 6, 4};

    auto l1 = to_list(vec1);
    auto l2 = to_list(vec2);

    Solution solution;
    auto result = solution.addTwoNumbers(l1.get(), l2.get());

    // Print the result
    while (result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
