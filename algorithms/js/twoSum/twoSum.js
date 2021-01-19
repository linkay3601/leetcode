let twoSum = function(nums, target) {
    let numsN = nums.length;
    for (let i = 0; i < numsN - 1; i++) {
        for (let j = i + 1; j < numsN; j++) {
            if (nums[i] + nums[j] === target) {
                return [i, j]
            }
        }
    }
    return []
}
