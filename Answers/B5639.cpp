/*
#include <iostream>

using namespace std;

// input 해결 못하면 절대 못품

struct node
{
	node* left;
	node* right;
	unsigned int value;
};

node* tree[10000];


void B5639Input()
{
	int size = 0;
	int v;
	while (cin >> v)
	{
		if (v == EOF)
			break;

		tree[size]->value = v;
		tree[size]->left = NULL;
		tree[size]->right = NULL;
		size++;
	}
}

void B5639Solution()
{
	B5639Input();
}

int main()
{
	B5639Solution();
}
*/