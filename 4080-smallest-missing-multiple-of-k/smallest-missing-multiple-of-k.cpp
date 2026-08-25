class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        for(int num: nums){
            if(num%k==0) st.insert(num);
        }

        for(int i=1;i<=100;i++){
            if(st.find(i*k)==st.end()) return i*k;
        }

        return k*101;
    }
};