#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    multimap<string,int> slot;
    for(int i=0; i<clothes.size(); i++){
        if(slot.count(clothes[i][1])){
            (slot.find(clothes[i][1])->second)++;
        }else{
            slot.insert(make_pair(clothes[i][1],1));
        }
    }
    int answer=1;
    multimap<string,int>::iterator it;
    for(it=slot.begin(); it!=slot.end(); it++){
        answer*=it->second+1;
    }
    return answer-1;
}
