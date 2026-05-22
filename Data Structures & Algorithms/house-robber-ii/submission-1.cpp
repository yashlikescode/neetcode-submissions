class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int house1 = 0,house2 = 0;
        int res1 = 0;
        int sizen = nums.size();
        for(int i = 0; i < sizen-1; i++){
            int n = nums[i];
            int temp = max(n+house1,house2);
            house1 = house2;
            house2 = temp;
        }
        res1 = house2;
        house1 = 0;
        house2 = 0;
        
        for(int i = 1; i < sizen; i++){
            int n = nums[i];
            int temp = max(n+house1,house2);
            house1 = house2;
            house2 = temp;
        }
        return (max(house2,res1));
    }
};
