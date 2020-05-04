int recur(vector<vector<int>>& map,vector<int>& current, int cnt, int di){
    int y = current[0];
    int x = current[1];
    int n = map.size();
    int check=0,tmp =0;
    int result =10000;
    if(y==n-1&&x==n-1){
        result = cnt;
    }else{
        if(x<n-1&&map[y][x+1]==0){ //오른쪽이동
            current[1]++;
            result = recur(map,current,++cnt);
        }else check ++;
        if(y<n-1&&map[y+1][x]==0){ //아래로 이동
            if(di==0){d
                
            }
            current[0]++;
            tmp=recur(map,current,++cnt);
            if(tmp<result)result=tmp;
        }else check++;
        if(check==2)return 10000;
    }
    return result;
}
