class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len=0;
        ListNode* temp=head;
        ListNode* current=head;
        ListNode* prev=nullptr;
        while(current){
            len++;
            current=current->next;
        }
        
        if(head==NULL || head->next==NULL) return NULL;
        if(n==len) return head->next;
        
        
         while(len>n){
            prev=temp;
            temp=temp->next;
             len--;
         }
       
        prev->next= temp->next;
        temp->next=NULL;
        delete temp;

        return head;

        
    }
};