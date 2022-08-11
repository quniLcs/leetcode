struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x){
    int queue[200];
    int tail = 0;

    struct ListNode *current = head;
    struct ListNode *previous = head;

    while (current){
        if (current -> val < x){
            previous -> val = current -> val;
            previous = previous -> next;
        }
        else{
            queue[tail++] = current -> val;
        }
        current = current -> next;
    }

    for (int index = 0; index < tail; index++){
        previous -> val = queue[index];
        previous = previous -> next;
    }

    return head;
}