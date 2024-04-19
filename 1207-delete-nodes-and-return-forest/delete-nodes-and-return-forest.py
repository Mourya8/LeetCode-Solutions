# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

import queue
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        r =[]
        q =queue.Queue()
        q.put(root)
        if not root.val in to_delete:
            r.append(root)
        while(q.qsize()!=0):
            temp = q.get()
            if temp.val in to_delete:
                if temp.right!=None and not(temp.right.val in to_delete):
                    r.append(temp.right)
                if temp.left!=None and not(temp.left.val in to_delete):
                    r.append(temp.left)
            if temp.right!=None:
                    q.put(temp.right)
                    if (temp.right.val in to_delete):
                        temp.right=None

            if temp.left!=None:
                    q.put(temp.left)
                    if temp.left.val in to_delete:
                        temp.left = None
        
        return r
            
            
