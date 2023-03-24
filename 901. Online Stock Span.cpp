class StockSpanner {
    stack <pair<int,int>> st;
    int index = -1;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        index ++;
        while(!st.empty() && st.top().first <= price)
            st.pop();
        
        if(st.empty())
        {
            st.push({price,index});
            return index+1;
        }
        int res = st.top().second;
        st.push({price,index});
        return index-res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
