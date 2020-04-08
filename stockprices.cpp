#include <stack>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<int> s;
    s.push(0);
    for(int i=1; i<prices.size(); i++){
        while(!s.empty()&&prices[i]<prices[s.top()]){
            answer[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()]=prices.size()-s.top()-1;
        s.pop();
    }
    return answer;
}
