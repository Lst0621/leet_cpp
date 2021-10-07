#include <glog/logging.h>
#include "gtest/gtest.h"

#include "142_linked_list_cycle_ii/linked_list_cycle_ii_solution.h"
#include "ds/listnode.h"
#include "memory_record.h"

using namespace lst::leet;

ListNode* create_loop_list(const vector<int>& nodes, int pos) {
    auto head = ListNode::vector_to_list_node(nodes);
    if (pos == -1) {
        return head;
    }
    ListNode::get_last_node(head)->next = ListNode::get_ith_node(head, pos);
    return head;
}

TEST(LinkedListCycleIITest, LeetTest) {
    Solution s;
    ListNode* head = create_loop_list({3, 2, 0, -4, 5, 10}, 3);
    ListNode* expected = ListNode::get_ith_node(head, 3);
    ListNode* actual = s.detectCycle(head);
    EXPECT_EQ(expected, actual);
}

int main(int argc, char** argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
