/*
QUESTION:- https://leetcode.com/problems/sort-list/
Given the head of a linked list, return the list after sorting it in ascending order.

Example:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
**APPROACH:**

To sort a linked list, we use the **Merge Sort algorithm**, which follows the divide-and-conquer technique. We perform the following steps:

1. If the linked list is empty or contains only one node, return the head because it is already sorted.
2. Find the middle node using the slow and fast pointer approach (`findMiddle()`).
3. Store the node after the middle in `right` and disconnect the two halves by setting `middle->next = nullptr`.
4. Store the original head in `left`.
5. Recursively call `sortList()` on both `left` and `right` to sort the two halves.
6. Merge the two sorted halves using `mergeTwoLists()`.
7. Inside `mergeTwoLists()`, compare the values of both lists and attach the smaller node using the `next` pointer.
8. Attach the remaining nodes once either list becomes empty.
9. Return the merged sorted list.
COMPLEXITY ANALYSIS
- Time Complexity: O(N log N) – The list is divided into halves recursively, creating log N levels. Each level takes O(N) time to find the middle and merge the lists.
- Auxiliary Space Complexity: O(log N) – Recursive calls require O(log N) stack space. The merging operation uses O(1) extra space.
*/
// CODE (C++)

ListNode *findMiddle(ListNode *head)
{
    if (head == NULL)
        return NULL;

    ListNode *slow = head;
    ListNode *fast = head->next;

    // Find the middle node
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // Create a dummy node for merging
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    // Merge both sorted lists
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    // Attach the remaining nodes
    if (list1)
        temp->next = list1;
    else
        temp->next = list2;

    ListNode *result = dummyNode->next;

    // Free dummy node
    delete dummyNode;

    return result;
}

ListNode *sortList(ListNode *head)
{
    // Base case: Empty or single node
    if (head == NULL || head->next == NULL)
        return head;

    // Find the middle node
    ListNode *middle = findMiddle(head);

    // Divide the list into two halves
    ListNode *right = middle->next;
    middle->next = nullptr;

    ListNode *left = head;

    // Recursively sort both halves
    left = sortList(left);
    right = sortList(right);

    // Merge the sorted halves
    return mergeTwoLists(left, right);
}
