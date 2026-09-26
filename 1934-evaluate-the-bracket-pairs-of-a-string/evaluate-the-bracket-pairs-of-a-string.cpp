class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(vector<string>v : knowledge){
            mp[v[0]] = v[1];
        }

        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='('){
                ans += s[i];
                continue;
            }else{
                string key = "";
                i++;
                while(s[i]!=')'){
                    key += s[i];
                    i++;
                }
                if(mp.find(key)!=mp.end()) ans+=mp[key];
                else ans += '?';
            }
        }

        return ans;
    }
};