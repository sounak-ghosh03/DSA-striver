/*
QUESTION:- https://leetcode.com/problems/rotate-list/
Given the head of a linked list, rotate the list to the right by k places.

APPROACH:
To rotate the linked list to the right by `k` places, we need to perform the following steps:
1. If the linked list is empty or `k == 0`, return the original head.
2. Find the length of the linked list and reach the last node (`tail`).
3. If `k % len == 0`, no rotation is required, so return the original head.
4. Update `k = k % len` to get the actual number of rotations.
5. Connect the last node to the head to form a circular linked list.
6. Find the `(len - k)`th node using the `findNthNode()` function. This node becomes the new tail.
7. Set the next node of the new tail as the new head.
8. Disconnect the circular link by setting `newLastNode->next = NULL` and return the new head.

COMPLEXITY ANALYSIS

- Time Complexity: O(N) – Finding the length takes O(N), and finding the new tail takes O(N) in the worst case.
- Space Complexity: O(1) – Only a constant number of pointer variables are used; no extra data structure is required.
*/

// CODE (C++)

ListNode *findNthNode(ListNode *temp, int k)
{
    int cnt = 1;

    // Traverse to the kth node
    while (temp != NULL && cnt < k)
    {
        cnt++;
        temp = temp->next;
    }

    return temp;
}

ListNode *rotateRight(ListNode *head, int k)
{
    // Handle empty list or zero rotations
    if (head == NULL || k == 0)
        return head;

    int len = 1;
    ListNode *tail = head;

    // Find the length and last node
    while (tail->next != NULL)
    {
        len++;
        tail = tail->next;
    }

    // No rotation needed
    if (k % len == 0)
        return head;

    // Calculate effective rotations
    k = k % len;

    // Make the linked list circular
    tail->next = head;

    // Find the new tail
    ListNode *newLastNode = findNthNode(head, len - k);

    // Update the new head
    head = newLastNode->next;

    // Break the circular link
    newLastNode->next = NULL;

    return head;
}
