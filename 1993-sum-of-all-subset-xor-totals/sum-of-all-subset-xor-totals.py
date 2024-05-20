class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)

        def find_sum(cur_ind, cur_num):
            if cur_ind == n: 
                return cur_num

            include_in_xor = find_sum(cur_ind + 1, cur_num ^ nums[cur_ind])
            not_include_in_xor = find_sum(cur_ind + 1, cur_num) 

            return include_in_xor + not_include_in_xor 

        return find_sum(0, 0)