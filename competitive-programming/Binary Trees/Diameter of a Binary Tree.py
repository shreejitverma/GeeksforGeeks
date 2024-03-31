'''https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
Diameter of a Binary Tree 
Easy Accuracy: 50.01% Submissions: 100k+ Points: 2
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000'''

# Python3 program to find the diameter of binary tree

# A binary tree node


class Node:

    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# The function Compute the "height" of a tree. Height is the
# number of nodes along the longest path from the root node
# down to the farthest leaf node.

def height(node):

    # Base Case : Tree is empty
    if node is None:
        return 0

    # If tree is not empty then height = 1 + max of left
    # height and right heights
    return 1 + max(height(node.left), height(node.right))

# Function to get the diameter of a binary tree


def diameter(root):

    # Base Case when tree is empty
    if root is None:
        return 0

    # Get the height of left and right sub-trees
    lheight = height(root.left)
    rheight = height(root.right)

    # Get the diameter of left and right sub-trees
    ldiameter = diameter(root.left)
    rdiameter = diameter(root.right)

    # Return max of the following tree:
    # 1) Diameter of left subtree
    # 2) Diameter of right subtree
    # 3) Height of left subtree + height of right subtree +1
    return max(lheight + rheight + 1, max(ldiameter, rdiameter))


# Driver Code
"""
Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
"""

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

# Function Call
print(diameter(root))


def vip(self, root):
    #global m
    if(root == None):
        return(0)
    lh = self.vip(root.left)
    rh = self.vip(root.right)
    global m
    m = max(m, lh+rh+1)
    # print(m)
    return(1+max(lh, rh))
   # Function to return the diameter of a Binary Tree.


def diameter(self, root):
    global m
    m = 0
    self.vip(root)
    return(m)
