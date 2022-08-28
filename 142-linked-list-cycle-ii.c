// almost directly copied from
// https://leetcode.cn/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/

#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head){
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    do{
        if (fast == NULL || fast -> next == NULL) return NULL;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    while (slow != fast);

    struct ListNode *ans = head;
    while (ans != slow) {
        ans = ans -> next;
        slow = slow -> next;
    }
    return ans; 
}