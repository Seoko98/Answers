#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

///////////////////////////////////////
// baekjoon 18185: buy ramen (Small) //
///////////////////////////////////////

// 공장에서 라면을 산다. buy ramen at factory.
int buy (vector<int> &needs, int ptr, int way)
{
	// 지불해야할 돈. money to pay
	int money = 0;

	// 현재 지정 범위의 최소 재고를 찾는다. find minimum stock at current specified range
	int min = *min_element(needs.begin() + ptr, needs.begin() + ptr + (way - 1));

	// 지정 범위의 재고에서 최소 재고를 뺀다. substract min from stock in specified range
	for (int i = ptr; i <= ptr + (way - 1); i++)
	{
		needs[i] -= min;
	}

	// 지불할 돈을 방법에 맞게 구한다. calculate the money according to the way
	if (way == 3)
		money = min * 7;
	else if (way == 2)
		money = min * 5;

	return money;
}

int solution (vector<int> needs)
{
	// 현재 인덱스를 가리키는 포인터. pointer that point current index
	int ptr = 0;
	int end = needs.size();

	// 지불해야할 돈. money to pay
	int pay = 0;

	// 벡터의 끝까지 탐색할 때 까지 반복. repeat until ptr explores the vector to the end
	while (ptr != end)
	{
		// 현재 인덱스의 재고가 0이면 다음을 가리킨다. if stock of current index is 0, point next
		if (needs[ptr] == 0)
		{
			ptr++;
			continue;
		}

		// 공장 3개가 연달아 재고가 있을 때. if three factory in a row has stock.
		if (ptr + 2 < end && needs[ptr] != 0 && needs[ptr + 1] != 0 && needs[ptr + 2] != 0)
		{
			// 예외(두 번째 공장 재고가 세 번째 공장 재고보다 많을 때). exception(if stock of second factory more than third)
			while (needs[ptr + 1] > needs[ptr + 2] && needs[ptr] > 0)
			{
				needs[ptr]--;
				needs[ptr + 1]--;

				pay += 5;
			}

			pay += buy(needs, ptr, 3);
		}
		// 공장 2개가 연달아 재고가 있을 때, if two factory in a row has stock
		else if (ptr + 1 < end && needs[ptr] != 0 && needs[ptr + 1] != 0)
		{
			pay += buy(needs, ptr, 2);
		}
		// 공장이 연달아 재고가 있지 않을 때, if just one factory
		else
		{
			pay += needs[ptr] * 3;
			needs[ptr] = 0;
			ptr++;
		}
	}

	return pay;
}