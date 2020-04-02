#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer=0;
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0; i<scoville.size(); i++){
        que.push(scoville[i]);
    }
    while(que.top()<K){
        if(que.size()==1)return -1;
        int tmp=que.top();
        que.pop();
        tmp+=2*que.top();
        que.pop();
        que.push(tmp);
        answer++;
    }
    return answer;
}
