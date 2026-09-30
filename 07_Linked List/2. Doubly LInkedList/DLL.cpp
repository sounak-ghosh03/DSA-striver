#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data2)
    {
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};

// Convert an array into a doubly linked list
Node *convertArryToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        // Link the new node with the previous node
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

// Print all elements of the DLL
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Delete the head node
Node *removeHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *prev = head;
    head = head->next;

    // Detach the old head
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

// Delete the tail node
Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *tail = head;

    // Traverse to the last node
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = NULL;

    delete tail;

    return head;
}

// Delete the kth node from the DLL
Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    int cnt = 0;
    Node *kNode = head;

    // Find the kth node
    while (kNode != NULL)
    {
        cnt++;

        if (cnt == k)
            break;

        kNode = kNode->next;
    }

    Node *prev = kNode->back;
    Node *front = kNode->next;

    // Only single node exists
    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    // kth node is the head
    else if (prev == NULL)
    {
        return removeHead(head);
    }
    // kth node is the tail
    else if (front == NULL)
    {
        return removeTail(head);
    }

    // Connect previous and next nodes
    prev->next = front;
    front->back = prev;

    // Detach and delete kth node
    kNode->next = NULL;
    kNode->back = NULL;

    delete kNode; //or free(kNode);

    return head;
}

// Delete a given node from the DLL
void remoeveNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    // Given node is the tail
    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);

        return;
    }

    // Bypass the given node
    prev->next = front;
    front->back = prev;

    // Detach and delete the node
    temp->next = temp->back = nullptr;

    free(temp);
}

// Insert a new node before the head
Node *insertBeforeHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);

    head->back = newHead;

    return newHead;
}

// Insert a new node before the tail
Node *insertBeforeTail(Node *head, int val)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }

    Node *tail = head;

    // Find the current tail
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *prev = tail->back;

    Node *newNode = new Node(val, tail, prev);

    // Insert new node between prev and tail
    prev->next = newNode;
    tail->back = newNode;

    return head;
}

// Insert a new node before the kth node
Node *insertBeforeKthElement(Node *head, int k, int val)
{
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }

    Node *temp = head;
    int cnt = 0;

    // Find the kth node
    while (temp != NULL)
    {
        cnt++;

        if (cnt == k)
            break;

        temp = temp->next;
    }

    Node *prev = temp->back;

    Node *newNode = new Node(val, temp, prev);

    // Insert new node before kth node
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

// Insert a new node before a given node
void insertBeforeGivenNode(Node *node, int val)
{
    Node *prev = node->back;

    Node *newNode = new Node(val, node, prev);

    // Link the new node between prev and node
    prev->next = newNode;
    node->back = newNode;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};

    Node *head = convertArryToDLL(arr);

    // Deletion
    // print(head);
    // head = removeHead(head);
    // print(head);

    // head = removeTail(head);
    // print(head);

    // head = removeKthElement(head, 1);
    // print(head);

    // remoeveNode(head->next->next);
    // print(head);

    // Insertion
    // head = insertBeforeHead(head, 10);
    // print(head);

    // head = insertBeforeTail(head, 20);
    // print(head);

    // head = insertBeforeKthElement(head, 3, 20);
    // print(head);

    insertBeforeGivenNode(head->next, 100);
    print(head);

    return 0;
}