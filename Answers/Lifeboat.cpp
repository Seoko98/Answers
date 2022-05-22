#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) 
{
    vector<int> light_People;
    vector<int> heavy_People;

    int len = people.size();

    for (int i = 0; i < len; i++)
    {
        if (people[i] > limit / 2)
            heavy_People.emplace_back(people[i]);
        else
            light_People.emplace_back(people[i]);
    }
    
    // ������ ��� �׷��� ��������, ���ſ� ����� ������������ ����
    if(!light_People.empty())
        sort(light_People.begin(), light_People.end(), less<int>());
    if(!heavy_People.empty())
        sort(heavy_People.begin(), heavy_People.end(), greater<int>());

    int l_len = light_People.size();
    int h_len = heavy_People.size();
    len = (l_len > h_len) ? l_len : h_len;  // �� ���� �� ���� ���̸� ��ȯ

    int answer = 0;

    // 2���� ��Ʈ�� �ִ��� limit�� ����� ���Է� ���� �¿��.
    for (int i = 0; i < len; i++)
    {
        // �� ���Ͱ� ������� ���� �� ����
        if (!light_People.empty() && !heavy_People.empty())
        {
            if (light_People[0] + heavy_People[h_len - 1] > limit)
                break;
            // ���� ������ ����� i��°�� ���ſ� ����� ���� limit���� �۴ٸ�
            if (light_People[0] + heavy_People[i] <= limit)
            {
                // ��Ʈ�� �¿��. (���Ϳ��� ����)
                light_People.erase(light_People.begin());
                heavy_People.erase(heavy_People.begin() + i);

                // �ε��� ����
                i--;
                len--;

                answer++;
            }
        }
        // �� �� �ϳ��� ����ִٸ� Ż��
        else
            break;
    }
    
    // �� ó���� ��ġ�� ������ �׷��� �����ִٸ�
    if (!light_People.empty())
    {
        // �� �� ¦���´�.
        int pair = light_People.size() / 2;
        // �׷��� Ȧ���ϼ��� �����Ƿ� �������� ���Ѵ�.
        int remain = light_People.size() % 2;

        answer += (pair + remain);
    }

    // ���ſ� �׷� ó��
    if(!heavy_People.empty())
        answer += heavy_People.size();

    return answer;
}

int main()
{
    vector<int> people = { 100, 500, 500, 900, 950};
    int limit = 1000;

    cout << solution(people, limit);
}