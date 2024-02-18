// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//      ListNode* l3=new ListNode();
//         int carry =0;
//         ListNode *temp3=l3;
//         while(l1 || l2 || carry>0){
//             int sum=0;
//             if(l1){
//             sum+=l1->val;
//                 l1=l1->next;
//             }
//             if(l2){
//                 sum+=l2->val;
//                 l2=l2->next;
//             }
//             sum+=carry;
//             carry=sum/10;
//             sum=sum%10;
//             ListNode* temp=new ListNode(sum);
//             temp3->next=temp;
//             temp3=temp3->next;
            
//         }
     
//         return l3->next;
//     }
// };



class Solution
{
public:
    void helper(ListNode *&l1, ListNode *&l2, int carry)
    {
        if (!l1 && !l2)
        {
            if (carry > 0)
            {
                l1 = new ListNode(carry);
            }
            return;
        }

        if (!l1)
        {
            std::swap(l1, l2); /* swap tails of the two lists */
        }

        int value = l1->val + (l2 ? l2->val : 0) /*beware*/ + carry;
        int d0 = value % 10;
        int d1 = value / 10;
        l1->val = d0;

        return helper(l1->next, l2 ? l2->next : l2 /*stay still when l2 is null*/, d1);
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        helper(l1, l2, 0);
        return l1;
    }
};