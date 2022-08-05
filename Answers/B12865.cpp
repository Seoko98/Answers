#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> things[101];
int answers[101][100001] = {0, };

void B12865Input(int &N, int &K, pair<int, int> things[])
{
	cin >> N >> K;
	int w, v;
	for (int i = 1; i <= N; i++)
	{
		cin >> w >> v;
		things[i] = make_pair(w, v);
	}
}

/* 시간 초과
// 배낭에 최대한 넣는다. i = N - 1, K = 배낭에 넣을 수 있는 최대 무게
int put_in_bag(int i, int K, pair<int, int> things[])
{
	int value = 0;
	// 범위 초과 시 예외 처리
	if (i < 0 || K <= 0)
		return 0;

	// 현재 탐색중인 물건이 현재 배낭에 넣을 수 있는 최대 무게보다 크다면
	if (things[i].first > K)
	{
		// 현재 가방에 들어있는 value를 반환한다.
		value = put_in_bag(i - 1, K, things);
		return value;
	}
	else // bag[i].first <= K
	{
		// 현재 탐색중인 물건을 넣지 않고 다음 물건을 탐색한다.
		int left = put_in_bag(i - 1, K, things);
		// 현재 탐색중인 물건을 넣고 다음 물건을 탐색한다.
		int right = put_in_bag(i - 1, K - things[i].first, things);

		// 위 두 경우 중 value 값이 큰 값을 반환한다.
		return max(left, right + things[i].second);
	}
}
*/
/*
// 1. 물건 하나를 집어 배낭에 넣는다.
// 1-1) 넣기 전에 무게 1 ~ K를 수납할 수 있는 배낭을 준비한다.
// 1-2) 배낭에 물건을 넣을 수 있다면 넣고 그 배낭의 가치를 기억한다(answers 배열)
// 1-3) 넣을 수 없다면 이 물건을 넣기 전의 배낭의 가치를 기억한다.
// 2. 물건을 교체할 때 가치가 클 경우
// 2-1) 바로 전 물건을 넣은 배낭에서 (예를 들어 4번째 물건을 넣는 중이라면 3번째 물건을 넣은 배낭을 찾아)
// 2-2) 현재 물건을 넣을 배낭의 수납 무게에 물건의 무게를 뺀 배낭을 찾아
// 2-3) 찾은 배낭(배낭의 가치)과 현재 물건의 가치를 더한 값을 구한 후
// 2-4) 바로 전 물건을 넣은 배낭과 비교한다.
*/
int put_in_bag(int N, int K, int answers[][100001], pair<int, int> things[])
{
	for (int i = 1; i <= N; i++)
	{
		for (int w = 1; w <= K; w++)
		{
			if (things[i].first <= w) // 최대 무게를 1씩 늘려가며 계산한다.
			{
				if ((things[i].second + answers[i - 1][w - things[i].first]) > answers[i - 1][w])
				{
					answers[i][w] = things[i].second + answers[i - 1][w - things[i].first];
				}
				else
					answers[i][w] = answers[i - 1][w];
			}
			else
				answers[i][w] = answers[i - 1][w];
		}
	}

	return answers[N][K];
}
void B12865Solution()
{
	int N, K, max_value = 0;
	// N, K, things 입력
	B12865Input(N, K, things);
	
	max_value = put_in_bag(N, K, answers, things);

	cout << max_value;
}
/*
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	B12865Solution();
	return 0;
}
*/