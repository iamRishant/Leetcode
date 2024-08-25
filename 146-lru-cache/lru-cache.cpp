class LRUCache {
public:
     class node {
      public:
        int key;
        int val;
        node * next;
        node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    int cap;
    unordered_map < int, node * > mp;
    LRUCache(int capacity) {
        cap=capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void addNode(node *newnode){
        node * temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
        head->next=newnode;
    }
    void deletenode(node *delnode){
        node * delnext=delnode->next;
        node * delprev=delnode->prev;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    
    int get(int key_) {
        if(mp.find(key_)!=mp.end()){
            int res=mp[key_]->val;
            node * curr=mp[key_];
            deletenode(curr);
            addNode(curr);
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        // now in puttint there can be two case if the key already exist or not
        // in not also there will be two case if capacity is reached or not

        if(mp.find(key_)!=mp.end()){
            // it means key exist
            auto currnode=mp[key_];
            currnode->val=value;
            deletenode(currnode);
            addNode(currnode);
        }
        else{
            if(mp.size()<cap){
                node * newnode=new node(key_,value);
                mp[key_]=newnode;
                addNode(newnode);
            }
            else{
                // it means capacity is full there fore  first we need to delete then add this node
                node * newnode=new node(key_,value);
                node * nodetobedeleted=tail->prev;
                mp.erase(nodetobedeleted->key);
                deletenode(nodetobedeleted);
                mp[key_]=newnode;
                addNode(newnode);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */