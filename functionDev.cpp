#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(!progresses.empty()){
        for(int i=0; i<progresses.size(); i++){
            progresses[i]+=speeds[i];
        }
        if(*progresses.begin()>=100){
            int result=0;
            while(*progresses.begin()>=100&&!progresses.empty()){
                result++;
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
            }
            answer.push_back(result);
        }
    }
    return answer;
}
