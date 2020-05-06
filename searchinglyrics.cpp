#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    int wvs=int(words.size());
    int qvs=int(queries.size());
    vector<int> answer(qvs,0);
    for(int i=0; i<wvs; i++){
        int ws=int(words[i].size());
        for(int j=0; j<qvs; j++){
            int qs=int(queries[j].size());
            if(ws!=qs)continue;
            int qws=0;
            if(queries[j][0]=='?'){
                while(queries[j][qws]=='?'){qws++;}
                qws=qs-qws;
                if(words[i].compare(qs-qws,qws,queries[j],qs-qws,qws)==0){
                    answer[j]++;
                }
            }else{
                while(queries[j][qws]!='?'){qws++;}
                if(words[i].compare(0,qws,queries[j],0,qws)==0){
                    answer[j]++;
                }
            }
            
        }
    }
    return answer;
}
