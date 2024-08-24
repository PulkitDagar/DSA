class Solution {
public:
    int coinChangeHelper(vector<int>& coins, int amount, vector<int>& dp) {
        // Base case: If amount is 0, no coins are needed
        if (amount == 0) return 0;
        // If the amount is negative, it's impossible to make change
        if (amount < 0) return INT_MAX;
        // If we already have a result stored for the current amount, return it
        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;  // Initialize the answer with a large value

        // Try every coin and see which gives the minimum number of coins
        for (int i = 0; i < coins.size(); i++) {
            int res = coinChangeHelper(coins, amount - coins[i], dp);
            if (res >= 0 && res < ans) {
                ans = res + 1;
            }
        }

        // Store the computed result in dp array
        dp[amount] = ans;

        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp array with -1 to indicate uncomputed values
        vector<int> dp(amount + 1, -1);
        int answer =  coinChangeHelper(coins, amount, dp);
        if(answer == INT_MAX){
            return -1;
        }
        else{
            return answer;
        }
    }
};