// almost directly copied from
// https://leetcode.cn/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode-solution/

#include<stdio.h>
#include<stdbool.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *findCentrality(struct ListNode *head){
    struct ListNode *slow = head;
    struct ListNode *fast = head -> next;
    while (fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

struct ListNode *reverseList(struct ListNode *head){
    struct ListNode *previous = NULL;
    struct ListNode *current = head;

    while (current){
        struct ListNode *succeed = current -> next;
        current -> next = previous;
        previous = current;
        current = succeed;
    }
    return previous;
}

bool isPalindrome(struct ListNode *head){
    struct ListNode *leftEnd = findCentrality(head);
    struct ListNode *rightStart = reverseList(leftEnd -> next);

    struct ListNode *leftCurrent = head;
    struct ListNode *rightCurrent = rightStart;
    bool result = true;
    while (rightCurrent){
        if (leftCurrent -> val != rightCurrent -> val){
            result = false;
            break;
        }
        else{
            leftCurrent = leftCurrent -> next;
            rightCurrent = rightCurrent -> next;
        }
    }

    leftEnd -> next = reverseList(rightStart);
    return result;
}