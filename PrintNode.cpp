class Printer {
public:
    std::unique_ptr<ListNode> to_list(std::vector<int> &vec) {
        ListNode *current = nullptr;
        for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
            ListNode *node = new ListNode(*it);
            node->next = current;
            current = node;
        }
        return std::unique_ptr<ListNode>(current);
    }
};
