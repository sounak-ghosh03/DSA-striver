/*
QUESTION:- https://leetcode.com/problems/add-two-numbers/description/
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

APPROACH:
Traverse both linked lists simultaneously, starting from the heads.
At each step, add the corresponding digits from both linked lists along with the carry (initialized as 0).
Create a new node with the sum%10 and update the carry as sum/10.
Move to the next nodes in both linked lists.
Continue this process until both linked lists are traversed completely and there is no carry left.
If one linked list is shorter than the other, consider its remaining digits as 0.
If there is still a remaining carry, create a new node with the carry and append it to the result linked list.
Return the head of the result linked list.

TIME COMPLEXITY: O(max(N, M)), where N and M are the lengths of the two input linked lists.
SPACE COMPLEXITY: O(max(N, M)), as the length of the result linked list can be at most max(N, M)+1.

*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *t1 = l1;
    ListNode *t2 = l2;
    ListNode *dummyNode = new ListNode(1); // Dummy node to simplify the logic
    ListNode *curr = dummyNode;
    int carry = 0;
    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry; // Add the carry from the previous step
        if (t1)
            sum += t1->val;
        if (t2)
            sum += t2->val;

        ListNode *newNode = new ListNode(sum % 10); // Create a new node with the current digit
        carry = sum / 10;                           // Update the carry for the next step

        curr->next = newNode;
        curr = curr->next; // Move to the next node in the result linked list

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }

    if (carry)
    {
        ListNode *newNode = new ListNode(carry);
        curr->next = newNode; // Append the remaining carry as a new node
    }
    return dummyNode->next; // Return the head of the result linked list (excluding the dummy node)
}