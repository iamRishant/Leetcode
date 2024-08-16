class MyStack {
public:
    int f1,f2,r1,r2;
    int q1[100000],q2[10000];
    MyStack() {
        f1=0;
        r1=0;
        f2=0;
        r2=0;
        
    }
    
    void push(int x) {
        
        while(f1!=r1){
            int cur=q1[f1];
            f1++;
            q2[r2]=cur;
            r2++;
        }
        q1[r1]=x;
        r1++;
        while(f2!=r2){
            int curr=q2[f2];
            f2++;
            q1[r1++]=curr;
        }
    }
    
    int pop() {
        return q1[f1++];
    }
    
    int top() {
        return q1[f1];
        
    }
    
    bool empty() {
        if(f1==r1) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */