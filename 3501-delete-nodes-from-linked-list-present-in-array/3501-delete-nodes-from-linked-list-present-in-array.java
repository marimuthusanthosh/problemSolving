/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> set=new HashSet<>();
        for(int i:nums){
            set.add(i);
        }
        while(set.contains(head.val)){
            head=head.next;
        }
        ListNode temp=head,prev=head;
        while(temp!=null){
            if(set.contains(temp.val)){
                prev.next=temp.next;
            }else{
                prev=temp;
            }
            temp=temp.next;
        }
        return head;
    }
}