struct ListNode{
    int val;
    struct ListNode *next;
};


// brutal force original code
struct ListNode *removeNthFromEnd(struct ListNode *head, int n){
    int length = 0;
    struct ListNode *current = head;

    while (current){
        current = current -> next;
        length++;
    }

    if (n == length){
        return head -> next;
    }
    else{
        int target = length - n;
        current = head;
        for (int index = 0; index < target - 1; index++){
            current = current -> next;
        }
        current -> next = current -> next -> next;
        return head;
    }
}

// double pointer and dummy node with reference to
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
struct ListNode *removeNthFromEnd(struct ListNode *head, int n){
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode* first = head;
    struct ListNode* second = dummy;

    for (int i = 0; i < n; i++){
        first = first -> next;
    }
    while (first){
        first = first -> next;
        second = second -> next;
    }
    second -> next = second -> next -> next;

    struct ListNode *ans = dummy -> next;
    free(dummy);
    return ans;
}