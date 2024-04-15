"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
import queue
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        q = queue.Queue()
        # print(root)

        if root==None:
            return root
        q.put(root)
        
        while(q.qsize()>0):
            n=q.qsize()
            for i in range(n):
                t = q.get()
                if i==n-1:
                    t.next=None
                else:
                    t.next=q.queue[0]
                if t.left!=None:
                    q.put(t.left)
                    # print(t.val,t.left.val)
                if t.right!=None:
                    q.put(t.right)
                


        return root