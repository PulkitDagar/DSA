class Solution {
public:
    ListNode* findMid(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow!=NULL && fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    };

      ListNode* merge(ListNode* left, ListNode* right) {
        if(left==0) return right;
        if(right==0) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(left && right){
            if(left->val <= right->val){
                mptr->next = left;
                mptr = left;
                left = left->next;
            }
            else{
                mptr->next = right;
                mptr = right;
                right = right->next;
            }
        }

        if(left){
            mptr->next = left;

        }

        
        if(right){
            mptr->next = right;
            // mptr = right;
            // right = right->next;
        }
        return ans->next;
    }


    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next ==0){
            return head;
        }

        //break linked list into two halves using mid nodes
        ListNode* mid = findMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = 0;

        //sort recursively
        left = sortList(left);
        right = sortList(right);

        ListNode* mergeLL = merge(left,right);
        return mergeLL;
    }
};