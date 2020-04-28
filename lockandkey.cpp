#include <vector>
using namespace std;
vector<vector<int>> rotation(vector<vector<int>>& key){
    vector<vector<int>> result(key.size(),vector<int>(key.size()));
    for(int i=0; i<key.size(); i++){
        for(int j=0; j<key.size(); j++){
            result[i][j]=key[key.size()-1-j][i];
        }
    }
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> locks(lock.size()*3,vector<int>(lock.size()*3,2));
    int holes=0;
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock.size(); j++){
            locks[lock.size()+i][lock.size()+j]=lock[i][j];
            if(lock[i][j]==0)holes++;
        }
    }
    for(int cnt =0; cnt<4; cnt++){
        for(int i=0; i<lock.size()*2; i++){
            for(int j=0; j<lock.size()*2; j++){
                int count =0;
                for(int y=i; y<key.size()+i; y++){
                    int right=1;
                    for(int x=j; x<key.size()+j; x++){
                        if(locks[y][x]==2)continue;
                        if(key[y-i][x-j]==1&&locks[y][x]==1){
                            right=0;
                            break;
                        }
                        if(key[y-i][x-j]==1&&locks[y][x]==0){
                            count++;
                        }
                    }
                    if(right==0)break;
                }
                if(count==holes){return true;}
            }
        }
        key=rotation(key);
    }
     return false;    
}
