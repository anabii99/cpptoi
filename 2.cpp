#include <iostream>
#include <stack>
#include <memory>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
        ListNode* node = new ListNode();
        ListNode* tmp = node;
        int carry = 0;
    
        while (l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int n = (n1 + n2) + carry;
            int digit = n % 10;
            
            tmp->val = digit;
            carry = n / 10;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            
            if (l1 || l2 || carry) {
                tmp->next = new ListNode();
                tmp = tmp->next;
            }
        }
        
        return node;
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
