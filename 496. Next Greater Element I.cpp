class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n);
        
        int m = nums2.size();
        vector<int> ans2(m);

        stack<pair<int,int>> st;
        map<int,int> mp;

        for(int i = m-1; i>=0;i--)
        {
            mp[nums2[i]] = i;
            while(!st.empty() && st.top().first <= nums2[i])
                st.pop();
            
            if(i<m)
            {
                if(!st.empty())
                    ans2[i] = st.top().first;
                else
                    ans2[i] = -1;
            }
            st.push({nums2[i],i});
        }

        for(int i=0; i<n;i++)
        {
            ans[i] = ans2[mp[nums1[i]]];
        }
        return ans;
    }
};
