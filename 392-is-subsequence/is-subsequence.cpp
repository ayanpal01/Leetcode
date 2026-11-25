class Solution {
public:
    bool isSubsequence(string s, string t) {
        int nS = s.size();
        int nT = t.size();

        int idxS=0, idxT=0;

        while(idxS<nS){
            while(s[idxS]!=t[idxT]) {
                idxT++;
                if(idxT>=nT) return false;
            }
            idxS++;
            idxT++;
            // if(idxT>=nT && idxS!=nS) return false;
        }
        if(idxS==nS) return true;
        return false;
    }
};