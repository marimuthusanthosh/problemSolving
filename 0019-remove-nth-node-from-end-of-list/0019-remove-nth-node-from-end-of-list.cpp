class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToRemove = slow->next;
        slow->next = slow->next->next;
        delete nodeToRemove;

        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};


// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if (head->next == nullptr)
//             return nullptr;
//         ListNode * p = head, * q = head;
//         for (int i = 0; i < n; ++i)
//         {
//             p = p->next;
//         }
//         if (p == nullptr)
//         {
//             q = head->next;
//             delete head;
//             return q;
//         }
//         while (p->next != nullptr)
//         {
//             p = p->next;
//             q = q->next;
//         }
//         p = q->next->next;
//         delete q->next;
//         q->next = p;
//         return head;
//     }
// };
