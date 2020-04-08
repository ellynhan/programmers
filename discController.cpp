#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct compare{
    bool operator()(vector<int>& a, vector<int>& b){
        return a.at(1)>b.at(1);
    }
};
int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>,vector<vector<int>>,compare> average;
    int time =0,i=0,answer=0;
    sort(jobs.begin(),jobs.end());
    while(i<jobs.size()||!average.empty()){
        while(i<jobs.size()&&time>=jobs[i][0]){
            average.push(jobs[i++]);
        }
        if(!average.empty()){
            time+=average.top().at(1);
            answer+=time-average.top().at(0);
            average.pop();
        }else{
            time=jobs[i][0];
        }
        
    }
    return answer/jobs.size();
}
