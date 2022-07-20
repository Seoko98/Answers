#include <iostream>
#include <vector>

using namespace std;

void input(int &N, int &M, vector<pair<int, int>> &brands)
{
	int first, second;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> first >> second;

		brands.emplace_back(make_pair(first, second));
	}
}

// O(n^2) 더 줄일 수 있을 것 같다. 아마도?
int solution(int N, int M, vector<pair<int, int>> brands)
{
	int min_price = 1000000;

	int quotient = 0, remain = 0;

	quotient = N / 6;
	remain = N % 6;

	int tmp = 0;

	// 패키지로 먼저 구매한 후 나머지를 낱개 혹은 패키지로 구매한다.
	for (int i = 0; i < M; i++)
	{
		// 패키지가 낱개에 비해 비싸다면 낱개 구매
		if (brands[i].first / 6 >= brands[i].second)
			tmp += brands[i].second * 6 * quotient;
		else
			tmp += brands[i].first * quotient;

		// 패키지 구매 값 저장
		int check = tmp;

		for (int j = 0; j < M; j++)
		{
			// 낱개로 사는 가격이 패키지 가격보다 비싸다면 패키지 구매
			if (brands[i].first < brands[j].second * remain)
				tmp += brands[i].first;
			else
				tmp += brands[j].second * remain;

			if (tmp < min_price)
				min_price = tmp;
			
			// 다음 브랜드 값과 비교하기 위한 초기화
			tmp = check;
		}

		tmp = 0;
	}

	return min_price;
}
/*
int main()
{
	int N, M; // N = 끊어진 기타줄 개수, M = 기타줄 브랜드 수
	vector<pair<int, int>> brands; // first = 패키지(6개) 가격, second = 1개 가격

	input(N, M, brands);

	cout << solution(N, M, brands);
}
*/