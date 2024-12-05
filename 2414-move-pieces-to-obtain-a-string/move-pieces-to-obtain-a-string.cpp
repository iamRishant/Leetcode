class Solution {
public:
    bool canChange(string start, string target) {
        int curr=0;
        int j=0;
        int n=start.length();
        while(curr<n){
            while(curr<n && target[curr]=='_') curr++;
            while(j<n && start[j]=='_') j++;
            // now both are either pointing to end, same character or diff character
            if(curr==n && j==n) return true;
            else if(curr==n && j!=n) return false;
            else if(curr!=n && j==n) return false;
            else{
                //both are pointing to a character
                if(start[j]!=target[curr]) return false;
                else{
                    //if both are equal
                    if(target[curr]=='L'){
                        if(curr>j) return false;//we can only move left and target if ahead
                        else{
                            // possible 
                            j++;
                            curr++;
                        }
                    }
                    else{
                        if(curr<j) return false;
                        else{
                            j++;
                            curr++;
                        }
                    }
                }
            }
        }
        while(j<n && start[j]=='_') j++;

        return j==n;
    }
};