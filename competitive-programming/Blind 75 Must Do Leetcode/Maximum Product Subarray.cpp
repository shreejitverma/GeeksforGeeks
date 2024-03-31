/*
https://leetcode.com/problems/maximum-product-subarray/
152. Maximum Product Subarray
Medium

8690

272

Add to List

Share
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
*/

//TLE
//183 / 184 test cases passed.
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int> > dp(n, vector(n, 1));
        int ans = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                //[i...j]
                // cout << i << ", " << j << endl;
                if (j == i)
                {
                    //interval of length 1
                    dp[i][j] = nums[i];
                }
                else
                {
                    dp[i][j] = nums[i] * dp[i + 1][j];
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

//O(n) DP
//https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
//Runtime: 8 ms, faster than 40.36% of C++ online submissions for Maximum Product Subarray.
//Memory Usage: 11.8 MB, less than 5.00% of C++ online submissions for Maximum Product Subarray.
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = nums[0];
        int curmax = nums[0], curmin = nums[0];

        for (int i = 1; i < n; i++)
        {
            /*
            multiplied by a negative makes big number smaller, 
            small number bigger
            so we redefine the extremums by swapping them
            */
            if (nums[i] < 0)
            {
                swap(curmax, curmin);
            }

            /*
            note the first item of max() is nums[i], not curmax!!
            it either extends the previous found subarray or
            create a new subarray
            */
            curmax = max(nums[i], curmax * nums[i]);
            curmin = min(nums[i], curmin * nums[i]);

            ans = max(curmax, ans);
        }

        return ans;
    }
};