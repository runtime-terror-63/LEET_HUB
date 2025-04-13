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
    ListNode* middleNode(ListNode* head) {
          if(head==NULL || head->next==NULL) return head;
            ListNode* temp = head;
            int cnt = 0;
            while(temp!=NULL){
                cnt++;
                temp = temp->next;
            }

            int middle = (cnt/2)+1;
            temp = head;
            

            for(int i=0; i<middle-1; i++){
                temp = temp->next;
            }
            return temp;
    }
};