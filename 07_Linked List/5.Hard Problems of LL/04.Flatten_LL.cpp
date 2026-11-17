/**QUESTION:**

Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is the head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

**Example 1:**
Input:
5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22   35
|           |     |
8           50   40
|                 |
9                 45
Output: 5->7->8->9->10->20->22->28->35->40->45->50
Explanation: After flattening the nodes there is one single linked list which has to be printed as such.


### **APPROACH:**

To flatten a linked list, we use a recursive approach and merge the lists from right to left. We perform the following steps:

1. If the root is `NULL` or there is no next list (`root->next == NULL`), return the root.
2. Recursively call `flatten(root->next)` to flatten all the lists on the right side.
3. Store the flattened right-side list in `mergeHead`.
4. Set `root->next = nullptr` to disconnect the current list from the remaining lists.
5. Merge the current list (`root`) with the flattened right-side list (`mergeHead`) using the `merge()` function.
6. Inside `merge()`, compare the `data` of both lists and attach the smaller node using the `bottom` pointer.
7. Continue merging until one list becomes empty, then attach the remaining nodes.
8. Return the merged list as the flattened list.
COMPLEXITY ANALYSIS

- Time Complexity: O(N × K), where N is the average number of nodes in each bottom-linked list and K is the number of linked lists. Each merge traverses the nodes being merged, and there are K−1 merges.
- Auxiliary Space Complexity: O(K) due to the recursive call stack, where K is the number of linked lists. The merge operation itself uses O(1) extra space.
*/

//  CODE (C++)

Node *merge(Node *list1, Node *list2)
{
    // Create a dummy node for merging
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    // Merge both lists in sorted order
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->bottom = list1; // Attach using bottom
            list1 = list1->bottom;
        }
        else
        {
            res->bottom = list2;
            list2 = list2->bottom;
        }

        res = res->bottom;
    }

    // Attach the remaining nodes
    if (list1)
        res->bottom = list1;
    else
        res->bottom = list2;

    Node *flattenedList = dummyNode->bottom;

    // Free dummy node
    delete dummyNode;

    return flattenedList;
}

Node *flatten(Node *root)
{
    // Base case: Empty or single list
    if (root == NULL || root->next == NULL)
        return root;

    // Flatten the remaining lists recursively
    Node *mergeHead = flatten(root->next);

    // Disconnect the next pointer
    root->next = nullptr;

    // Merge current list with flattened list
    root = merge(root, mergeHead);

    return root;
}
