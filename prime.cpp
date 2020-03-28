#include <string>
#include <vector>
#include <set>
using namespace std;

void permute(vector<char>& ele, set<int>& picked, int sz,string s,set<int>& result){
    if(s.length()==sz)result.insert(stoi(s));
    for(int i=0; i<ele.size(); i++){
        if(!picked.count(i)){
            picked.insert(i);
            permute(ele,picked,sz,s+ele[i],result);
            picked.erase(i);
        }
    }
}

bool isPrime(int num){
    if(num<2)return false;
    int mid=num/2;
    for(int i=2; i<=mid; i++){
        if(num%i==0)return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> element;
    for(int i=0; i<numbers.length(); i++){
        element.push_back(numbers[i]);
    }
    set<int> result;
    for(int i=0; i<numbers.size(); i++){
        set<int> picked;
        permute(element, picked, i+1,"",result);
    }
    set<int>::iterator it;
    for(it=result.begin(); it!=result.end(); it++){
        if(isPrime(*it))answer++;
    }
    return answer;
}
