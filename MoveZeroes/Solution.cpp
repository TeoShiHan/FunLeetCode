/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?




Solution simplest

1. variable of zeroCounter
2. create a vector of same size
3. if is not zero, then insert to vector
4. if is zero add to counter
5. if traverse complete, insert zero into array as counter remained.

// But cannot have a copyt of array ..........


maybe can do it like

bubble sorting? if zero then swap forward? then
// can maybe not fast 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for (int pass = 0; pass < n; pass++) {
            for (int i = 0; i + 1 < n; i++) {
                if (nums[i] == 0 && nums[i + 1] != 0) {
                    swap(nums[i], nums[i + 1]);
                }
            }
        }
    }
};

// super slowwwwwwwwww

// maybe we can do it like this
so ....

we will have record the insertionIndex be it zero,
so every traverse one step we will do insert,

so....

and the insertion index only update when it is not zero.

then if not zero, we will put the non zero value into
insertionIndex

if it is zero , then do nothing
then at last clear the array tail.


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }

        while (insertPos < nums.size()) {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};



*/


