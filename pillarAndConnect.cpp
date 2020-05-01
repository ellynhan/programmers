#include <vector>
using namespace std;
bool isConnect(int x, int y, int pillar[][101], int connect[][101]){ // 당장 그 좌표에서 가능한지 확인 (보)
    if(pillar[y-1][x]||pillar[y-1][x+1]){
        return true;
    }else{
        if(connect[y][x-1]&&connect[y][x+1])return true;
    }
    return false;
}

bool isPillar(int x, int y, int pillar[][101], int connect[][101]){ // 당장 그 좌표에서 기둥이 가능한가
    if(y==0){
        return true;
    }else{
        if(pillar[y-1][x]){
            return true;
        }else{
            if(connect[y][x]||connect[y][x-1]){
                return true;
            }
        }
    }
    return false;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    int pillar[101][101];
    int connect[101][101];
    vector<vector<int>> answer;
    for(int i=0; i<n+1; i++){ //초기화
        for(int j=0; j<n+1; j++){
            pillar[i][j]=0;
            connect[i][j]=0;
        }
    }
    for(int i=0; i<build_frame.size(); i++){
        int y = build_frame[i][1];
        int x = build_frame[i][0];
        if(build_frame[i][3]==1){ //추가일때
            if(build_frame[i][2]==0){ //기둥일때
                if(isPillar(x,y,pillar,connect)){
                    pillar[y][x]=1;
                }
            }else{ // 보일때
                if(isConnect(x,y,pillar,connect)){
                    connect[y][x]=1;
                }
            }
        }else{ //삭제일때
            if(build_frame[i][2]==0){ //기둥일때
                pillar[y][x]=0;
                bool right=true;
                if(pillar[y+1][x]){
                    if(!isPillar(x,y+1,pillar,connect))right=false;
                }
                if(right&&connect[y+1][x-1]){
                    if(!isConnect(x-1,y+1,pillar,connect))right=false;
                }
                if(right&&connect[y+1][x]){
                    if(!isConnect(x,y+1,pillar,connect))right=false;
                }
                if(!right)pillar[y][x]=1;
            }else{ // 보일때
                connect[y][x]=0;
                bool right =true;
                if(right&&connect[y][x-1]){
                    if(!isConnect(x-1,y,pillar,connect))right=false;
                }
                if(right&&connect[y][x+1]){
                    if(!isConnect(x+1, y, pillar, connect))right=false;
                }
                if(right&&pillar[y][x]){
                    if(!isPillar(x,y,pillar,connect))right=false;
                }
                if(right&&pillar[y][x+1]){
                    if(!isPillar(x+1,y,pillar,connect))right=false;
                }
                if(!right)connect[y][x]=1;
            }
        }
    }
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            if(pillar[j][i]==1)answer.push_back({i,j,0});
            if(connect[j][i]==1)answer.push_back({i,j,1});
        }
    }
    return answer;
}
