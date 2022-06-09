class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        
        // For Corner Cases where all array elts are 0 so output sould be 0  
        // and not a series of 0s like 00...0
        int fl = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == 0)
                fl++;
        }
        if(fl == nums.size()) return "0";
        
        
        // Logic to form the largest number. Logic is IMPORTANT!
        string ns1 = "", ns2 = "";
        long int num1, num2;
        int temp;
        for(int i = 0 ; i<nums.size() ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                ns1 = to_string(nums[i]) + to_string(nums[j]);
                ns2 = to_string(nums[j]) + to_string(nums[i]);
                
                if(stol(ns1) >= stol(ns2)) continue;
                else{
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        
        
        // This can also be used to check if nums has only zeroes as after sorting if the largest
        // number is 0 in the beginning then all elts are 0s
        // if(nums[0] == 0) return "0";
        
        // Once all the numbers in the nums array are arranged to form the largest number,
        // they are concatenated to the ans string.
        string ans = "";
        for(int i = 0; i<nums.size() ; i++){
            ans += to_string(nums[i]);
        }
        
        return ans;
    }
};
