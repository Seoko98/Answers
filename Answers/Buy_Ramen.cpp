#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

///////////////////////////////////////
// baekjoon 18185: buy ramen (Small) //
///////////////////////////////////////

// ���忡�� ����� ���. buy ramen at factory.
int buy (vector<int> &needs, int ptr, int way)
{
	// �����ؾ��� ��. money to pay
	int money = 0;

	// ���� ���� ������ �ּ� ��� ã�´�. find minimum stock at current specified range
	int min = *min_element(needs.begin() + ptr, needs.begin() + ptr + (way - 1));

	// ���� ������ ����� �ּ� ��� ����. substract min from stock in specified range
	for (int i = ptr; i <= ptr + (way - 1); i++)
	{
		needs[i] -= min;
	}

	// ������ ���� ����� �°� ���Ѵ�. calculate the money according to the way
	if (way == 3)
		money = min * 7;
	else if (way == 2)
		money = min * 5;

	return money;
}

int solution (vector<int> needs)
{
	// ���� �ε����� ����Ű�� ������. pointer that point current index
	int ptr = 0;
	int end = needs.size();

	// �����ؾ��� ��. money to pay
	int pay = 0;

	// ������ ������ Ž���� �� ���� �ݺ�. repeat until ptr explores the vector to the end
	while (ptr != end)
	{
		// ���� �ε����� ��� 0�̸� ������ ����Ų��. if stock of current index is 0, point next
		if (needs[ptr] == 0)
		{
			ptr++;
			continue;
		}

		// ���� 3���� ���޾� ��� ���� ��. if three factory in a row has stock.
		if (ptr + 2 < end && needs[ptr] != 0 && needs[ptr + 1] != 0 && needs[ptr + 2] != 0)
		{
			// ����(�� ��° ���� ��� �� ��° ���� ����� ���� ��). exception(if stock of second factory more than third)
			while (needs[ptr + 1] > needs[ptr + 2] && needs[ptr] > 0)
			{
				needs[ptr]--;
				needs[ptr + 1]--;

				pay += 5;
			}

			pay += buy(needs, ptr, 3);
		}
		// ���� 2���� ���޾� ��� ���� ��, if two factory in a row has stock
		else if (ptr + 1 < end && needs[ptr] != 0 && needs[ptr + 1] != 0)
		{
			pay += buy(needs, ptr, 2);
		}
		// ������ ���޾� ��� ���� ���� ��, if just one factory
		else
		{
			pay += needs[ptr] * 3;
			needs[ptr] = 0;
			ptr++;
		}
	}

	return pay;
}