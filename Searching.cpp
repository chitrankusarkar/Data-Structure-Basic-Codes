#include <iostream>
#define SIZE 20
using namespace std;

class Searching
{
private:
    int n, arr[SIZE];

public:
    void inItForLinearSearch();
    void inItForBinarySearch();
    void linearSearch();
    void binarySearch();
};
void Searching ::inItForLinearSearch()
{
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the elemenets : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void Searching ::inItForBinarySearch()
{
    cout << "Enter the size of the array : ";
    cin >> n;
    cout << "Enter the elemenets in Sorted order : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void Searching ::linearSearch()
{
    int flag = 0, pos, item;
    cout << "Enter the elememt to search : ";
    cin >> item;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            flag = 1;
            pos = i + 1;
        }
    }
    if (flag != 1)
    {
        cout << "Item not found!!";
    }
    else
    {
        cout << "Item found at position : " << pos;
    }
}
void Searching ::binarySearch()
{
    int beg, end, mid, flag = 0, item;
    beg = 0;
    end = n - 1;
    cout << "Enter the elememt to search : ";
    cin >> item;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == item)
        {
            flag = 1;
            break;
        }
        else if (item > arr[mid])
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (flag == 0)
    {
        cout << "Item not found!!";
    }
    else
    {
        cout << "Iten found at position : " << mid + 1;
    }
}
int main()
{
    Searching obj;
    int ch;
    cout << "Enter your choice : " << endl;
    cout << "Enter 1 to Search using Linear Search " << endl;
    cout << "Enter 2 to Search using Binary Search " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        obj.inItForLinearSearch();
        obj.linearSearch();
        break;
    case 2:
        obj.inItForBinarySearch();
        obj.binarySearch();
        break;
    default:
        cout << "Invalid Choice!!";
    }
    return 0;
}