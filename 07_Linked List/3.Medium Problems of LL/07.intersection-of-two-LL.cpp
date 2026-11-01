/*
QUESTION: https://leetcode.com/problems/intersection-of-two-linked-lists/
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

Optimal Approach (Two Pointers):

1. Initialize two pointers `t1` and `t2` at the heads of both linked lists.
2. Move both pointers one step at a time.
3. When `t1` reaches `NULL`, redirect it to `headB`.
4. When `t2` reaches `NULL`, redirect it to `headA`.
5. If both pointers meet, return the intersection node. If both reach `NULL`, there is no intersection.

- Time Complexity: (O(N+M))
- Space Complexity: (O(1))
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;

    ListNode *t1 = headA;
    ListNode *t2 = headB;
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
            return t1;

        if (t1 == NULL)
        {
            t1 = headB;
        }
        if (t2 == NULL)
        {
            t2 = headA;
        }
    }
    return t1;
}