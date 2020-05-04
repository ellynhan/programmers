int bfs(vector<vector<int>>& map, vector<int> c){ //(y,x,direction) direction 0 1 2 3 오 왼 위 아래
    int n=map.size()-2;
    vector<vector<int>> move ={{0,1},{0,-1},{-1,0},{1,0}};
    queue<vector<int>> q;
    q.push(c);
    while(!q.empty()){
        vector<int> now = q.front();
        q.pop();
        if((now[0]==n&&now[1]==n)||(now[2]==0&&now[0]==n&&now[1]==n-1)||(now[2]==3&&now[0]==n-1&&now[1]==n)){
            return now[3];
        }
        if(now[2]==0||now[2]==1){
            for(auto a : move){
                if(map[now[0]+a[0]][now[1]+a[1]]==0&&map[now[0]+a[0]][now[1]+now[2]*-2+1+a[1]]==0){
                    q.push({now[0]+a[0],now[1]+a[1],now[2],now[3]+1});
                }
            }
            if(map[now[0]+1][now[1]]==0&&map[now[0]+1][now[1]+now[2*-2+1]]==0){//회전가능
                q.push({now[0]+1,now[1]+1+now[2]*-2,2,now[3]+1});
                q.push({now[0],now[1],3,now[3]+1});
            }
        }else{
            for(auto a : move){
                if(map[now[0]+a[0]][now[1]+a[1]]==0&&map[now[0]+(now[2]-2)*2-1+a[0]][now[1]+a[1]]==0){
                    q.push({now[0]+a[0],now[1]+a[1],now[2],now[3]+1});
                }
            }
            if(map[now[0]][now[1]+1]==0&&map[now[0]+(now[2]-2)*-2+1][now[1]+1]==0){//회전가능
                if(now[2]==2){
                    q.push({now[0],now[1],0,now[3]+1});
                    q.push({now[0]-1,now[1]+1,1,now[3]+1});
                }else{
                    q.push({now[0]+1,now[1]+1,1,now[3]+1});
                    q.push({now[0],now[1],0,now[3]+1});
                }
            }
        }
    }
    return 10000;
}
int main(){
    vector<vector<int>> board={{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}};
    vector<int> current ={1,1,0,0};//y,x,direction(0,1,2,3) // 오 왼 위 아 , depth
    vector<vector<int>> map;
    for(int i=0; i<board.size(); i++){
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
    cout<<bfs(map,current);
    return 0;
}
