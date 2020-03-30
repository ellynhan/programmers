#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> result(heights.size(),0);
    for(int i=heights.size()-1; i>-1; i--){
        for(int j=i-1; j>-1; j--){
            if(heights[i]<heights[j]){
                result[i]=j+1;
                break;
            }
        }
    }
    return result;
}
