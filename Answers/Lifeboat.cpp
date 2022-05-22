#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    // people�� �������� ������ sort_People
    vector<int> sort_People = people;
    sort(sort_People.begin(), sort_People.end(), less<int>());

    int len = sort_People.size();
    int back_ptr = len;
    int answer = 0;

    // 2���� �ִ��� limit�� ������ �¿��.
    for (int i = 0; i < len; i++)
    {
        // ���� ������ ���.
        int first = sort_People[i];
        for (int j = back_ptr - 1; j > 0; j--)
        {
            // ���� ���ſ� ���.
            int second = sort_People[j];
            // ���� ���԰� limit�� ���ų� �۴ٸ�
            if (first + second <= limit)
            {
                // ���� ��Ʈ�� �¿��(���Ϳ��� ����)
                sort_People.erase(sort_People.begin() + j);
                sort_People.erase(sort_People.begin() + i);

                // �ε��� ���� �� answer ����
                len -= 2;
                back_ptr = j;
                i--;
                answer++;

                break;
            }
        }
    }

    // 2�� ��Ÿ�� ������� �¿��(�������� ����)
    answer += sort_People.size();
    
    return answer;
}

int main()
{
    vector<int> people = { 40, 50, 50, 60, 70, 150, 160, 170, 200 };
    int limit = 200;

    cout << solution(people, limit);
}