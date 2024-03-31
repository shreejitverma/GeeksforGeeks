'''https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1

Remove Consecutive Characters 
Basic Accuracy: 56.33% Submissions: 10963 Points: 1
Given a string S delete the characters which are appearing more than once consecutively.

Example 1:

Input:
S = aabb
Output:  ab 
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.

Example 2:

Input:
S = aabaa
Output:  aba
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
'a' at fifth position is appearing
2nd time consecutively.
 

Your Task:
You dont need to read input or print anything. Complete the function removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string. 
 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).
 

Constraints:
1<=|S|<=105
All characters are lowercase alphabets.'''
# User function Template for python3


class Solution:
    def removeConsecutiveCharacter(self, S):
        # code here
        st = []
        s1 = ''
        for i in range(len(S)):
            if (st and st[-1] != S[i]) or not st:
                st.append(S[i])
        while st:
            s1 += st.pop()
        return s1[::-1]

# {
#  Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        s = input()
        ob = Solution()
        print(ob.removeConsecutiveCharacter(s))

# } Driver Code Ends
