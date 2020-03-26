#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    int number = genres.size();
    int count = number;

    while (count > 0)
    {
        int max = -1;
        int maxIndex = -1;
        for (int i = 0; i < number; i++)
        {
            if (plays[i] > max)
            {
                max = plays[i];
                maxIndex = i;
            }
        }
        plays[maxIndex] = 0;
        answer.push_back(maxIndex);
        count--;

        string maxGenre = genres[maxIndex];
        genres[maxIndex].clear();

        int max2 = -1;
        int maxIndex2 = -1;
        for (int i = 0; i < number; i++)
        {
            if (genres[i] == maxGenre)
            {
                count--;
                genres[i].clear();
                if (max2 < plays[i])
                {
                    max2 = plays[i];
                    maxIndex2 = i;
                }
            }
        }
        if (max2 != -1)
        {
            plays[maxIndex2] = 0;
            answer.push_back(maxIndex2);
        }
    }
    return answer;
}
