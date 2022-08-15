/*
#include <iostream>
#include <vector>

using namespace std;

struct node
{
	node* left;
	node* right;
	char value;
};

node* t[26];

void B1991Input()
{
	int N;
	cin >> N;

	// 노드 N개 생성. A부터 A + N개까지
	for (int i = 0; i < N; i++)
	{
		node* tree;
		tree = (node*)malloc(sizeof(node));

		// 'A' = 65
		tree->value = 65 + i;
		tree->left = NULL;
		tree->right = NULL;

		t[i] = tree;
	}

	char R, l, r; // Root, left, right
	for (int i = 0; i < N; i++)
	{
		cin >> R >> l >> r;
		
		t[R - 65]->left = t[l - 65];
		t[R - 65]->right = t[r - 65];
	}
}

void preorder(node* node)
{
	cout << node->value;
	if (node->left != NULL)
		preorder(node->left);
	if (node->right != NULL)
		preorder(node->right);
}

void inorder(node* node)
{
	if (node->left != NULL)
		inorder(node->left);
	cout << node->value;
	if (node->right != NULL)
		inorder(node->right);
}

void postorder(node* node)
{
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->value;
}

void B1991Solution()
{
	B1991Input();

	preorder(t[0]);
	cout << endl;
	inorder(t[0]);
	cout << endl;
	postorder(t[0]);
}

int main()
{
	B1991Solution();
}
*/