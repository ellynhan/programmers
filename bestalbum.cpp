#include <string>
#include <vector>
#include <map>
using namespace std;
struct Node{
    int primeNum;
    int playNum;
    int sum=0;
    struct Node* next=NULL;
};

void swapNode(Node* first, Node* second){
    int tmp = first->playNum;
    first->playNum=second->playNum;
    second->playNum=tmp;
    tmp=first->primeNum;
    first->primeNum=second->primeNum;
    second->primeNum=tmp;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,Node*> table;
    map<string,Node*>::iterator it;
    for(int i=0; i<genres.size(); i++){
        if(table.count(genres[i])){
            Node* pre =table.find(genres[i])->second;
            if(pre->next){ // 이미 있고 2번째 노드도 있다
                if(plays[i]>pre->next->playNum){ //change
                    pre->next->playNum=plays[i];
                    pre->next->primeNum=i;
                }
            }else{ // 장르 한개만 저장되어있다
                Node* Next=new Node;
                Next->primeNum=i;
                Next->playNum=plays[i];
                pre->next=Next;
            }
            pre->sum=plays[i]+pre->playNum;
            if(plays[i]>pre->playNum){ //swap
                swapNode(pre->next,pre);
            }
        }else{
            Node* tmp=new Node;
            tmp->primeNum=i;
            tmp->playNum=tmp->sum=plays[i];
            table.insert(make_pair(genres[i], tmp));
        }
    }
    multimap<int,string,greater<int>> comp;
    multimap<int,string,greater<int>>::iterator iter;
    for(it=table.begin(); it!=table.end(); it++){
        comp.insert(make_pair(it->second->sum, it->first));
    }
    for(iter=comp.begin(); iter!=comp.end(); iter++){
        Node* tmp = table.find(iter->second)->second;
        answer.push_back(tmp->primeNum);
        if(tmp->next){
            answer.push_back(tmp->next->primeNum);
        }
    }
    return answer;
}
