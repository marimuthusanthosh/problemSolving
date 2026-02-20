/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
     {
        if (head == nullptr || head->next == nullptr) {
            return false; // Empty list or single node, no cycle
        }

        ListNode *temp = head;
        ListNode *temp1 = head->next;

        while (temp1&&temp1->next) {
            if (temp == temp1) {
                return true; // Cycle detected
            }
            temp = temp->next; // Move temp pointer by one step
            temp1 = temp1->next->next; // Move temp1 pointer by two steps
        }

        return false; // No cycle found
      
          
     }
};