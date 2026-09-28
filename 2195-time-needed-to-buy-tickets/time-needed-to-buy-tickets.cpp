class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        // calculate left
        int n = t.size();
        int left = 0;
        for(int i=0;i<k;i++){
            if(t[i]>=t[k]) left+=t[k];
            else left+=t[i];
        }

        // calculate right 
        int right = 0;
        for(int i=k+1;i<n;i++){
            if(t[i]>=t[k]) right+=(t[k]-1);
            else left+=t[i];
        }

        return left+right+t[k];
    }
};