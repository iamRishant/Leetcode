class Trie {
private:
    struct Node{
        Node * children[26];
        bool isEnd=false;
    };
public:
    Node * getNode(){
        Node *newNode= new Node();
        newNode->isEnd=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    Node *root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        Node * mover=root;
        for(int i=0;i<word.size();i++){
            if(mover->children[word[i]-'a']==NULL){
                Node *temp=getNode();
                mover->children[word[i]-'a']=temp;
                mover=temp;
            }
            else mover=mover->children[word[i]-'a'];
        }
            mover->isEnd=true;
    }
    
    bool search(string word) {
        Node * mover=root;
        for(auto ch:word){
            if(mover->children[ch-'a']==NULL) return false;
            mover=mover->children[ch-'a'];
        }
        if(mover !=NULL && mover->isEnd) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node * mover=root;
        int i=0;
        for(;i<prefix.size();i++){
            if(mover->children[prefix[i]-'a']==NULL) return false;
            mover=mover->children[prefix[i]-'a'];
        }
        if(i==prefix.size()) return true;
        
        return false;
    }
};

/**'
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */