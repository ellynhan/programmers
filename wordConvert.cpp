#include <string>
#include <vector>
#include <set>
using namespace std;

void compare(string begin, string target, vector<string>& words, vector<int>& used,set<int>& answers){
    if(begin==target){
        int sum=0;
        for(auto i:used)if(i==1)sum++;
        answers.insert(sum);
        return ;
    }
    for(int i=0; i<words.size(); i++){
        if(used[i]==1)continue;
        int count =0;
        for(int j=0; j<words[i].length(); j++)if(words[i][j]==begin[j])count++;
        if(count==words[i].size()-1){
            used[i]=1;
            compare(words[i],target,words,used,answers);
            used[i]=0;
        }
    }
    return ;
}

int solution(string begin, string target, vector<string> words) {
    set<int> answers;
    vector<int> used(words.size(),0);
    compare(begin, target, words, used,answers);
    if(answers.empty()){
        return 0;
    }else
    return *answers.begin();
}
