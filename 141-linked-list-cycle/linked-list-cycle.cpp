/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
          if(head == NULL || head->next == NULL) return false;
          /*

            ListNode* first = head;
            ListNode* slow =  head;
            while(first != NULL && first->next != NULL){
                first = first->next->next;
                slow = slow->next;

                if(first == slow) return true;
            }
            return false;  */

        unordered_set<ListNode*>st;
        ListNode* temp = head;
        while(temp!=NULL){
            if(st.find(temp) !=st.end()) return true;

            st.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};