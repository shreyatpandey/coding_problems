/*
Given a sorted array A of unique numbers, find the K-th missing number starting from the leftmost number of the array.
Example 1:

Input: A = [4,7,9,10], K = 1
Output: 5
Explanation: 
The first missing number is 5.
*/
class Solution {
    private:
        int missingnumber(int indexvalue,vector<int>&nums)
        {
            return ( nums[indexvalue] - nums[0] - indexvalue);
        }
public:
    int missingElement(vector<int>& nums, int k) {
        int numslength = nums.size();
        
        if( k > missingnumber (numslength-1,nums))
            return nums[numslength-1] + k - missingnumber(numslength-1,nums) ;
        
        int low = 0 , high = numslength-1 , mid = 0;
        while ( low != high)
        {
            mid = low + (high-low)/2;
            if ( missingnumber(mid,nums)<k)
                low = mid+1;
            else
                high = mid;
        }
        return ( nums[low-1] + k - missingnumber(low-1,nums));
        
    }
};
