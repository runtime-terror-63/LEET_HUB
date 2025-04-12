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
    ListNode* removeElements(ListNode* head, int ele) {
  if(head==NULL) return head;
  while(head && head->val==ele){
    ListNode* temp = head;
    head = head->next;
    delete(temp);
  }
  ListNode* temp = head;
  while(temp && temp->next){
    if(temp->next->val==ele){
      temp->next = temp->next->next;
    }else
    temp = temp->next;
  }
  return head;
    }
};