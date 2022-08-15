/*
#include <iostream>
#include <vector>

using namespace std;

int inOrder[100001];
int postOrder[100001];
int inOrder_Index[100001]; 

void B2263Input(int &N)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> inOrder[i];
		inOrder_Index[inOrder[i]] = i;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> postOrder[i];
	}
}

void getTree(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd)
{
	// 분할할 수 없다면 return
	if (inOrderStart > inOrderEnd || postOrderStart > postOrderEnd)
	{
		return;
	}
	
	// postOrder의 맨 끝은 항상 root임을 고려해 inOrder의 루트를 찾는 다음
	// inOrder의 루트 기준 왼쪽 범위와 오른쪽 범위를 구한다.
	int inOrderRootIndex = inOrder_Index[postOrder[postOrderEnd]];
	int leftRange = inOrderRootIndex - inOrderStart;
	int rightRange = inOrderEnd - inOrderRootIndex;

	cout << inOrder[inOrderRootIndex] << ' ';

	// 재귀
	getTree(inOrderStart, inOrderRootIndex - 1, postOrderStart, postOrderStart + leftRange - 1);
	getTree(inOrderRootIndex + 1, inOrderEnd, postOrderStart + leftRange, postOrderEnd - 1);
}

void B2263Solution()
{
	int N;
	B2263Input(N);
	getTree(0, N - 1, 0, N - 1);
}

int main()
{
	B2263Solution();
}
*/