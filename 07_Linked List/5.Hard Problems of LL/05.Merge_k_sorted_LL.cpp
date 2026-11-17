/*Question: https://leetcode.com/problems/merge-k-sorted-lists/
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []


Approach: Min Heap (Priority Queue)
1. Initialize a Min Heap: Create a min heap that stores `ListNode*` and compares nodes based on their `val`.
2. Insert Head Nodes: Traverse the `lists` vector and insert the head node of every non-empty linked list into the min heap.
3. Create a Dummy Node: Create a dummy node and a `tail` pointer to construct the merged linked list easily.
4. Extract the Smallest Node: While the min heap is not empty:
    - Extract the node with the smallest value.
    - If the extracted node has a next node, insert that next node into the min heap.
    - Attach the extracted node to the merged list using `tail->next`.
    - Move the `tail` pointer forward.
5. Return the Result: Once the heap becomes empty, return `dummy.next`, which points to the merged sorted linked list.

Complexity Analysis
- Time Complexity: \\(O(N \log K)\\), where N is the total number of nodes and K is the number of linked lists. Each node is inserted and removed from the min heap.
- Space Complexity: \\(O(K)\\), as the min heap stores at most K nodes at a time.

**Key Idea:** Instead of comparing all nodes individually, use a Min Heap to efficiently find the smallest available node among the K sorted linked lists.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *bottom;

    // Constructor for a linked list node.
    ListNode(int value)
    {
        val = value;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        auto compare = [](ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> minHeap(compare);

        // Push the head of every linked list
        for (ListNode *head : lists)
        {
            if (head != nullptr)
            {
                minHeap.push(head);
            }
        }

        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (!minHeap.empty())
        {

            ListNode *smallest = minHeap.top();
            minHeap.pop();

            // Push the next node of the extracted node
            if (smallest->next != nullptr)
            {
                minHeap.push(smallest->next);
            }

            // Attach the smallest node to the merged list
            tail->next = smallest;
            tail = tail->next;
        }

        return dummy.next;
    }
};
