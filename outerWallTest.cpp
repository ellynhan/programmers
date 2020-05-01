#include <algorithm>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int min=dist.size()+1;
    do{
        if(min==-1)min=dist.size()+1;
        for(int i=0; i<weak.size(); i++){
            int friends=0,current =0,next=0;
            while(next!=weak.size()&&friends<dist.size()){
                current=weak[next];
                for(int i=0; i<dist[friends]; i++){
                    current++;
                    if(current==n)current=0;
                    if(current==weak[next+1])next++;
                }
                next++;
                friends++;
            }
            if(next==weak.size()&&min>friends)min=friends;
            int tmp=0,k=0;
            for(; k<weak.size()-1; k++){
                tmp=weak[k];
                weak[k]=weak[k+1];
                weak[k+1]=tmp;
            }
            weak[k]=tmp;
        }
        if(min==dist.size()+1){min=-1;}
    }while(next_permutation(dist.begin(),dist.end()));
    return min;
}
