class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {  
         int n = nums.size();
        int Sum = (n*(n+1))/2;
        for(int i=0;i<n;i++)
        {
            Sum -= nums[i];
        }

        return Sum;;       
    }
};
