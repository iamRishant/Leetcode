class MyCalendar {
    map<int,int> mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
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
            if(count>=2){
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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */