
// █▀█ █░█ █▀▀ █▀ ▀█▀ █ █▀█ █▄░█
// ▀▀█ █▄█ ██▄ ▄█ ░█░ █ █▄█ █░▀█
// Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// You may assume the input array always has a valid answer.

 

// Example 1:

// Input: nums = [1,5,1,1,6,4]
// Output: [1,6,1,5,1,4]
// Explanation: [1,4,1,5,1,6] is also accepted.
// Example 2:

// Input: nums = [1,3,2,2,3,1]
// Output: [2,3,1,3,1,2]
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 5000
// It is guaranteed that there will be an answer for the given input nums.
 


// Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?



// █▀ █▀█ █░░ █░█ ▀█▀ █ █▀█ █▄░█ ▄█
// ▄█ █▄█ █▄▄ █▄█ ░█░ █ █▄█ █░▀█ ░█
// initial algorithm design
// 1. sort the array
// 2. seperate them to the half
// 3. interleaf them.
// why i this can work?
/*
 Why this can work because the questions want to have the pattern of first 
 element is smaller than second, but the second element is larger than the 
 third one. So if I separate the array, I sort it and then separate it, 
 then I merge them to interleave them. Then I was thinking that this is 
 guaranteed that the first element is always the smaller, and then the 
 second one is always the bigger, and then I switch back again, then the 
 third one is the smaller one. So means the patterns will work.


however how about if the last element in array, just same as the last - 1 element?
left  = [1,1,2]
right = [2,2,3]

1 < 2 ✅
2 > 1 ✅
1 < 2 ✅
2 > 2 ❌ fail

[2,3,1,2,1,2] this work and algo

█▀ █▀█ █░░ █░█ ▀█▀ █ █▀█ █▄░█ ▀█
▄█ █▄█ █▄▄ █▄█ ░█░ █ █▄█ █░▀█ █▄

so how to prevent this happening? or reduce change, maybe we create different in
delta larger like 2,1,1 | 3,2,2


this way the left side is largest and right side is also the largest.
then the same number is look like "seperate further to extreme" see, the 2 and 2 now
is very far to each other.

so we can have this : 
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        int mid = (n + 1) / 2;

        vector<int> left(sorted.begin(), sorted.begin() + mid);
        vector<int> right(sorted.begin() + mid, sorted.end());

        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());

        int i = 0;
        for (int x : left) {
            nums[i] = x;
            i += 2;
        }

        i = 1;
        for (int x : right) {
            nums[i] = x;
            i += 2;
        }
    }
};

█▀ █▀█ █░░ █░█ ▀█▀ █ █▀█ █▄░█
▄█ █▄█ █▄▄ █▄█ ░█░ █ █▄█ █░▀█
Here is the top one solution unlocked yay just more efficient

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        // 左半部結尾 (較小群組的最大值)
        int left = (n + 1) / 2 - 1; 
        // 右半部結尾 (較大群組的最大值)
        int right = n - 1;          

        for (int i = 0; i < n; i++) {
            // 偶數索引放左半部 (逆序取)
            if (i % 2 == 0) {
                nums[i] = sorted[left--];
            } 
            // 奇數索引放右半部 (逆序取)
            else {
                nums[i] = sorted[right--];
            }
        }
    }
};




*/ 

