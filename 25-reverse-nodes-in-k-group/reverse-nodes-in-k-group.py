# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getlength(self, head):
        length=0
        while head is not None:
            length+=1
            head=head.next

        return length

    def reverseInK(self, head, k, length):
        if k>length:
            return head

        curr=head
        prev = None
        temp = None
        cnt=0

        while curr is not None and cnt<k:
            temp=curr.next
            curr.next=prev
            prev=curr
            curr=temp
            cnt+=1

        if temp is not None:
            head.next=self.reverseInK(temp, k, length-k)

        return prev
        

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None:
            return None

        length=self.getlength(head)
        return self.reverseInK(head, k , length)