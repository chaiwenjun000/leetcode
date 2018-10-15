/*
前缀和。 Runtime: 156 ms, faster than 47.25%

用 vector代替 sum,比较慢
Runtime: 204 ms, faster than 27.54% of C++
 */

class NumArray {
public:
    int sum[100010];
    NumArray(vector<int> nums) {
        int sz = nums.size();
        if(sz == 0) return;
        sum[0] = nums[0];
        for(int i=1;i<sz;i++){
            sum[i] = sum[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        int back = 0;
        if(i != 0)
            back = sum[i-1];
        return sum[j] - back;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 *
 * 
 */