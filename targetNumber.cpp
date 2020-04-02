#include <vector>
using namespace std;
class Node{
    public:
        int data=0;
        int depth = 0;
        Node* l_minus;
        Node* r_plus;
};

int tree(Node* root, vector<int>& nums,int sign,int target){
    int sum=0;
    root->data +=nums[root->depth]*sign;
    root->l_minus = new Node();
    root->l_minus->depth = root->depth;
    root->l_minus->depth++;
    root->l_minus->data=root->data;
    root->r_plus = new Node();
    root->r_plus->depth = root->depth;
    root->r_plus->data = root->data;
    root->r_plus->depth++;
    if(root->depth<nums.size()-1){
    sum+=tree(root->l_minus,nums,-1,target);
    sum+=tree(root->r_plus,nums,1,target);
    }
    if(root->depth==nums.size()-1&&root->data==target){return 1;}
    return sum;
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    Node* root = new Node();
    Node* root2 = new Node ();
    answer+=tree(root,numbers,1,target);
    answer+=tree(root2,numbers,-1,target);
    return answer;
}
