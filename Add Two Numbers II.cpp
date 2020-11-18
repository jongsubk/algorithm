//https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3522/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1=0, s2=0;
        ListNode* temp;
        vector<int> v1, v2;
        temp = l1;
        while(temp) {
            s1++;
            v1.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = l2;
        while(temp) {
            s2++;
            v2.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* result = NULL;
        int val=0;
        int up=0;
        while( s1 || s2 ) {
            if( s1 && s2 ) {
                val = v1[s1-1] + v2[s2-1];
                if( up ) { val++; up = 0; }
                
            }else if( s1 && s2==0 ) {
                val = v1[s1-1];
                if( up ) { val++; up = 0; }
                    
            }else if( s1==0 && s2) {
                val = v2[s2-1];
                if( up ) { val++; up = 0; }
                
            }
            
            if( val > 9) {
                val -= 10;
                up = 1;
            }
            result = new ListNode( val, result );
            
            if( s1) s1--;
            if( s2) s2--;
        }
        
        if( up )
            result = new ListNode( 1, result );
            
        
        return result;

    }
};
