class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x, sum = 0, l = 0, best = -1;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (l <= r && sum > target)
                sum -= nums[l++];

            if (sum == target)
                best = max(best, r - l + 1);
        }

        return best == -1 ? -1 : nums.size() - best;
    }
};