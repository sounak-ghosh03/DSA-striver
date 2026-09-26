#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Initialize node with data and next pointer
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Initialize node with data only
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

    // Create and link nodes for remaining elements
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// Remove the first node
Node *removeHead(Node *head)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    head = head->next;

    delete temp;
    return head;
}

// Remove the last node / tail of the linked list
Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;

    // Stop at the second-last node
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

// Remove the node at position k (1-based indexing)
Node *removeK(Node *head, int k)
{
    if (head == NULL || k <= 0)
        return head;

    // Handle removal of the head separately
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;
    int cnt = 1;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = temp->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

// Remove the first node containing the given element
Node *removeElement(Node *head, int el)
{
    if (head == NULL)
        return head;

    // Handle removal of the head separately
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrToLL(arr);

    // head = removeHead(head);
    // print(head);

    // head = removeTail(head);
    // print(head);

    // head = removeK(head, 2);
    // print(head);

    head = removeElement(head, 8);
    print(head);
}
