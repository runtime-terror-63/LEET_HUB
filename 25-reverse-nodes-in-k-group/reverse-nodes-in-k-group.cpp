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

int getLength(ListNode* head){
  int cnt = 0;
  while(head){
    cnt++;
    head = head->next;
  }
  return cnt;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
 if(head==NULL || k==1) return head;

  int len = getLength(head);
  ListNode* dummy = new ListNode(0);
  dummy->next = head;

  ListNode* prevGround = dummy;
  while(len>=k){
    ListNode* curr = prevGround->next;
    ListNode* next = curr->next;

    for(int i=1; i<k; i++){
      curr->next = next->next;
      next->next = prevGround->next;
      prevGround->next = next;
      next = curr->next;
    }

    prevGround = curr;
    len -= k;
  }
  return dummy->next;
    }
};