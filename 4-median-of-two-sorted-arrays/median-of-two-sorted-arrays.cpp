class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        int ind1=(n1+n2)/2;
        int ind2=ind1-1;

        int ind1ele=-1;
        int ind2ele=-1;
        int count=0;
        while(i<n1 && j<n2){
            if(nums1[i]>nums2[j]){
                if(count==ind1){
                    ind1ele=nums2[j];
                }
                if(count==ind2){
                    ind2ele=nums2[j];
                }
                j++;
                count++;
            }
            else{
                if(count==ind1){
                    ind1ele=nums1[i];
                }
                if(count==ind2){
                    ind2ele=nums1[i];
                }
                i++;
                count++;
            }
        }

        while(i<n1){
            if(count==ind1){
                    ind1ele=nums1[i];
                }
                if(count==ind2){
                    ind2ele=nums1[i];
                }
                i++;
                count++;
        }
        while(j<n2){
            if(count==ind1){
                    ind1ele=nums2[j];
                }
                if(count==ind2){
                    ind2ele=nums2[j];
                }
                j++;
                count++;
        }
        if((n1+n2)%2!=0){
            return ind1ele;
        }
        return (double)(ind1ele+ind2ele)/2.0;
    }
};