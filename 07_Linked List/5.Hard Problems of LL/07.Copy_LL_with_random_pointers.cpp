/*
QUESTION: https://leetcode.com/problems/copy-list-with-random-pointer/
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
APPROACH:

To create a deep copy of a linked list with random pointers, we use the **Three-Pass Approach (Inserting copied nodes in between)**. We perform the following steps:

1. Traverse the original linked list and create a copy of each node with the same value.
2. Insert each copied node immediately after its corresponding original node using the `next` pointer.
3. Traverse the modified list again and set the random pointer of each copied node:
   - If the original node has a random pointer, set `copyNode->random = temp->random->next`.
   - Otherwise, set the copied node's random pointer to `nullptr`.
   4. Separate the original and copied linked lists using the `getDeepCopyList()` function.
   5. Restore the original list by updating its `next` pointers and connect the copied nodes to form the new list.
   6. Return the head of the copied linked list.
   COMPLEXITY ANALYSIS

   - Time Complexity: O(N) – We traverse the linked list three times: once to create copied nodes, once to assign random pointers, and once to separate the two lists.
   - Auxiliary Space Complexity: O(1) – No hashmap or extra data structure is used. Only a constant number of pointers are used.
*/

// CODE (C++)

void insertCopyInBetween(Node *head)
{
    Node *temp = head;

    // Insert copied nodes between original nodes
    while (temp != NULL)
    {
        Node *nextElement = temp->next;
        Node *copy = new Node(temp->val);

        copy->next = nextElement;
        temp->next = copy;

        temp = nextElement;
    }
}

void connectRandomPointers(Node *head)
{
    Node *temp = head;

    // Assign random pointers to copied nodes
    while (temp != NULL)
    {
        Node *copyNode = temp->next;

        if (temp->random)
            copyNode->random = temp->random->next;
        else
            copyNode->random = nullptr;

        temp = temp->next->next;
    }
}

Node *getDeepCopyList(Node *head)
{
    Node *temp = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    // Separate original and copied lists
    while (temp != NULL)
    {
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }

    Node *copiedHead = dummyNode->next;

    // Free dummy node
    delete dummyNode;

    return copiedHead;
}

Node *copyRandomList(Node *head)
{
    // Handle empty list
    if (head == NULL)
        return NULL;

    // First pass: Create copied nodes
    insertCopyInBetween(head);

    // Second pass: Connect random pointers
    connectRandomPointers(head);

    // Third pass: Separate both lists
    return getDeepCopyList(head);
}
