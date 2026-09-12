class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original_index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by start time
        sort(a.begin(), a.end());

        // dp[i][k] = best answer starting from i,
        // choosing at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        // Find first interval whose start > current end
        auto nextIndex = [&](int end) {
            int l = 0, r = n;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (a[mid][0] > end)
                    r = mid;
                else
                    l = mid + 1;
            }

            return l;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take current interval
                dp[i][k] = dp[i + 1][k];

                // Option 2: take current interval
                int nxt = nextIndex(a[i][1]);

                long long newWeight =
                    a[i][2] + dp[nxt][k - 1].first;

                vector<int> selected =
                    dp[nxt][k - 1].second;

                selected.push_back(a[i][3]);

                sort(selected.begin(), selected.end());

                // Compare with current best
                if (newWeight > dp[i][k].first ||
                    (newWeight == dp[i][k].first &&
                     selected < dp[i][k].second)) {

                    dp[i][k] = {
                        newWeight,
                        selected
                    };
                }
            }
        }

        return dp[0][4].second;
    }
};