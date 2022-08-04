/*
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 문자열을 받아 연산자와 숫자를 분리시킨다.
void split(string question, vector<string> &number, vector<char> &op)
{	
	int size = question.size();

	// 먼저 연산자를 따로 분리하고 그 자리에 공백을 채운다.
	for (int i = 0; i < size; i++)
	{
		if (question[i] == '+' || question[i] == '-')
		{
			op.emplace_back(question[i]);
			question[i] = ' ';
		}
	}

	// 이후 공백을 기준으로 문자열을 분리한다. (숫자만 따로 얻음)
	istringstream ss(question);
	string stringbuffer;

	while (getline(ss, stringbuffer, ' '))
	{
		number.emplace_back(stringbuffer);
	}
}
// - 연산자 뒤에 + 연산자가 있다면 -로 바꿔 괄호를 씌워주는 것 처럼 보이게 한다.
void changeOp(vector<char> &op)
{
	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == '-' && i < op.size() - 1)
		{
			for (int j = i + 1; j < op.size(); j++)
			{
				if (op[j] == '+')
					op[j] = '-';
				else if (op[j] == '+' || j == op.size() - 1)
				{
					i = j;
					break;
				}
			}
		}
	}
}
// 최종 연산
int cal(vector<string> number, vector<char> op)
{
	int sum = stoi(number[0]);
	int size = op.size();

	for (int i = 0; i < size; i++)
	{
		if (op[i] == '+')
		{
			sum += stoi(number[i + 1]);
		}
		else
		{
			sum -= stoi(number[i + 1]);
		}
	}

	return sum;
}

int B1541Solution()
{
	string question;
	int answer = 0;

	vector<string> number;
	vector<char> op;

	cin >> question;

	split(question, number, op);

	/* 디버그
	for (int i = 0; i < number.size(); i++)
		cout << number[i] << ' ';
	cout << endl;
	for (int i = 0; i < op.size(); i++)
		cout << op[i] << ' ';
	cout << endl;
	

	changeOp(op);

	answer = cal(number, op);

	return answer;
}


int main()
{
	cout << B1541Solution();
	return 0;
}
*/