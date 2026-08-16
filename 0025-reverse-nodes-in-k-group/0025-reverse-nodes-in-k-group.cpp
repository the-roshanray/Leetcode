class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)
            return head;

        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;
        while (count >= k) {
            ListNode* first = prevGroup->next;
            ListNode* second = first->next;
            for (int i = 1; i < k; i++) {
                first->next = second->next;
                second->next = prevGroup->next;
                prevGroup->next = second;
                second = first->next;
            }
            prevGroup = first;
            count -= k;
        }
        return dummy.next;
    }
};