// Heap Approach
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty()) return NULL;
        
        // MAX heap
        priority_queue<pair<int, ListNode*>> pq; 
        int n=lists.size();
        
        for(int i=0;i<n;i++)
        {
            ListNode *p = lists[i];
            while(p)
            {
                pq.push({-p->val, p}); // acts as min heap
                p = p->next;
            }
        }
                
        ListNode* head=NULL;
        ListNode* last=NULL;
        
        if(pq.empty()) return head;
        
        head=pq.top().second;
        last=pq.top().second;
        pq.pop();
        
        
        while(!pq.empty())
        {
            last->next = pq.top().second;
            last = pq.top().second;
            pq.pop();
            
        }
        last->next=NULL;
        
        return head;
        
    }
};


//DNC Approach



// class Solution {
// public:
//     ListNode* merge(ListNode* l1, ListNode* l2){
//         if(!l1)return l2;
//         if(!l2)return l1;
//             if(l1->val<=l2->val){
//                  l1->next=merge(l1->next,l2);
//                 return l1;
//             }
//             else {
//                 l2->next=merge(l1,l2->next);
//                 return l2;
//         }
//         return l1;
//     }
//     ListNode* divide(vector<ListNode*>& lists,int l,int r){
//         if(l>r)return NULL;
//         if(l==r)return lists[l];
//         int mid=l+(r-l)/2;
//         ListNode *left=divide(lists,l,mid);
//         ListNode * right=divide(lists,mid+1,r);
//         lists[l]=merge(left, right);
//         return lists[l];
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size()==0)return nullptr;
//         return divide(lists,0,lists.size()-1);
//     }
// };