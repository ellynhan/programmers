#include <string>
#include <vector>
#include <set>
using namespace std;
void process(vector<vector<int>>& jobs, vector<int>&used, int timeline,int sum,set<int>& average){
    int check=0;
    for(int i : used){if(i==0)check++;}
    if(check!=0){
        for(int i=0; i<jobs.size(); i++){
            int tmp = timeline;
            if(used[i]==1)continue;
            used[i]=1;
            if(jobs[i][0]>tmp)tmp=jobs[i][0];
            tmp+=jobs[i][1];
            process(jobs,used,tmp,sum+tmp-jobs[i][0],average);
            used[i]=0;
        }
    }else{
        average.insert(sum/jobs.size());
        return ;
    }
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<int> used(jobs.size(),0);
    set<int> average;
    int timeline=0,sum=0;
    timeline+=jobs[0][1];
    used[0]=1;
    sum=timeline-jobs[0][0];//현재 있는 위치에서 요청위치를 뺌 = 걸린 시간
    process(jobs,used,timeline,sum,average);
    answer=*average.begin();
    return answer;
}
