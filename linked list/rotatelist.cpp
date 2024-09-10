class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;

       int len=1;
       ListNode* tail=head;
       while(tail->next){
        // condition indicate until tail is not reaches to last position tail ko aage badhao
         tail=tail->next;
         len++;
       }

       int c=1;
       k=k%len;
       ListNode* curr=head;

       while(c<len-k){
        curr=curr->next;
        c++;
       }
       tail->next=head;
       head=curr->next;
       curr->next=NULL;

       return head;
        
    }
};