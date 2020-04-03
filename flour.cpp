#include <queue>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0,now=0;
    priority_queue<int> pq;
    dates.push_back(k);
    for(int i=0; i<dates.size(); i++){
        while(stock<dates[i]-now){
            stock+=pq.top();
            pq.pop();
            answer++;
        }
        pq.push(supplies[i]);
        stock-=dates[i]-now;
        now=dates[i];
    }
    return answer;
}
