#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    // Create and link nodes for remaining elements.
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Insert a new node at the beginning.
Node *insertHead(Node *head, int val)
{
    return new Node(val, head);
}

// Insert a new node at the end.
Node *insertTail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }

    Node *temp = head;

    // Traverse to the last node.
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(val);
    temp->next = newNode;

    return head;
}

// Insert a new node at position k (1-based).
Node *insertAtPosition(Node *head, int el, int k)
{
    if (head == NULL)
    {
        // Only position 1 is valid for an empty list.
        if (k == 1)
        {
            return new Node(el);
        }
        else
        {
            return head;
        }
    }

    // Insert at the beginning.
    if (k == 1)
    {
        return new Node(el, head);
    }

    int cnt = 0;
    Node *temp = head;

    // Find the node just before position k.
    while (temp != NULL)
    {
        cnt++;

        if (cnt == (k - 1))
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }

        temp = temp->next;
    }

    return head;
}

// Insert a new node before the first occurrence of val.
Node *insertAtValue(Node *head, int el, int val)
{
    if (head == NULL)
    {
        return NULL;
    }

    // If the target is the first node, update the head.
    if (head->data == val)
    {
        return new Node(el, head);
    }

    Node *temp = head;

    // Search for the node containing val.
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }

        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrToLL(arr);

    // head = insertHead(head, 100);
    // print(head);

    // head = insertTail(head, 200);
    // print(head);

    // head = insertAtPosition(head, 100, 2);
    // print(head);

    head = insertAtValue(head, 100, 12);
    print(head);
}