/*
QUESTION:- https://leetcode.com/problems/middle-of-the-linked-list/
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

// BRUTE FORCE:-(using temp pointer)
ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    int midNode = (cnt / 2) + 1;
    temp = head;
    while (temp != NULL)
    {
        midNode = midNode - 1;
        if (midNode == 0)
            break;
        temp = temp->next;
    }
    return temp;
}
/*
OPTIMAL APPROACH:(TORTOISE & HARE)
-> To find the middle node of a linked list, we can use the two-pointer technique.
-> Initialize two pointers, slow and fast, to the head of the linked list.
-> Move the slow pointer one step at a time and the fast pointer two steps at a time.
-> When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
-> If the total number of nodes in the list is even, there will be two middle nodes, and the slow pointer will be at the first middle node.
-> To return the second middle node, we need to move the slow pointer one more step.
-> Finally, return the node pointed to by the slow pointer.

 TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/

// CODE:-

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}