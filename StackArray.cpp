#include <iostream>
using namespace std;
#define SIZE 20

class Stack
{
private:
    int n, top, arr[SIZE];

public:
    Stack()
    {
        cout << "Enter the Stack Size : ";
        cin >> n;
        top = -1;
    }
    void push();
    void pop();
    void display();
};
void Stack ::push()
{
    if (top == n - 1)
    {
        cout << "Stack Overflow!!" << endl;
    }
    else
    {
        int item;
        cout << "Enter the element : ";
        cin >> arr[++top];
        cout << "Push Successful!!" << endl;
    }
}
void Stack ::pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow!!" << endl;
    }
    else
    {
        cout << "Popped item is : " << top << endl;
        arr[top--];
    }
}
void Stack ::display()
{
    if (top == -1)
    {
        cout << "Stack Underflow!!";
    }
    else
    {
        cout << "The elements of the Stack are : " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
}
int main()
{
    Stack obj;
    int ch;
    while (ch != 4)
    {
        cout << "Enter 1 to PUSH" << endl;
        cout << "Enter 2 to POP" << endl;
        cout << "Enter 3 to DISPLAY" << endl;
        cout << "Enter 4 to EXIT" << endl;
        cout << "Enter youtr choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.push();
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice!!" << endl;
        }
    }
}