/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).





Solution 1:
comparitorIndex=0
1. start iterate with N[comparitorIndex]
2. compare N[comparitorIndex] with [N+i], swapIndex=1
3. if duplicate, ignore, next iteration will compare N[comparitorIndex] with [N+i] again.
4. if non duplicate, then 
    OPERATION = SWAP element with swapIndex, 
    UPDATE    = swapIndex++, i++, ca  



class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0) {
            return 0;
        }

        int comparatorIndex = 0;
        int swapIndex = 1;
        int i = 1;

        while (i < nums.size()) 
        {
            if (nums[comparatorIndex] == nums[i]) 
            {
                i++;
            } 
            else 
            {
                nums[swapIndex] = nums[i];
                comparatorIndex = swapIndex;
                swapIndex++;
                i++;
            }
        }

        return swapIndex;
    }
};

*/