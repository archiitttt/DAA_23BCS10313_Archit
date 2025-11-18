class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : arr[st.top()];
            st.push(i);
        }

        return ans;
    }
};
