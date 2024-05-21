class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        def backtrack(start, path):
            result.append(path[:])
            for i in range(start, len(nums)):
            # Include nums[i] in the current subset
                path.append(nums[i])
            # Continue with the next elements
                backtrack(i + 1, path)
            # Backtrack by removing nums[i] from the current subset
                path.pop()
        backtrack(0, [])
        return result