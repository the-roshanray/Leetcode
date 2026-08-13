class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode* current = head;
        ListNode* beforeLeft = nullptr;

        // Move to the left position
        for (int i = 1; i < left; i++) {
            beforeLeft = current;
            current = current->next;
        }

        ListNode* leftNode = current;

        // Reverse the sublist
        ListNode* prev = nullptr;
        ListNode* second = nullptr;

        for (int i = 0; i <= right - left; i++) {
            second = current->next;
            current->next = prev;
            prev = current;
            current = second;
        }

        // Reconnect
        if (beforeLeft)
            beforeLeft->next = prev;
        else
            head = prev;

        leftNode->next = current;

        return head;
    }
};