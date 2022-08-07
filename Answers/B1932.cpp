/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangle[500][500];

void B1932Input(int &N)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}
}

int tree(int width, int height, int N)
{
	// 현재 노드 정보를 받는다
	int current = triangle[height][width];
	int left = 0, right = 0;

	// 자식이 있다면 (완전 이진 트리이기 때문에 가능한 if문이다.)
	if (width < N - 1 && height < N - 1)
	{
		// 왼쪽 오른쪽 자식 정보를 받는다.
		left = tree(width, height + 1, N);
		right = tree(width + 1, height + 1, N);

		// 디버깅
		//cout << "height = " << height << " width = " << width << endl;
		//cout << "left = " << left << " right = " << right << endl;
		
	}

	// 왼쪽 자식과 오른쪽 자식 중 더 큰 값을 현재 노드에 더해 리턴한다.
	return max(current + left, current + right);
}

void B1932Solution()
{
	int N;
	int sum = 0;

	B1932Input(N);

	int answer = tree(0, 0, N);

	cout << answer;
}

int main()
{
	B1932Solution();
}
*/