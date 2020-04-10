#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<int> nums(1,1);
    string a,b;
    int answer=s.length();
    for(int i=1; i<=s.length()/2; i++){ // 덩어리크기
        int _answer=0;
        for(int j=0; j+2*i<=s.length(); j+=i){
            a=s.substr(j,i);
            b=s.substr(j+i,i);
            if(a==b){
                nums.back()++;
            }else{
                nums.push_back(1);
            }
        }
        for(int j=0; j<nums.size(); j++){
            _answer+=to_string(nums[j]).length()+i;
            if(nums[j]==1)_answer-=1;
        }_answer+=s.length()%i;
        nums.clear();
        nums.push_back(1);
        if(answer>_answer)answer=_answer;
    }
    return answer;
}
