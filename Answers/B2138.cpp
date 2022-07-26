#include <iostream>
#include <vector>
#include <string>

using namespace std;

void B2138Input(string &currentState, string &endState)
{
	int N;
	string tmp;
	cin >> N;

	cin >> tmp;
	currentState = tmp;

	cin >> tmp;
	endState = tmp;
}
// 0이면 1로, 1이면 0으로 변환한다.
void switching (char &num)
{
	if (num == '0')
		num = '1';
	else
		num = '0';
}
// 현재 상태와 인덱스를 받아 인덱스의 위치에 따라 다른 방식으로 변환한다.
void change(string& currentState, int i)
{
	int size = currentState.size();

	if (i == 0)
	{
		switching(currentState[i]);
		switching(currentState[i + 1]);
	}
	else if (i == size - 1)
	{
		switching(currentState[i - 1]);
		switching(currentState[i]);
	}
	else
	{
		switching(currentState[i - 1]);
		switching(currentState[i]);
		switching(currentState[i + 1]);
	}
}

int B2138Solution()
{
	string currentState, endState, firstState;
	int changeCount1 = 0, changeCount2 = 0, minCount;

	B2138Input(currentState, endState);
	
	firstState = currentState;

	int size = currentState.size();
	// 0번 스위치를 누르는 경우
	change(currentState, 0);
	changeCount1++;

	for (int i = 1; i < size; i++)
	{
		// 이전 스위치의 상태가 최종 스위치 상태랑 같지 않다면
		if (currentState[i - 1] != endState[i - 1])
		{
			// 누른다
			change(currentState, i);
			changeCount1++;
		}
	}

	// 위 과정을 거친 스위치가 최종 상태랑 같지 않다면
	if (currentState != endState)
		changeCount1 = -1;

	// 초기화
	currentState = firstState;

	// 0번 스위치를 누르지 않는 경우
	for (int i = 1; i < size; i++)
	{
		if (currentState[i - 1] != endState[i - 1])
		{
			change(currentState, i);
			changeCount2++;
		}
	}

	if (currentState != endState)
		changeCount2 = -1;

	// 스위치 누른 횟수 리턴
	if (changeCount1 == -1 && changeCount2 == -1)
		return -1;
	else if (changeCount1 == -1)
		return changeCount2;
	else if (changeCount2 == -1)
		return changeCount1;
	else if (changeCount1 <= changeCount2)
		return changeCount1;
	else if (changeCount2 < changeCount1)
		return changeCount2;
}

/*
int main()
{
	cout << B2138Solution();
}
*/