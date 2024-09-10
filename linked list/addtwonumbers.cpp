class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummyNode= new ListNode(-1);
        int carry=0;
         ListNode* curr=dummyNode;

        while(temp1!=NULL || temp2!=NULL){
                int sum=carry;
              if(temp1!=NULL){ 
               sum=sum+temp1->val;
               temp1=temp1->next;
               }
                if(temp2!=NULL) {
                    sum=sum+temp2->val;
                    temp2=temp2->next;
                }

              ListNode* newNode=new ListNode(sum%10);
              carry=sum/10;
              curr->next=newNode;
              curr=curr->next;
        }
             // attached the carry to linked list
        if(carry>0){
            ListNode* newNode=new ListNode(carry);
            curr->next=newNode;
        }
         return dummyNode->next;
    }
};