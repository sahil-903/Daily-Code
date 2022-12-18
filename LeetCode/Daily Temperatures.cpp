class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums2) {
        stack<int> st{};
        map<int,int> mp;
        vector<int> v(nums2.size(),0);
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums2[st.top()]<=nums2[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                v[i]=st.top()-i;
            }
            st.push(i);
            
        }
        return v;
    }
};
