// I don't like my answer. I need to think more -_-
#include <string>
#include <vector>

using namespace std;

int first[5]={1,2,3,4,5};
int second[8]={2,1,2,3,2,4,2,5};
int third[10]={3,3,1,1,2,2,4,4,5,5};
int counts[3]={0,0,0};
               
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==first[i%5]) counts[0]++;
        if(answers[i]==second[i%8]) counts[1]++;
        if(answers[i]==third[i%10]) counts[2]++;
    }
    if(counts[0]>counts[1]){
        if(counts[0]>counts[2]){
            answer.push_back(1);
        }else if(counts[0]==counts[2]){
            answer.push_back(1);
            answer.push_back(3);
        }else{
            answer.push_back(3);
        }
    }else if(counts[0]==counts[1]){
        if(counts[0]>counts[2]){
            answer.push_back(1);
            answer.push_back(2);
        }else if(counts[0]==counts[2]){
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else{
            answer.push_back(3);
        }
    }else{
        if(counts[1]>counts[2]){
            answer.push_back(2);
        }else if(counts[1]==counts[2]){
            answer.push_back(2);
            answer.push_back(3);
        }else{
            answer.push_back(3);
        }
    }
    return answer;
}
