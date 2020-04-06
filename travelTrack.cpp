#include <string>
#include <vector>
#include <set>
using namespace std;
void connect(string before, vector<vector<string>>& tickets, vector<int>& visited, string track,set<string>& ms){
    if(track.length()==(tickets.size()+1)*3)ms.insert(track);
    for(int i=0; i<tickets.size(); i++){
        if(visited[i]==1)continue;
        if(tickets[i][0]==before){
            visited[i]=1;
            connect(tickets[i][1],tickets,visited,track+tickets[i][1],ms);
            visited[i]=0;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<int> visited(tickets.size(),0);
    set<string> myset;
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0]=="ICN"){
            string track="ICN"+tickets[i][1];
            visited[i]=1;connect(tickets[i][1],tickets, visited,track,myset);
            visited[i]=0;
        }
    }
    string tmp="";
    for(int i=0; i<myset.begin()->length(); i++){
        tmp+=myset.begin()->at(i);
        if(i%3==2){
            answer.push_back(tmp);
            tmp="";
        }
    }
    return answer;
    
}
