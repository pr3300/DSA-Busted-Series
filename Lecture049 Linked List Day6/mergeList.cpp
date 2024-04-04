// this is the leetcode solution
class Solution {
public:

    void insertattail(ListNode*&head, int data){
        ListNode*q=new ListNode();
        q->val=data;
        q->next=NULL;
        ListNode*p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=q;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*p=list1;
        ListNode*q=list2;
        if(p==NULL){
            return q;
        }
        if(q==NULL){
            return p;
        }
        ListNode*ans=new ListNode();
        ans->val=-1;
        ans->next=NULL;
        while(p!=NULL || q!=NULL){
             if(p==NULL){
               insertattail(ans,q->val);
                q=q->next;
                continue;
                
            }
            if(q==NULL){
               insertattail(ans,p->val);
                p=p->next;
                continue;
            }
           
            if((q->val)<(p->val)){
               insertattail(ans,q->val);
                q=q->next;
                continue;

            }
             if((q->val)>(p->val)){
                insertattail(ans,p->val);
                p=p->next;
                continue;
                
            }
            if((q->val)==(p->val)){
                insertattail(ans,p->val);
                p=p->next;
                insertattail(ans,q->val);
                q=q->next;

            }

        }
        
        return ans->next;

    
    }
};

