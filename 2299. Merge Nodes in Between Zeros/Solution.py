# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tempsum=0
        temp=head
        tail=head
        tailprev=tail
        while(temp!=None):
            if temp.val==0 and tempsum!=0:
                tail.val=tempsum
                tailprev=tail
                tail=tail.next
                tempsum=0
            else:
                tempsum=tempsum+temp.val
            temp=temp.next
        if tempsum!=0:
            tail.val=tempsum
            tailprev=tail
        tailprev.next=None

        return head
        