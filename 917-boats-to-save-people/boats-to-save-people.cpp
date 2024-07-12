class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int s=0;
        int e=people.size()-1;
        int boat=0;
        int sum=0;
        while(s<=e){

            // if(s==e){
            //     return boat+1;
            // }
            // else{
                sum=(people[s]+people[e]);
                if(sum<=limit){
                    boat++;
                    s++;
                    e--;
                    continue;
                }
                else{
                    boat++;
                    e--;
                }
            // }
            
        }
        return boat;
    }
};