#pragma once
#include "all_include.h"
#include "memory_record.h"
namespace lst {
namespace leet {
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {
    }
    static ListNode* get_list_node(int x) {
        ListNode* const ret = new ListNode(x);
        Pool<ListNode>::add(ret);
        return ret;
    }
    static ListNode* vector_to_list_node(const vector<int>& nodes) {
        int len = nodes.size();
        if (len == 0) {
            return 0;
        }
        ListNode* const ret = get_list_node(nodes.front());
        ListNode* prev = ret;
        for (int i = 1; i < len; i++) {
            ListNode* node = get_list_node(nodes.at(i));
            prev->next = node;
            prev = node;
        }
        return ret;
    }
    static ListNode* get_ith_node(ListNode* node, int i) {
        while (i) {
            node = node->next;
            i--;
        }
        return node;
    }
    static ListNode* get_last_node(ListNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        while (node->next != nullptr) {
            node = node->next;
        }
        return node;
    }
};
}  // namespace leet
}  // namespace lst
