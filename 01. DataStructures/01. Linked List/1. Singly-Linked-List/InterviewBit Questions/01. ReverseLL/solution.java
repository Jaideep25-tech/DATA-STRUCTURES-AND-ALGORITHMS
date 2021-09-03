public class Solution {
    public ListNode reverseList(ListNode A) {
        ListNode curr=A;
        ListNode previous=null;
        ListNode nex=null;
        while(curr!=null) {
            nex=curr.next;
            curr.next=previous;
            previous=curr;
            curr=nex;
        }
        return previous;
    }
}
