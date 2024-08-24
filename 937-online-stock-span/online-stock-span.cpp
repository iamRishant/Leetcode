class StockSpanner {
public:
        int count;
        stack<pair<int,int>> st;//val,index
    StockSpanner() {
       count=0;
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,count});
            count++;
            return count;
        }
        else{
            while(!st.empty() && price>=st.top().first) st.pop();
            if(st.empty()){
                st.push({price,count});
                count++;
                return count;
            }
            int ans=count-st.top().second;
            st.push({price,count});
            count++;
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */