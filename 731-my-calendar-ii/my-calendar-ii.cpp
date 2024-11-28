class MyCalendarTwo {
    map<int,int> mp;

public:
    MyCalendarTwo() {
        // int count=0;
    }
    
    bool book(int startTime, int endTime) {
        // mp[startTime]++;
        // mp[endTime]--;
        if(mp.size()==0){
            mp[startTime]++;
            mp[endTime]--;
            return true;
        }
        int count=0;
        mp[startTime]++;
        mp[endTime]--;
        for(auto it=mp.begin();it!=mp.end();it++){
            count+=it->second;
            // check if sweep line result in 3
            if(count>=3){
                // cancel the booking
                mp[startTime]--;
                mp[endTime]++;
                
                return false;
            }

        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */