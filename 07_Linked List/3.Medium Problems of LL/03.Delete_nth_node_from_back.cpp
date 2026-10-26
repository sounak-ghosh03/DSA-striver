/*
QUESTION:- https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

/*
APPROACH:
To remove the nth node from the end of the linked list, we can follow these steps:
1. Initialize two pointers, `fast` and `slow`, to the head of the linked list.
2. Move the `slow` pointer n nodes ahead.
3. If `slow` becomes NULL, it means the first node needs to be removed. Return head->next.
4. Iterate until `slow->next` becomes NULL.
5. Move both `fast` and `slow` pointers one node ahead in each iteration.
6. Once `slow->next` becomes NULL, `fast` will be pointing to the (n-1)th node from the end.
7. Update `fast->next` to skip the nth node from the end.
8. Return the head of the modified linked list.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;

    // Move the right pointer n nodes ahead
    for (int i = 0; i < n; i++)
        fast = fast->next;
    // If right becomes NULL, remove the first node
    if (fast == NULL)
        return head->next;

    // Iterate until right->next becomes NULL
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // Update left->next to skip the nth node from the end
    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}