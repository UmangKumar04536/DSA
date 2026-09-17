class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);
        unordered_map<int, int> mp;

        int sum = 0, ans = INF;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // Best subarray ending at or before i
            if (i > 0)
                best[i] = best[i - 1];

            if (mp.count(sum - target)) {
                int start = mp[sum - target] + 1;
                int len = i - start + 1;

                // Combine with a previous non-overlapping subarray
                if (start > 0 && best[start - 1] != INF)
                    ans = min(ans, len + best[start - 1]);

                best[i] = min(best[i], len);
            }

            mp[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};