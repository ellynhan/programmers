#include <set>
#include <queue>
#include <vector>
using namespace std;
void connect(int computer, vector<vector<int>>& c, set<int>& ms){
    vector<int> link=c[computer];
    queue<int> temp;
    ms.erase(computer);
    for(int i=0; i<link.size(); i++){
        if(link[i]==1&&ms.count(i)){
            temp.push(i);
        }
    }
    while(!temp.empty()){
        connect(temp.front(),c,ms);
        temp.pop();
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    set<int> myset;
    for(int i=0; i<n; i++)myset.insert(i);
    while(!myset.empty()){
        answer++;
        connect(*myset.begin(), computers, myset);
    }
    return answer;
}
