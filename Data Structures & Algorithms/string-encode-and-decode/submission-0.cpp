class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        int n = strs.size();
        for(int i = 0; i < n; i++){
            s+=strs[i];
            s+="|";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        string ts = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == '|'){
                v.push_back(ts);
                ts = "";
            } else
                ts += c;
        }
        return v;
    }
};
