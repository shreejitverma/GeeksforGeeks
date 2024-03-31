/*
https://leetcode.com/problems/coin-change/
322. Coin Change
Medium

8774

223

Add to List

Share
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

//DP
//TLE
//58 / 182 test cases passed.
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        //padding ahead
        vector<int> count(amount + 1, INT_MAX);

        //base case
        for (int coin : coins)
        {
            //to ensure it won't exceed the array's size
            if (coin <= amount)
                count[coin] = 1;
        }

        // for(int i = 1; i <= amount; i++){
        //     cout << i << ", " << count[i] << " | ";
        // }
        // cout << endl;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                if (count[j] == INT_MAX || count[i - j] == INT_MAX)
                {
                    //skip this split
                    continue;
                }
                else
                {
                    count[i] = min(count[i], count[j] + count[i - j]);
                }
            }
            // cout << i << ", " << count[i] << endl;
        }
        // cout << "===========" << endl;

        return count[amount] == INT_MAX ? -1 : count[amount];
    }
};

//DP
//Runtime: 124 ms, faster than 29.29% of C++ online submissions for Coin Change.
//Memory Usage: 14.1 MB, less than 27.45% of C++ online submissions for Coin Change.
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        //padding ahead
        vector<int> count(amount + 1, INT_MAX);

        //base case
        for (int coin : coins)
        {
            //to ensure it won't exceed the array's size
            if (coin <= amount)
                count[coin] = 1;
        }

        // for(int i = 1; i <= amount; i++){
        //     cout << i << ", " << count[i] << " | ";
        // }
        // cout << endl;

        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i < coin)
                    continue;
                if (count[i - coin] == INT_MAX)
                    continue;
                count[i] = min(count[i], count[i - coin] + 1);
            }
            // cout << i << ", " << count[i] << endl;
        }
        // cout << "===========" << endl;

        return count[amount] == INT_MAX ? -1 : count[amount];
    }
};

//DP, more concise
//Runtime: 120 ms, faster than 33.17% of C++ online submissions for Coin Change.
//Memory Usage: 14 MB, less than 31.37% of C++ online submissions for Coin Change.
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        //we use "amount+1" in replace of INT_MAX
        //padding ahead
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (coin > i)
                    continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

//recursion
//Runtime: 1128 ms, faster than 5.02% of C++ online submissions for Coin Change.
//Memory Usage: 66.5 MB, less than 5.88% of C++ online submissions for Coin Change.
class Solution
{
public:
    unordered_map<int, int> memo;

    int coinChange(vector<int> &coins, int amount)
    {
        if (memo.find(amount) != memo.end())
            return memo[amount];

        if (amount == 0)
        {
            memo[amount] = 0;
            return memo[0];
        }

        if (coins.size() > 0 && amount < *min_element(coins.begin(), coins.end()))
        {
            memo[amount] = -1;
            return memo[amount];
        }

        int count = INT_MAX;
        for (int coin : coins)
        {
            //edge case
            if (amount == coin)
            {
                memo[amount] = 1;
                return memo[amount];
            }
            int remainCount = coinChange(coins, amount - coin);
            if (remainCount == -1)
                continue;
            // cout << coin << " + " << amount - coin << " : " << 1 + remainCount << endl;
            count = min(count, 1 + remainCount);
        }

        if (count == INT_MAX)
            count = -1;

        memo[amount] = count;

        return memo[amount];
    }
};

//Approach #2 (Dynamic programming - Top down)
//recursion, more concise
//Runtime: 968 ms, faster than 5.02% of C++ online submissions for Coin Change.
//Memory Usage: 61.6 MB, less than 9.80% of C++ online submissions for Coin Change.
//time: O(S*n), S(amount): recursion depth, n(coins.size()): the for loop
//space: O(S), the memo
class Solution
{
public:
    unordered_map<int, int> memo;

    int coinChange(vector<int> &coins, int amount)
    {
        //edge case of "amount = coins[?]" can be replaced with this
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (memo.find(amount) != memo.end())
            return memo[amount];

        int cost = INT_MAX;
        for (int coin : coins)
        {
            int res = coinChange(coins, amount - coin);
            if (res >= 0)
                cost = min(cost, 1 + res);
        }

        memo[amount] = (cost == INT_MAX) ? -1 : cost;
        return memo[amount];
    }
};

//backtrack
//TLE
//57 / 182 test cases passed.
//time: S is amount, ci means ith element in coins, S/c0 * S/c1 * S/cn-1 => O(S^n)
//space: O(n), recursion depth
class Solution
{
public:
    int coinChange(int idxCoin, vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (idxCoin >= coins.size() || amount < 0)
            return -1;

        int minCost = INT_MAX;
        for (int i = 0; i <= amount / coins[idxCoin]; i++)
        {
            //we use "i" coins[idxCoin]
            if (amount >= i * coins[idxCoin])
            {
                int res = coinChange(idxCoin + 1, coins, amount - i * coins[idxCoin]);
                if (res == -1)
                    continue;
                minCost = min(minCost, i + res);
            }
        }

        return (minCost == INT_MAX) ? -1 : minCost;
    };

    int coinChange(vector<int> &coins, int amount)
    {
        return coinChange(0, coins, amount);
    }
};