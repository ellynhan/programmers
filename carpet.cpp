#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer={3,3};
    for(int i=1; i<=red/2; i++){
        if(red%i==0){
            int width=red/i;
            if((width+2)*(i+2)-red==brown){
            answer[0]=i+2;
            answer[1]=width+2;
            break;
        }
        }
    }
    sort(answer.rbegin(), answer.rend());
    return answer;
}
