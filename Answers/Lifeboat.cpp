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
    
    // 가벼운 사람 그룹은 오름차순, 무거운 사람은 내림차순으로 정렬
    if(!light_People.empty())
        sort(light_People.begin(), light_People.end(), less<int>());
    if(!heavy_People.empty())
        sort(heavy_People.begin(), heavy_People.end(), greater<int>());

    int l_len = light_People.size();
    int h_len = heavy_People.size();
    len = (l_len > h_len) ? l_len : h_len;  // 두 길이 중 작은 길이를 반환

    int answer = 0;

    // 2명을 보트에 최대한 limit에 가까운 무게로 맞춰 태운다.
    for (int i = 0; i < len; i++)
    {
        // 두 벡터가 비어있지 않을 때 진입
        if (!light_People.empty() && !heavy_People.empty())
        {
            if (light_People[0] + heavy_People[h_len - 1] > limit)
                break;
            // 가장 가벼운 사람과 i번째로 무거운 사람의 합이 limit보다 작다면
            if (light_People[0] + heavy_People[i] <= limit)
            {
                // 보트에 태운다. (벡터에서 제거)
                light_People.erase(light_People.begin());
                heavy_People.erase(heavy_People.begin() + i);

                // 인덱스 조정
                i--;
                len--;

                answer++;
            }
        }
        // 둘 중 하나라도 비어있다면 탈출
        else
            break;
    }
    
    // 위 처리를 거치고 가벼운 그룹이 남아있다면
    if (!light_People.empty())
    {
        // 두 명씩 짝짓는다.
        int pair = light_People.size() / 2;
        // 그룹이 홀수일수도 있으므로 나머지도 구한다.
        int remain = light_People.size() % 2;

        answer += (pair + remain);
    }

    // 무거운 그룹 처리
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