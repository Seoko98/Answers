#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void input(int &N, int &K)
{
	cin >> N >> K;
}

int solution1052(int N, int K)
{
	vector<int> bottle; // 저장할 물병 집합.

	int tmp = N;
	int count = 0;		// 반복 횟수
	int buy_Count = 0;	// 구매 물병 수

	// N개의 물병을 2개씩 합쳐 전체 수를 줄인다. (2로 나누면서 진행)
	while (tmp != 1)
	{
		// 물병이 홀수 개수만큼 있다면
		if (tmp % 2 == 1)
		{
			// 물병 하나를 빼고 그 물병을 저장한다. (그 물병의 리터를 저장)
			bottle.emplace_back(pow(2, count)); 
			tmp--;
		}

		tmp = tmp / 2;
		count++;
	}

	// 위 과정을 거치고 만들어진 물병을 저장한다.
	bottle.emplace_back(pow(2, count));

	int size = bottle.size();

	int buy = 0;	// 각 반복마다 살 물병 개수

	// 들고 갈 물병 개수가 될 때 까지 반복
	while (K < size)
	{
		// 물병을 구매하고 총 구매 물병 수에 더한다.
		buy += (bottle[1] - bottle[0]);
		buy_Count += buy;

		// 물병을 합친다.
		tmp = buy + bottle[0] + bottle[1];

		// 벡터 인덱스 처리 후 합친 물병을 배열의 가장 앞에 둔다.
		bottle.erase(bottle.begin());
		bottle[0] = tmp;
		
		// 변수 초기화
        buy = 0;
		size = bottle.size();
	}

	return buy_Count;
}

/*
int main()
{
	int N, K;
	input(N, K);

	cout << solution1052(N, K);
}
*/