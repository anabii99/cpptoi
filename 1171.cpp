#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeZeroSumSublists(ListNode *head) {
    // Move list values into a vector
    vector<int> list;
    for (ListNode *node = head; node != nullptr; node = node->next) {
        list.push_back(node->val);
    }

    // Remove zero-sum sequences from the vector
    int start = 0;
    while (start < list.size()) {
        int prefix = 0;
        int end = start;
        while (end < list.size()) {
            prefix += list[end];
            if (prefix == 0) {
                list.erase(list.begin() + start, list.begin() + end + 1);
                start--;
                break;
            }
            end++;
        }
        start++;
    }

    // Create a new list
    ListNode *newHead = new ListNode(0);
    ListNode *n = newHead;
    for (int val : list) {
        n->next = new ListNode(val);
        n = n->next;
    }
    n->next = nullptr;
    return newHead->next;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(-3);
    head->next->next->next->next = new ListNode(4);

    ListNode *result = removeZeroSumSublists(head);
    for (ListNode *node = result; node != nullptr; node = node->next) {
        cout << node->val << " ";
    }
    cout << endl;

    return 0;
}
