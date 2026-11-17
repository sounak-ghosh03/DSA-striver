/*Question : https://leetcode.com/problems/merge-two-sorted-lists/
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []

APPROACH:

To merge two sorted linked lists into a single sorted linked list, we use a **two-pointer approach**. We perform the following steps:

1. Initialize two pointers `t1` and `t2` to point to the heads of the two linked lists.
2. Create a dummy node (`dNode`) with value `-1` and use a `temp` pointer to build the merged list.
3. Traverse both lists while `t1` and `t2` are not `NULL`.
4. Compare the values of the nodes pointed to by `t1` and `t2`:
   - If `t1->val < t2->val`, attach the node pointed to by `t1` to the merged list, move `temp` to that node, and advance `t1`.
   - Otherwise, attach the node pointed to by `t2`, move `temp` to that node, and advance `t2`.
5. Once one of the lists becomes empty, attach the remaining nodes of the other list directly to the merged list.
6. Return `dNode->next`, which points to the head of the merged sorted linked list.

COMPLEXITY ANALYSIS

- Time Complexity: O(N + M) – Each node from both linked lists is visited at most once, where N and M are the lengths of the two lists.
- Space Complexity: O(1)– Only a constant number of pointers and one dummy node are used. No additional data structure is required.
*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *t1 = list1;
        ListNode *t2 = list2;
        ListNode *dNode = new ListNode(-1);
        ListNode *temp = dNode;
        while (t1 != NULL && t2 != NULL)
        {
            if (t1->val < t2->val)
            {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if (t1)
            temp->next = t1;
        if (t2)
            temp->next = t2;
        return dNode->next;
    }
};