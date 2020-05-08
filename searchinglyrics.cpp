#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Trie{
public:
    Trie *children[26];
    int depth=0;
    bool isTerminal=false;
    Trie(int a) : isTerminal(false),depth(a) {
           memset(children, NULL, sizeof(children));
    }
    ~Trie() {
        for (int i = 0; i < 26; i++){
            if (children[i])
                delete children[i];
        }
    }
    void insert(string key)
    {
        Trie *p = this;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!p->children[index])
                p->children[index] = new Trie((p->depth)+1);
    
            p = p->children[index];
        }
        p->isTerminal = true;
    }
    Trie* search(string key)
    {
        Trie *p = this;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!p->children[index])
                return NULL;
            
            p = p->children[index];
        }

        return p;
    }
    int counting(string part, int len){
        Trie *root = search(part);
        if(root==NULL)return 0;
        int cnt =0;
        queue<Trie*> q;
        q.push(root);
        while(!q.empty()){
            Trie *p = q.front();
            q.pop();
            for(int i=0; i<26; i++){
                if(p->children[i]!=NULL){
                    q.push(p->children[i]);
                    if(p->children[i]->depth==len&&p->children[i]->isTerminal)cnt++;
                }
            }
        }
        return cnt;
    }
};
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int>answer(queries.size());
    Trie proot(0);
    Trie sroot(0);
    for(int i=0; i<words.size(); i++){
        proot.insert(words[i]);
        reverse(words[i].begin(),words[i].end());
        sroot.insert(words[i]);
    }
    for(int i=0; i<queries.size(); i++){
        int len = queries[i].length();
        string tmp;
        int cnt=0;
        if(queries[i][0]=='?'){
            while(queries[i][cnt]=='?'){cnt++;}
            tmp = queries[i].substr(cnt,len-cnt);
            reverse(tmp.begin(),tmp.end());
            answer[i]=sroot.counting(tmp,len);
        }else{
            while(queries[i][len-cnt-1]=='?'){cnt++;}
            tmp = queries[i].substr(0,len-cnt);
            answer[i]=proot.counting(tmp,len);
        }
    }
    return answer;
}
