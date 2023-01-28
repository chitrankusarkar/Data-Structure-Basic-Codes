#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};
node *newNode(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        cout << "Can't allocate memory!!" << endl;
    }
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
node *create(node *root, int key)
{
    if (root == NULL)
        return newNode(key);
    if (key < root->data)
        root->left = create(root->left, key);
    else if (key > root->data)
        root->right = create(root->right, key);
    return root;
}
node *search(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

node *minValueNode(node *node)
{
    if (node->left != NULL)
    {
        return minValueNode(node->left);
    }
    return node;
}

node *deleteNode(node *root, int key)
{
    struct node *temp;
    if (root == NULL)
        return root;
    else
    {
        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                temp = root->left;
                free(root);
                return temp;
            }

            temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
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
    node *ptr;
    node *root = NULL;
    root = create(root, 50);
    create(root, 30);
    create(root, 20);
    create(root, 40);
    create(root, 70);
    create(root, 60);
    create(root, 80);
    cout << "---------- The nodes of the Binary Search Tree are ----------"<< endl;
    inOrder(root);
    ptr = search(root, 40);
    if(ptr == NULL)
    {
        cout << "Data Not Found!!" <<endl;
    }   
    else
    {
        cout << "\nData found at address : "<< ptr << endl;
    }
    root = deleteNode(root, 40);
	cout << endl;
    cout << "---------- The nodes of the Binary Search Tree are ----------"<< endl;
	inOrder(root);
    return 0;
}
