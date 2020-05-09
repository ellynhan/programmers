#include <vector>
#include <queue>
using namespace std;
int mx[4]={1,0,-1,0}; //오른쪽 아래 왼쪽 위
int my[4]={0,-1,0,1}; // move x, move y
int _x[2]={1,0}; // 사이드가 오른쪽인경우, 아래쪽인경우.
int _y[2]={0,1};

int solution(vector<vector<int>> board) {
    vector<vector<int>> map;
     for(int i=0; i<board.size(); i++){ // 경계 없애기
        vector<int> tmp(board.size()+2,1);
        if(i==0)map.push_back(tmp);
        for(int j=0; j<board.size(); j++){
            tmp[j+1]=board[i][j];
        }
        map.push_back(tmp);
        if(i==board.size()-1){
            tmp.assign(board.size()+2, 1);
            map.push_back(tmp);
        }
    }
    int n=map.size()-2;
    bool visited[102][102][2]{};
    vector<int> curr ={1,1,0}; // y, x, k(k는 가로인지 세로인지. 0가로, 1세로), cnt
    queue<vector<int>> q;
    q.push(curr);
    visited[1][1][0]=1;
    int answer =0;
    while(!q.empty()){
        int qs =q.size();
        while(qs--){vector<int> now = q.front(); q.pop();
        int y = now[0];
        int x = now[1];
        int k = now[2];
        int yy = y + _y[k];
        int xx = x + _x[k];
        if((y == n && x == n)||(yy == n && xx == n)) return answer;
        
        for(int i=0; i<4; i++){ //이동
            int ny = y + my[i]; //new y, new x
            int nx = x + mx[i];
            int nyy = yy + my[i];
            int nxx = xx + mx[i];
            if(map[ny][nx]==0 && map[nyy][nxx]==0 && visited[ny][nx][k]==0){
                visited[ny][nx][k]=1;
                q.push({ny,nx,k});
            }
        }
        if(k==0){//가로
            if(map[y+1][x]==0 && map[yy+1][xx]==0){
                if(visited[y][x][1]==0){
                    visited[y][x][1]=1;
                    q.push({y,x,1});
                }
                if(visited[yy][xx][1]==0){
                    visited[yy][xx][1]=1;
                    q.push({yy,xx,1});
                }
            }
            if(map[y-1][x]==0 && map[yy-1][xx]==0){
                if(visited[y-1][x][1]==0){
                    visited[y-1][x][1]=1;
                    q.push({y-1,x,1});
                }
                if(visited[yy-1][xx][1]==0){
                    visited[yy-1][xx][1]=1;
                    q.push({yy-1,xx,1});
                }
            }
        }else{//세로
            if(map[y][x-1]==0 && map[yy][xx-1]==0){
                if(visited[y][x-1][0]==0){
                    visited[y][x-1][0]=1;
                    q.push({y,x-1,0});
                }
                if(visited[yy][xx-1][0]==0){
                    visited[yy][xx-1][0]=1;
                    q.push({yy,xx-1,0});
                }
            }
            if(map[y][x+1]==0 && map[yy][xx+1]==0){
                if(visited[y][x][0]==0){
                    visited[y][x][0]=1;
                    q.push({y,x,0});
                }
                if(visited[yy][xx][0]==0){
                    visited[yy][xx][0]=1;
                    q.push({yy,xx,0});
                }
            }
        }}
        answer++;
    }
}
