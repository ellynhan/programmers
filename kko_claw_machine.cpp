#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> bucket;
    int answer = 0;
    for(int i=0; i<moves.size(); i++){
        for(int j=0; j<board.size(); j++){
            int tmp = board[j][moves[i]-1];
            if(tmp!=0){
                if(bucket.size()>=1&&bucket.top()==tmp){
                    bucket.pop();
                    answer+=2;
                }else{
                    bucket.push(tmp);
                }
                board[j][moves[i]-1]=0;
                break;
            }
        }
    }
    return answer;
}
