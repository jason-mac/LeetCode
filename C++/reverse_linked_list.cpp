// LeetCode 206. Reverse Linked List

// recuersive approach
// O(n) time and space complexity
class Solution_One {
public:
  void rec(ListNode *current, ListNode *trail, ListNode *&newHead) {
    if (!current) {
      newHead = trail;
      return;
    }
    rec(current->next, current, newHead);
    current->next = trail;
  }
  ListNode *reverseList(ListNode *head) {
    rec(head, nullptr, head);
    return head;
  }
}

// iterative apporach
// O(n) time complexity, O(1) space complexity
class Solution_Two {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head)
      return nullptr;
    if (!head->next)
      return head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *ahead = head->next;
    while (curr) {
      curr->next = prev;
      prev = curr;
      curr = ahead;
      ahead = ahead->next;
    }
    curr->next = prev;
    return curr;
  }
}
