class Solution {
public:
    
    bool isPalin(string str){
        int start = 0, end = str.size() - 1;
        while(start <= end){
            if(str[start] != str[end])
                return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
    
    void pp(string& s, vector<vector<string>>& res, vector<string> curr, int i){
        
        if(i == s.size()){
            res.push_back(curr);
            return;
        }
        
        string temp = "";
        for(int pos = i ; pos<s.size() ; pos++){

            temp += s[pos];
            if(isPalin(temp)){
                curr.push_back(temp);
                pp(s,res,curr,pos+1);
                curr.pop_back();
            }
        }
        return;
    }
    
    
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector<vector<string>> res;
        
        vector<string> curr;
        
        pp(s, res, curr, 0);
        return res;
        
    }
};
