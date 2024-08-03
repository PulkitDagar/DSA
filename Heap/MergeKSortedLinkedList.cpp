//leetcode 23
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //create a priority queue
        priority_queue<ListNode*, vector<ListNode*>, compare >minHeap;

        int k = lists.size();
        if(k==0){
            return NULL;
        }

        //first element of every linked list ko insert krdo heap k ander
        for(int i=0; i<k; i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        };

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(head==NULL){
                //temp NULL pda hai abhi
                head = temp;
                tail = temp;
                if(tail->next !=NULL){
                    minHeap.push(tail->next);
                }
            }
            else{
                //temp is not the first element of linked list
                tail->next = temp;
                tail = temp;
                if(tail->next !=NULL){
                    minHeap.push(tail->next);
                }
            }
        }
        return head;

    }
};