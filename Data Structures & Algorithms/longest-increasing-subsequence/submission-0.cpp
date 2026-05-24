class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,1);
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j < n; j++){
                if(nums[i] < nums[j]){
                    v[i] = max(v[i], 1+v[j]);
                }
            }
        }
        return *max_element(v.begin(), v.end());
    }
};