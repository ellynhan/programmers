#include <vector>
using namespace std;

bool isMostBig(vector<int>& p){
    int me = p[0];
    for(int i: p){if(me<i) return false;}
    return true;
}

int solution(vector<int> priorities, int location) {
    int count=1;
    while(!priorities.empty()&&!(location==0&&isMostBig(priorities))){
        if(!isMostBig(priorities)){
            priorities.push_back(priorities[0]);
            count--;
        }
        priorities.erase(priorities.begin());
        if(location==0)location=priorities.size();
        location--;
        count++;
    }
    return count;
}
