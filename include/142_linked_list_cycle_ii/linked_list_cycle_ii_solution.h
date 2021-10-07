#include "all_include.h"
#include "ds/listnode.h"

namespace lst {
namespace leet {
class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == head) {
            return head;
        }
        ListNode *fast = head->next;

        ListNode *slow = head;

        while (true) {
            if (fast == nullptr) {
                return nullptr;
            }
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next;

            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next;
            slow = slow->next;
            if (fast == slow) {
                break;
            }
        }

        ListNode *node = slow->next;
        int p = 1;
        while (node != slow) {
            node = node->next;
            p++;
        }
        slow = head;
        fast = head;
        for (int i = 0; i < p; i++) {
            fast = fast->next;
        }
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
}  // namespace leet
}  // namespace lst
