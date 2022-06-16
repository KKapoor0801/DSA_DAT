class Solution {
public:
    
    void wb(string input, set<string> st, vector<string>& res, string currOutput){
        
        if(input.size() == 0){
            res.push_back(currOutput);
            return;
        }
        
        string temp = "";
        for(int pos = 0 ; pos<input.size() ; pos++){
            
            temp += input[pos];
            if(st.find(temp) != st.end()){
                
                string prevOutput = currOutput;
                
                for(auto it : temp)
                    prevOutput.push_back(it);
                
                string partitionedInput = input.substr(pos+1);
                
                if(partitionedInput.size() != 0)
                    prevOutput.push_back(' ');
                
                wb(partitionedInput,st,res,prevOutput);
            }
        }
        return;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        string curr = "";
        string input = s;
        vector<string> res;
        
        set<string> st;
        for(auto a: wordDict){
            st.insert(a);
        }
        
        wb(input,st,res,curr);
        return res;
    }
};
