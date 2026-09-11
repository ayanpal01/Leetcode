class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>v(10,0);
        int count = 0;
        
        for(int d : digits) v[d]++;

        for(int i=1;i<=9;i++){
            if(v[i]==0) continue;
            v[i]--;
            for(int j=0;j<=9;j++){
                if(v[j]==0) continue;
                v[j]--;
                for(int k=0;k<=8;k+=2){
                    if(v[k]==0) continue;
                    int num = i*100 + j*10 + k;
                    count++;
                }
                v[j]++;
            }
            v[i]++;
        }
        return count;
    }
};