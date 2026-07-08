class Solution {
public:
    vector<int> dp;

    int solve(int idx, vector<vector<int>>& jobs) {
        if (idx >= jobs.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int nextIdx =
            lower_bound(jobs.begin() + idx + 1, jobs.end(), jobs[idx][1],
                        [](const vector<int>& job, int endTime) {
                            return job[0] < endTime;
                        }) -
            jobs.begin();

        int take = jobs[idx][2] + solve(nextIdx, jobs);
        int skip = solve(idx + 1, jobs);

        return dp[idx] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();
        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        dp.resize(n, -1);

        return solve(0, jobs);
    }
};