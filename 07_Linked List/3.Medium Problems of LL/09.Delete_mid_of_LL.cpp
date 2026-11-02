/*
QUESTION:- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

Example:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.

OPTIMAL APPROACH:
To delete the middle node of a linked list, we can use the slow and fast pointer technique.

1. If the linked list is empty or contains only one node, return `NULL`.
2. Initialize two pointers, `slow` and `fast`, both pointing to the head.
3. Move the `fast` pointer two steps ahead initially to handle the middle node correctly.
4. Traverse the linked list by moving the `slow` pointer one step at a time and the `fast` pointer two steps at a time until `fast` reaches the end or its next pointer becomes `NULL`.
5. Once the traversal ends, the `slow` pointer will be pointing to the node just before the middle node.
6. Store the next node of `slow` in a temporary pointer `midNode`.
7. Update `slow->next` to `slow->next->next` to skip the middle node.
8. Delete the middle node using the `delete` keyword.
9. Return the original head of the modified linked list.


TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/

ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    fast = fast->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *midNode = slow->next;
    slow->next = slow->next->next;
    delete midNode;
    return head;
}