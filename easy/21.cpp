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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = nullptr;
    ListNode *current = head;
    ListNode *lp = list1;
    ListNode *rp = list2;

    while (lp != nullptr || rp != nullptr) {
      int newValue;
      if (lp == nullptr) {
        newValue = rp->val;
        rp = rp->next;
      } else if (rp == nullptr) {
        newValue = lp->val;
        lp = lp->next;
      } else if (lp->val > rp->val) {
        newValue = rp->val;
        rp = rp->next;
      } else {
        newValue = lp->val;
        lp = lp->next;
      }

      if (head == nullptr) {
        head = new ListNode(newValue);
        current = head;
      } else {
        current->next = new ListNode(newValue);
        current = current->next;
      }
    }

    return head;
  }
};

