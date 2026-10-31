/*
QUESTION:- https://leetcode.com/problems/palindrome-linked-list/
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*/

/*
APPROACH:
To determine if a linked list is a palindrome, we can follow these steps:
1. Find the middle node of the linked list using the slow and fast pointer technique.
2. Reverse the second half of the linked list.
3. Compare the first half of the original linked list with the reversed second half.
4. If all nodes match, the linked list is a palindrome.
5. If any node does not match, the linked list is not a palindrome.
*/

// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)


// optimal 

ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    // Step 1: Find the middle of the linked list
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode *newHead = reverseLL(slow->next);

    // Step 3: Compare the two halves
    ListNode *first = head;
    ListNode *second = newHead;
    bool isPal = true;
    while (second != NULL)
    {
        if (first->val != second->val)
        {
            isPal = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    // Step 4: Restore the original list
    slow->next = reverseLL(newHead);

    return isPal;
}
