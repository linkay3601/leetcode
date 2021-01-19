'''
思路：
             j
        /^^^^^^^^^^\
    [1, 2, 3, 4, 5, 6]
    \____________/
          i
'''

def twoSum3(nums: list[int], target: int) -> list[int]:
    numsN = len(nums)
    for i in range(numsN - 1):
        for j in range(i + 1, numsN):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []


def twoSum2(nums, target):
    numsN = len(nums)
    for i in xrange(numsN - 1):
        for j in xrange(i + 1, numsN):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []
