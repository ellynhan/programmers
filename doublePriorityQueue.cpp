#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int count =0;
    for(auto i : operations){
        if(i[0]=='I'){
            string tmp="";
            for(int j=2; j<i.length(); j++)tmp+=i[j];
            min.push(stoi(tmp));
            max.push(stoi(tmp));
            count++;
        }else if(max.size()+min.size()>count&&max.size()>=count/2&&min.size()>=count/2){
            if(i=="D 1"){
                max.pop();
            }else{
                min.pop();
            }
        }
        if(count==max.size()+min.size()){
            while(!max.empty())max.pop();
            while(!min.empty())min.pop();
            count=0;
        }
    }
    if(count==0)answer={0,0};
    else{
        answer.push_back(max.top());
        answer.push_back(min.top());
    }
    return answer;
}
