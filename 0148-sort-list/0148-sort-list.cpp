class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        int n = 0;
        ListNode* curr = head;

        while (curr) {
            n++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        for (int size = 1; size < n; size *= 2) {
            ListNode* prev = &dummy;
            curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);

                prev->next = merge(left, right);

                while (prev->next)
                    prev = prev->next;
            }
        }

        return dummy.next;
    }

private:
    ListNode* split(ListNode* head, int size) {
        while (--size && head)
            head = head->next;

        if (!head) return nullptr;

        ListNode* second = head->next;
        head->next = nullptr;

        return second;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};