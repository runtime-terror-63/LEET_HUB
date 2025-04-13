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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL ) return NULL;
        if(head->next==NULL && n==1) return NULL;
          int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }

        if(cnt==n){
           ListNode* curr = head->next;
           delete(head);
           return curr;
        }
        int res = cnt - n;
        temp = head;
        int res1 = 0;
        while(temp!=NULL){
                res1 ++;
                if(res1==res){
                ListNode* deleNode = temp->next;
                temp->next = temp->next->next;
                delete(deleNode);
            }
            temp = temp->next;
        }
        return head;
    }
};