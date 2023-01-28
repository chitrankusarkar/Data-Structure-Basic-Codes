#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
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
    temp->left = temp->right = NULL;
    return temp;
}
node *create(node *root)
{
    int ch;
    node *temp;
    if (root == NULL)
    {
        cout << "For root ";
        temp = newNode();
        create(temp);
        return temp;
    }
    else
    {
        cout << "Do you want to add to the left of : " << root->data << " ?" << endl;
        cout << "Enter 1 to add or any other to Cancel : ";
        cin >> ch;
        if (ch == 1)
        {
            root->left = newNode();
            create(root->left);
        }
        cout << "Do you want to add to the right of : " << root->data << " ?" << endl;
        cout << "Enter 1 to add or any other to Cancel : ";
        cin >> ch;
        if (ch == 1)
        {
            root->right = newNode();
            create(root->right);
        }
        return NULL;
    }
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
int main()
{
    node *root = NULL;
    root = create(root);
    cout << "---------- The nodes of the Tree are ----------" << endl;
    inOrder(root);
    return 0;
}