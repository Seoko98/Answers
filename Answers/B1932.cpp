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
	// ���� ��� ������ �޴´�
	int current = triangle[height][width];
	int left = 0, right = 0;

	// �ڽ��� �ִٸ� (���� ���� Ʈ���̱� ������ ������ if���̴�.)
	if (width < N - 1 && height < N - 1)
	{
		// ���� ������ �ڽ� ������ �޴´�.
		left = tree(width, height + 1, N);
		right = tree(width + 1, height + 1, N);

		// �����
		//cout << "height = " << height << " width = " << width << endl;
		//cout << "left = " << left << " right = " << right << endl;
		
	}

	// ���� �ڽİ� ������ �ڽ� �� �� ū ���� ���� ��忡 ���� �����Ѵ�.
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