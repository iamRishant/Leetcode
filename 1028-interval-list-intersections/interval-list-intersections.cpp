class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
     vector<vector<int>> store;
     for(int i=0;i<firstList.size();i++){
        store.push_back(firstList[i]);
     }   
     for(int i=0;i<secondList.size();i++){
        store.push_back(secondList[i]);
     }
     sort(store.begin(),store.end());

     int prev=0;
     vector<vector<int>> ans;
    //  int curr=1;
    for(int i=1;i<store.size();i++){
        if(store[i][0]>store[prev][1]){

            if(store[i][1]>store[prev][1]) prev=i;
            // continue;
        }
        else{
            vector<int> temp;
            // temp.push_back();
            ans.push_back({max(store[prev][0],store[i][0]),min(store[prev][1],store[i][1])});
        }
        if(store[i][1]>store[prev][1]) prev=i;
    }
    return ans;

    }
};