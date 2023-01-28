#include <iostream>
#define SIZE 100
using namespace std;

class DeQueue
{
private:
    int arr[SIZE];
    int rear, front;

public:
    void insertAtFront(int);
    void insertAtRear(int);
    void delAtFront();
    void delAtRear();
    void traverse();
    DeQueue()
    {
        rear = -1;
        front = -1;
    }
};

void DeQueue ::insertAtRear(int size)
{
    if (rear == size - 1)
    {
        cout << "Queue Overflow!!" << endl;
    }
    else
    {
        cout << "Enter value : ";
        cin >> arr[++rear];
        if (front == -1)
        {
            front += 1;
        }
        cout << "Insertion Successful\n";
    }
}
void DeQueue ::insertAtFront(int size)
{
    if (rear == size - 1)
    {
        cout << "Queue Overflow!!" << endl;
    }
    else
    {
        for (int i = rear; i >= front; i--)
        {
            arr[i + 1] = arr[i];
        }
        cout << "Enter value : ";
        cin >> arr[front];
        rear += 1;
    }
}
void DeQueue ::delAtFront()
{
    if (front == -1)
    {
        cout << "Queue Underflow!!" << endl;
    }
    else
    {
        front = front + 1;
        if (front > rear)
        {
            front = rear = -1;
        }
        cout << "Deletion Successful!\n"
             << endl;
    }
}
void DeQueue ::delAtRear()
{
    if (front == -1)
    {
        cout << "Queue Underflow!!" << endl;
    }
    else
    {
        rear -= 1;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void DeQueue ::traverse()
{
    if (front == -1)
    {
        cout << "Queue Underflow!!" << endl;
    }
    else
    {
        cout << "The elemenets are : ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
}
int main()
{
    int size;
    cout << "Enter the size of Queue : ";
    cin >> size;
    DeQueue obj;
    int choice;
    while (choice != 6)
    {
        cout << "\nEnter 1 for INSERTION at REAR : \n"
             << "Enter 2 for INSERTION at FRONT : \n"
             << "Enter 3 for DELETION at REAR : \n"
             << "Enter 4 for DELETETION at FRONT : \n"
             << "Enter 5 for TRAVERSAL : \n"
             << "Enter 6 for EXIT : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.insertAtRear(size);
            break;
        case 2:
            obj.insertAtFront(size);
            break;
        case 3:
            obj.delAtRear();
            break;
        case 4:
            obj.delAtFront();
            break;
        case 5:
            obj.traverse();
            break;
        case 6:
            break;
        default:
            cout << "Invalid Input!!!\n";
        }
    }
    return 0;
}