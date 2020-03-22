#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for(int test=0; test<commands.size(); test++){
        for(int i=commands[test][0]; i<=commands[test][1]; i++){
            tmp.push_back(array[i-1]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[commands[test][2]-1]);
        tmp.clear();
    }
    return answer;
}
