class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> st;
        int left[n], right[n];
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
            
            if(st.empty())
                left[i] = -1;
            else
                left[i] = st.top().second;
            
            st.push({heights[i],i});
        }
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();
            
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top().second;
            
            st.push({heights[i],i});
        }

        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, heights[i]*(right[i]-left[i]-1));
        }
        return maxi;
    }
};
