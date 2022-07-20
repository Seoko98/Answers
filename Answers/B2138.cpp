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
// 현재 상태가 최종 상태와 같은지 확인한다.
bool isSameState(string currentState, string endState)
{
	int size = currentState.size();

	for (int i = 0; i < size; i++)
	{
		if (currentState[i] != endState[i])
			return false;
	}

	return true;
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
	
}

int main()
{
	cout << B2138Solution();
}