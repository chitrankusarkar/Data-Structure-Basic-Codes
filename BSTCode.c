#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->key);
	}
}

struct node *insert(struct node *node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

struct node *search(struct node *root, int key)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (key == root->key)
	{
		return root;
	}
	else if (key < root->key)
	{
		return search(root->left, key);
	}
	else
	{
		return search(root->right, key);
	}
}

struct node *minValueNode(struct node *node)
{
	if (node->left != NULL)
	{
		return minValueNode(node->left);
	}
	return node;
}

struct node *deleteNode(struct node *root, int key)
{
	struct node *temp;
	if (root == NULL)
		return root;
	else
	{
		if (key < root->key)
			root->left = deleteNode(root->left, key);

		else if (key > root->key)
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
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
		return root;
	}
}

int main()
{
	struct node *temp, *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	temp = search(root, 40);
	if (temp == NULL)
	{
		printf("\nData is not present in the tree");
	}
	else
	{
		printf("\nvalue found at the address- %p", temp);
	}
	root = deleteNode(root, 40);
	printf("\n");
	inorder(root);

	return 0;
}
