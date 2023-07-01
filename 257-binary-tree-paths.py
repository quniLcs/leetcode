# Definition for a binary tree node
class TreeNode(object):
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        self.allPaths = []
        self.findCurrentPath(root, currentPath = [])
        return self.allPaths

    def findCurrentPath(self, node, currentPath):
        currentPath.append(str(node.val))
        if node.left is None and node.right is None:
            self.allPaths.append('->'.join(currentPath))
        else:
            if node.left is not None:
                self.findCurrentPath(node.left, currentPath)
            if node.right is not None:
                self.findCurrentPath(node.right, currentPath)
        currentPath.pop()
