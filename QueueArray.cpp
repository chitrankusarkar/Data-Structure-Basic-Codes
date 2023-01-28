#include <iostream>
using namespace std;
#define SIZE 20

class Queue
{
private:
    int n, front, rear, arr[SIZE];

public:
    Queue()
    {
        cout << "Enter the Queue Size : ";
        cin >> n;
        front = rear = -1;
    }
    void enqueue();
    void dequeue();
    void display();
};
void Queue ::enqueue()
{
    if (rear == n - 1)
    {
        cout << "Queue is full!!" << endl;
    }
    else
    {
        cout << "Enter the element : ";
        cin >> arr[++rear];
        cout << "Enqueuing Successful!!" << endl;
        if (front == -1)
        {
            front++;
        }
    }
}
void Queue ::dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty!!" << endl;
    }
    else
    {
        cout << "Dequeued element is : " << arr[front] << endl;
        arr[front++];
        if(front > rear)
        {
            front = rear = -1;
        }
    }
}
void Queue ::display()
{
    if (front == -1)
    {
        cout << "Queue is empty!!" << endl;
    }
    else
    {
        cout << "The elements of the Queue are : ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    Queue obj;
    int ch;
    while (ch != 4)
    {
        cout << "Enter 1 to ENQUEUE" << endl;
        cout << "Enter 2 to DEQUEUE" << endl;
        cout << "Enter 3 to DISPLAY" << endl;
        cout << "Enter 4 to EXIT" << endl;
        cout << "Enter youtr choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.enqueue();
            break;
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice!!" <<endl;
        }
    }
}