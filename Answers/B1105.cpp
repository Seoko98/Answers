#include <iostream>
#include <vector>
#include <string>

using namespace std;

void B1107input(int& L, int& R)
{
	cin >> L >> R;
}


bool isSameDigit(string a, string b)
{
	if (a.size() == b.size())
		return true;
	else
		return false;
}

bool isSameNumber(char a, char b)
{
	if (a == b)
		return true;

	return false;
}

bool isNumberEight(char a)
{
	if (a == '8')
		return true;

	return false;
}

int B1107solution(int L, int R)
{
	string strL = "", strR = "";
	int eightCount = 0;

	strL = to_string(L);
	strR = to_string(R);

	if (isSameDigit(strL, strR))
	{
		int size = strL.size();
		for (int i = 0; i < size; i++)
		{
			if (isSameNumber(strL[i], strR[i]))
			{
				if (isNumberEight(strL[i]))
				{
					eightCount++;
				}
			}
			else
				break;
		}
	}

	return eightCount;
}
/*
int main()
{
	int L, R;
	B1107input(L, R);

	cout << B1107solution(L, R);
}
*/