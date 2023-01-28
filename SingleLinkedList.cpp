#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *newNode()
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        cout << "Can't allocate memory!!" << endl;
    }
    cout << "Enter data : ";
    cin >> temp->data;
    temp->next = NULL;
    return temp;
}
node *addAtHead(node *head)
{
    node *temp = newNode();
    temp->next = head;
    head = temp;
    return head;
}
node *addAtEnd(node *head)
{
    node *ptr = head;
    node *temp = newNode();
    if (head != NULL)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        return head;
    }
    else
    {
        return temp;
    }
}
int getSize(node *head)
{
    int size = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        size++;
    }
    return size;
}
node *addAtCertinPos(node *head)
{
    int pos;
    node *ptr = head;
    cout << "Enter the position to Insert a node : ";
    cin >> pos;

    int size = getSize(head);
    if (pos >= 1 && pos <= size + 1)
    {
        node *temp = newNode();
        if (pos == 1)
        {
            temp->next = head;
            head = temp;
            return head;
        }
        while (pos != 2)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        return head;
    }
    else
    {
        cout << "Invalid Position!!" << endl;
    }
}
node *delFromHead(node *head)
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "Linked List is empty!!" << endl;
    }
    else
    {
        ptr = ptr->next;
        free(head);
        head = ptr;
        return head;
    }
}
node *delFromEnd(node *head)
{

    if (head == NULL)
    {
        cout << "Linked List is empty!!" << endl;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        node *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
    return head;
}
node *delFromCertainPos(node *head)
{
    int pos;
    node *ptr = head;
    node *prev = head;
    node *curr = head;
    cout << "Enter the position to Insert a node : ";
    cin >> pos;
    int size = getSize(head);
    if (pos >= 1 && pos <= size)
    {
        if (pos == 1)
        {
            return (delFromHead(head));
        }
        while (pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        prev->next = curr->next;
        free(curr);
        curr = NULL;
        return head;
    }
    else
    {
        cout << "Invalid Position!!" << endl;
    }
}
void display(node *head)
{
    node *ptr = head;
    if (ptr == NULL)
    {
        cout << "Linked List is empty!!" << endl;
    }
    else
    {
        cout << "The elements of the Linked List are : ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}
int main()
{
    int ch, size = 0;
    node *head, *temp, *ptr;
    head = NULL;
    while (1)
    {
        if (head == NULL)
        {
            temp = newNode();
            head = temp;
            ptr = temp;
        }
        else
        {
            ptr->next = newNode();
            ptr = ptr->next;
        }
        cout << "Do you want to continue?" << endl;
        cout << "Enter 1 to Continue or any other number to Cancel" << endl;
        cin >> ch;
        if (ch != 1)
        {
            break;
        }
        ptr->next = NULL;
    }
    cout << "------------ Before Function Calls ------------" << endl;
    display(head);
    cout << "---------- Adding node at the Beginning ----------" << endl;
    head = addAtHead(head);
    display(head);
    cout << "---------- Adding node at the End ----------" << endl;
    head = addAtEnd(head);
    display(head);
    cout << "---------- Adding node at Certain Position ----------" << endl;
    head = addAtCertinPos(head);
    // If the position is not valid it will print garbage values
    display(head);
    cout << "---------- Deleting Node from the Beginning ----------" << endl;
    head = delFromHead(head);
    display(head);
    cout << "---------- Deleting Node from the End ----------" << endl;
    head = delFromEnd(head);
    display(head);
    cout << "---------- Deleting Node from the Certain Position ----------" << endl;
    head = delFromCertainPos(head);
    // If the position is not valid it will print garbage values
    display(head);
    size = getSize(head);
    cout << "\nThe Total Nodes in the Linked List are : " << size << endl;
    return 0;
}