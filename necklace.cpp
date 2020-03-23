#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findNextPoint(int pre,vector<vector<int>>& point,vector<int>& isChecked){
    int result=0;
    if(isChecked[isChecked.size()-1]){return 1;} //기저
    for(int i=pre+1; i<isChecked.size(); i++){
        if(!isChecked[i]&&point[i][0]-point[i][1]-point[pre][0]+point[pre][1]==point[i][2]){
            isChecked[i]=1;
            result+=findNextPoint(i,point,isChecked);
            isChecked[i]=0;
        }
    }
    return result;
}


vector<int> solution(int n, vector<vector<int>> point, vector<vector<int>> query) {
    sort(point.begin(),point.end()); //첫번째 원소가 S, 마지막 원소가 E
    vector<int> isChecked; //첫번째원소를 true로 바꿔줄 필요는 없지.
    isChecked.assign(n,0);
    vector<int> answer(n+1,0);
    vector<vector<int>> tmp;
    answer[0]=findNextPoint(0,point,isChecked)%1000000007;
     for(int i=0; i<n; i++){
        tmp=point;
        vector<int> qPoint={query[i][1],query[i][2],query[i][3]};
         if(query[i][0]==0){
             tmp.push_back(qPoint);
            sort(tmp.begin(),tmp.end());
             isChecked.assign(n+1,0);
         }else{
             vector<vector<int>>::iterator it;
             for(it=tmp.begin(); it!=tmp.end(); it++){
                 if((*it)[0]==qPoint[0]){tmp.erase(it);break;}
             }

             isChecked.assign(n-1,0);
         }
        answer[i+1]=findNextPoint(0,tmp,isChecked)%1000000007;
    }
    return answer;
}

int main(){
    vector<int> out;
    out=solution(3,{{0,4,1},{2,2,4},{4,0,4}},{{0,3,3,4},{0,3,1,2},{1,2,2,0}});
    for(int i=0; i<out.size(); i++){
        cout<<out[i]<<" ";
    }
}
