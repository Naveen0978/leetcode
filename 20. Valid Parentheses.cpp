class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length();i++)
        {
            if(s[i] == '[' or s[i] == '{' or s[i] == '(')
                st.push(s[i]);
            else
            {
                if(st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if(  (s[i] == ']' and ch == '[') or
                    (s[i] == ')' and ch == '(') or
                    (s[i] == '}' and ch == '{'));
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
