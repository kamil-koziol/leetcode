using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if(head == nullptr) {return head;}
      ListNode* current = head;
      ListNode* result = nullptr;
       
      while(current != nullptr) {
        result = new ListNode(current->val, result);
        current = current->next;
      }

      return result;
    }
};
