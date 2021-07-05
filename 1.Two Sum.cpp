class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,ele1,ele2,j;
        //we are going to use map for this problem, can also use two pointer concept
        unordered_map<int,int> mp;
        for(i=0;i<nums.size();i++){
            mp[nums[i]]=i+1;
        }
        vector<int> vc;
        //now for each element in nums we search (target-nums[i]) in the map
        for(i=0;i<nums.size();i++){
            if(mp[(target-nums[i])]!=0&&(mp[(target-nums[i])]-1)!=i){
                vc.push_back(i);
                vc.push_back(mp[(target-nums[i])]-1);
                break;
            }
        }
        return vc;
    }
};
