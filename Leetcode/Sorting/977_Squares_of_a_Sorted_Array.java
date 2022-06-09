class Solution {
    public int[] sortedSquares(int[] nums) {
        int res[] = new int[nums.length];
        
//         // O(n) solution
        
        int start = 0 , end = nums.length - 1 , i = nums.length - 1;
        
        while(i>=0){
            if(nums[start]*nums[start] <= nums[end]*nums[end]){
                res[i] = nums[end]*nums[end];
                end--;
                i--;
            }
            else if(nums[start]*nums[start] > nums[end]*nums[end]){
                res[i] = nums[start]*nums[start];
                start++;
                i--;
            }
        }
        return res;
        
//         NAIVE SOLUTION = O(nlogn)
//         for(int i = 0 ; i<nums.length ; i++){
//             res[i] = (int)Math.pow(nums[i],2);
//         }
//         Arrays.sort(res);
        
//         return res;
    }
}
