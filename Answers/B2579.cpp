#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void B2579Input(vector<int> &stair)
{
	int N;
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		stair.emplace_back(tmp);
	}
}

int climb(int start, vector<int> stair)
{
	int score = 0;
	int size = stair.size();
	int continuous = 0;

	score += stair[start];
	continuous++;

	for (int i = start + 1; i < size - 1; i++)
	{
		if (stair[i + 1] == stair[size - 2])
		{
			score += stair[size - 1];
			break;
		}

		if (continuous == 2 && i != size - 2)
		{
			score += stair[i + 1];
			i++;
			continuous = 1;
		}
		else if (stair[i] < stair[i + 1])
		{
			score += stair[i + 1];
			i++;
			continuous++;
		}
		else if (stair[i] >= stair[i + 1])
		{
			score += stair[i];
			continuous++;
		}
	}

	return score;
}

void B2579Solution()
{
	int score = 0;

	vector<int> answer;
	vector<int> stair;
	B2579Input(stair);

	// 첫번째 계단을 밟을 때
	score += climb(0, stair);

	answer.emplace_back(score);
	// 초기화
	score = 0;
	
	// 첫번째 계단을 밟지 않을 때
	score += climb(1, stair);

	answer.emplace_back(score);

	cout << *max_element(answer.begin(), answer.end());
}
/*
int main()
{
	B2579Solution();
	return 0;
}
*/