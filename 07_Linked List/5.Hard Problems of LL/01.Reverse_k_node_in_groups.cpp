/*
QUESTION:- https://leetcode.com/problems/reverse-nodes-in-k-group/
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

APPROACH:
(Iterative Approach).
1. The idea is to reverse the nodes of a linked list in groups of size `k` using an iterative approach.

2. First, initialize a pointer `temp` to the head and `prevLast` to `NULL`. `prevLast` keeps track of the last node of the previously reversed group.

3. Find the kth node from the current position using the `findKthNode()` function.
    - If the kth node exists, connect the previous group's last node to the next group's first node and continue to the next group.
    - If the kth node does not exist, connect the previous group's last node to the remaining nodes and stop, leaving the incomplete group unchanged.

4. Store the node after the kth node in `nextNode` and disconnect the current group by setting `kthNode->next = NULL`.

5. Reverse the current group using the `reverseLinkedList()` function, which reverses the links using three pointers: `temp`, `prev`, and `front`.

6. After reversing:
    - If it is the first group, update `head` to the kth node.
    - Otherwise, connect the previous group's last node (`prevLast`) to the new head (`kthNode`) of the reversed group.

7. Update `prevLast` to the original head of the current group (which becomes its last node after reversal) and move `temp` to `nextNode`.

8. Repeat until all complete groups have been reversed and return the updated head.

 
TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1).

*/

Node *reverseLinkedList(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;

        prev = temp;
        temp = front;
    }
    return prev;
}

Node *findKthNode(Node *temp, int k)
{
    k -= 1;

    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prevLast = NULL;
    while (temp != NULL)
    {
        Node *kthNode = findKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevLast)
                prevLast->next = temp;
            break;
        }

        Node *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLinkedList(temp);

        if (temp == head)
            head = kthNode;
        else
            prevLast->next = kthNode;

        prevLast = temp;
        temp = nextNode;
    }
    return head;
}