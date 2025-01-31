class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x==y){
            return x==target;
        }

        if(target==x+y) return true;
        if(target>x+y) return false;

        long long Y=max(x,y);
        long long X=min(x,y);

        while(Y!=0){
            if(Y-X>=0) Y-=X;
            else{
                X-=Y;
                Y=max(x,y);
                if(X==target || Y==target || X+Y==target) return true;
                Y-=X;
                X=min(x,y);
            }
            if(X==target || Y==target || X+Y==target) return true;
        }
        return false;
    }
};