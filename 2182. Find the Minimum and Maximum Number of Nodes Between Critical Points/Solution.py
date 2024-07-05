# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        critical=[]
        left = head
        head = head.next
        right=head.next
        counter=1
        mind=100001
        maxd=-1
        
        while right!=None:
            if (left.val-head.val)*(right.val-head.val)>0:
                if len(critical)>0:
                    mind=min(mind,abs(critical[-1]-counter))
                critical.append(counter)

            left=left.next
            head=head.next
            right=right.next
            counter+=1
        
        if len(critical)<=1 :
            return [-1,-1]
        
        return [mind,critical[-1]-critical[0]]
        