class Solution {
private:
    Node* dfs(Node* head) {
        Node* curr = head;
        Node* last = nullptr;

        while (curr) {
            Node* next = curr->next;

            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                last = childTail;
                curr = childTail;
            } else {
                last = curr;
            }

            curr = curr->next;
        }

        return last;
    }

public:
    Node* flatten(Node* head) {
        if (!head) return head;
        dfs(head);
        return head;
    }
};