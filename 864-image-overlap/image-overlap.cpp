class Solution {
    int n;
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2,int row,int col) {
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int bi = row+i;
                int bj = col+j;

                if(bi<0 || bi>=n || bj<0 || bj>=n) continue;
                if(img1[i][j]==1 && img2[bi][bj]==1) count++;
            }
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        int maxOverlap = 0;

        for(int rowOff=-n+1;rowOff<n;rowOff++){
            for(int colOff=-n+1;colOff<n;colOff++){
                maxOverlap = max(maxOverlap, countOverlap(img1,img2,rowOff,colOff));
            }
        }

        return maxOverlap;
    }
};