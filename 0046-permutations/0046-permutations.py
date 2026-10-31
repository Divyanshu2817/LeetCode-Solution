class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res=[]
        def backtrap(path):
            if len(path)==len(nums):
                res.append(list(path))
                return
            for num in nums:
                if num in path:
                    continue
                path.append(num)
                backtrap(path)
                path.pop()
        backtrap([])
        return res