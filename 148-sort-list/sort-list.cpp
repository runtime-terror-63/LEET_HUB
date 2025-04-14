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

ListNode* getMiddle(ListNode* head){

  if(head == NULL  || head->next==NULL) return head;
  ListNode* slow = head;
  ListNode* first = head->next;
  while(first && first->next){
    slow = slow->next;
    first = first->next->next;
  }
  return slow;
}

ListNode* merge(ListNode* left, ListNode* right){
    if(!left) return right;
    if(!right) return left;
  ListNode* dummy = new ListNode(-1);
  ListNode* tail = dummy;

  while(left && right){
    if(left->val<=right->val){
      tail->next = left;
      left = left->next;
    }else {
      tail->next = right;
      right = right->next;
    }
    tail = tail->next;
  }

  if(left) tail->next = left;
  if(right) tail->next = right;
  return dummy->next;
}
    ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head; 

  ListNode* mid = getMiddle(head);
  ListNode* right = mid->next;
  mid->next = NULL;
  ListNode* left = head;

  left = sortList(left);
  right = sortList(right);

  return merge(left, right);
    }
};