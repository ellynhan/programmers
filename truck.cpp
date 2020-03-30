#include <vector>
using namespace std;

struct truck{
    int weight;
    int location=0;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time=0, current_weight=0,now=0,done=0;
    vector<truck> onTheBridge;
    do{
        time++;
        for(int i=0; i<onTheBridge.size(); i++){
            onTheBridge[i].location++;
        }
        if(!onTheBridge.empty()&&onTheBridge[0].location==bridge_length+1){
            current_weight-=onTheBridge[0].weight;
            onTheBridge.erase(onTheBridge.begin());
            done++;
        }
        if(current_weight+truck_weights[now]<=weight){
            truck newTruck;
            newTruck.weight=truck_weights[now];
            newTruck.location++;
            current_weight+=newTruck.weight;
            now++;
            onTheBridge.push_back(newTruck);
        }
        for(int j=0; j<onTheBridge.size(); j++){
        }
    }while(truck_weights.size()-done);
    return time;
}
