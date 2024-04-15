# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp= head
        if temp == None or temp.next==None:
            return temp
        tn = head.next
        while(tn!=None):
            a=temp.val
            temp.val=tn.val
            tn.val=a
            temp=tn.next
            tn=tn.next
            if tn!=None:
                tn = tn.next
            
        return head

        
        