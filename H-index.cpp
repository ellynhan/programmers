#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int max_count=0;
    int max=citations.size();
    for(int i=citations.size()-1; i>-1; i--){
        if(citations[i]<max){
            if(citations[i]>max_count){
                max=citations[i];
            }else max=max_count;
        }
        max_count++;
        if(max_count>=max){return max;}
    }
}
