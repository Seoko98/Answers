/*
#include <iostream>
#include <algorithm>

using namespace std;

int field[300000]; // 2Â÷¿ø ¹è¿­ -> 1Â÷¿ø ¹è¿­·Î [100000][3] -> [300000]
int prev_memo[3];
int memo[3];


void B2096Input(int &N)
{
	cin >> N;
	for (int i = 0; i < 3 * N; i++)
	{
		cin >> field[i];
	}
}

void descending(int N, int mode)
{
	memo[0] = field[0];
	memo[1] = field[1];
	memo[2] = field[2];

	for (int i = 3; i < 3 * N; i++)
	{
		int index = i % 3;

		if (index == 0)
		{
			for (int j = 0; j < 3; j++)
				prev_memo[j] = memo[j];
		}

		switch (mode)
		{
		// mode = max
		case 0:
			switch (index)
			{
			// ¿ÞÂÊ ÀÎµ¦½º
			case 0:
				memo[index] = max(prev_memo[0] + field[i], prev_memo[1] + field[i]);
				break;
			// °¡¿îµ¥ ÀÎµ¦½º
			case 1:
				memo[index] = max(prev_memo[0] + field[i], prev_memo[1] + field[i]);
				memo[index] = max(memo[index], prev_memo[2] + field[i]);
				break;
			// ¿À¸¥ÂÊ ÀÎµ¦½º
			case 2:
				memo[index] = max(prev_memo[1] + field[i], prev_memo[2] + field[i]);
				break;
			}
			break;

		// mode = min
		case 1:
			switch (index)
			{
				// ¿ÞÂÊ ÀÎµ¦½º
			case 0:
				memo[index] = min(prev_memo[0] + field[i], prev_memo[1] + field[i]);
				break;
				// °¡¿îµ¥ ÀÎµ¦½º
			case 1:
				memo[index] = min(prev_memo[0] + field[i], prev_memo[1] + field[i]);
				memo[index] = min(memo[index], prev_memo[2] + field[i]);
				break;
				// ¿À¸¥ÂÊ ÀÎµ¦½º
			case 2:
				memo[index] = min(prev_memo[1] + field[i], prev_memo[2] + field[i]);
				break;
			}
			break;
			
		}
		//µð¹ö±ë
		//cout << "memo[" << index << "] = " << memo[index] << endl;
	}
}

void B2096Solution()
{
	int N;
	int max_value = 0, min_value = 0;
	B2096Input(N);

	// max
	descending(N, 0);
	max_value = max(memo[0], memo[1]);
	max_value = max(max_value, memo[2]);

	// min
	descending(N, 1);
	min_value = min(memo[0], memo[1]);
	min_value = min(min_value, memo[2]);

	cout << max_value << ' ' << min_value;
}

int main()
{
	B2096Solution();
	return 0;
}
*/