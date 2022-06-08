class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {0};
        string ans;
        for(int i = 0 ; i<s.size() ; i++){
            freq[s[i] - 'a'] += 1; //Frequency of each character of s
        }
        
        //Add characters of order to ans which are present in s
        for(int i = 0 ; i<order.size() ; i++){
            while(freq[order[i] - 'a'] != 0){
                ans += order[i];
                freq[order[i] - 'a'] -= 1;
                
            }
        }
        
        // Add remaining characters of s to ans which were not present order
        for(int i = 0 ; i<s.size() ; i++){
            if(freq[s[i] - 'a'] != 0){
                ans += s[i];
                freq[s[i] - 'a'] -= 1;
            }
        }
        return ans;
    }
};
