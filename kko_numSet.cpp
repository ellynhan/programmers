#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(set<int>& a, set<int>& b){
    return a.size()<b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<set<int> > group;
    set<int> tmp;
    string s_temp="";
    for(int i=1;i<s.length()-1; i++){
        if(s[i]>='0'&&s[i]<='9'){
            s_temp+=s[i];
        }else if(s[i]==','&&s[i-1]!='}'){
            tmp.insert(stoi(s_temp));
            s_temp="";
        }
        else if(s[i]=='}'){
            if(s_temp!=""){
                tmp.insert(stoi(s_temp));
                s_temp="";
            }
            group.push_back(tmp);
            tmp.clear();
        }
    }
    sort(group.begin(), group.end(),compare);
    for(int i=0; i<group.size(); i++){
        if(i==0){
            answer.push_back(*(group[0].begin()));
        }else{
            set<int>::iterator it;
            for(it=group[i].begin(); it!=group[i].end(); it++){
                if(!group[i-1].count(*it)){
                    answer.push_back(*it);
                    break;
                }
            }
        }
    }
    return answer;
}
