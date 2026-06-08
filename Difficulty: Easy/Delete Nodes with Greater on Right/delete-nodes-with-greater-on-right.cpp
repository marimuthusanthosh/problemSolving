class Solution {
  public:

    Node* reverse(Node* head){

        Node* prev = NULL;
        Node* curr = head;

        while(curr){

            Node* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    Node *compute(Node *head) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        head = reverse(head);

        int maxi = head->data;

        Node* curr = head;

        while(curr && curr->next){

            if(curr->next->data < maxi){

                curr->next = curr->next->next;
            }
            else{

                curr = curr->next;
                maxi = max(maxi, curr->data);
            }
        }

        head = reverse(head);

        return head;
    }
};