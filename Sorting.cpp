#include <iostream>
#define SIZE 20
using namespace std;

class Sorting
{
private:
    int n;
    int arr[SIZE];

public:
    void inIt();
    void swap(int *, int *);
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void display();
    // void shellSort();
};
void Sorting ::inIt()
{
    cout << "Enter the array size : ";
    cin >> n;
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void Sorting ::swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void Sorting ::bubbleSort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void Sorting ::insertionSort()
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void Sorting ::selectionSort()
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }
}
void Sorting ::display()
{
    cout << "The sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}
int main()
{
    Sorting obj;
    int ch;
    while (ch != 4)
    {
        cout << "Enter 1 to Sort using Bubble Sort" << endl;
        cout << "Enter 2 to Sort using Insertion Sort" << endl;
        cout << "Enter 3 to Sort using Selection Sort" << endl;
        cout << "Enter 4 to EXIT" << endl;
        cout << "Enter youtr choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.inIt();
            obj.bubbleSort();
            obj.display();
            break;

        case 2:
            obj.inIt();
            obj.insertionSort();
            obj.display();
            break;

        case 3:
            obj.inIt();
            obj.selectionSort();
            obj.display();
            break;

        default:
            cout << "Invalid Option!!" << endl;
        }
    }
}