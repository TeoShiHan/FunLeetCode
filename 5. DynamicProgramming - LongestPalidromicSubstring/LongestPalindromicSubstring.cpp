
// █▀█ █░█ █▀▀ █▀ ▀█▀ █ █▀█ █▄░█
// ▀▀█ █▄█ ██▄ ▄█ ░█░ █ █▄█ █░▀█
// 5. Longest Palindromic Substring
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

/*


█▀ █▀█ █░░ █░█ ▀█▀ █ █▀█ █▄░█ ▄█
▄█ █▄█ █▄▄ █▄█ ░█░ █ █▄█ █░▀█ ░█
 initial algorithm design
 1. create a funtion named as check_palindrome()
         // the algorithm will be like :
         // iterate compare first(0) and last(N) and 0+1, N-1 etc, so if 
         // even then expect the iteration will no need return
         // if odd then id will return when /2+1 when i equals
         // so ... if the compare is not matched then consider not palindrom return false 
    2. after that create the function named as stringCutter, that it will extract all the possible 
       string combination in window sliding
    3. then another function as mainSearch, then it will use string cutter then verify from max to lowest untill find the solution.

class Solution {
public:
    bool check_palindrome(const string& s, int left, int right) {
        while (left < right) 
        {

            if (s[left] != s[right]) 
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        // Try all possible lengths from biggest to smallest
        for (int len = n; len >= 1; len--) 
        {
            // Sliding window for this length
            for (int start = 0; start + len - 1 < n; start++) {
                int end = start + len - 1;

                if (check_palindrome(s, start, end)) {
                    return s.substr(start, len);
                }
            }
        }

        return "";
    }
};


*/



/*
yay passed and this is the BEST solution

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)return s;
        int maxind=0;
        int maxlen=1;
        int i=0;
        while(i<s.size()){
            int start=i;
            int end=i;
            while(end+1<s.size() && s[end]==s[end+1]){
                end++;
            }
            i=end+1;
            while(start-1>=0 && end+1<s.size() &&s[start-1]==s[end+1]){
                start--;;
                end++;
            }
            int currlen=end-start+1;
            if(currlen>maxlen){
                maxind=start;
                maxlen=currlen;
            }
        }
        return s.substr(maxind,maxlen);
    }
};

// this solution is faster because it find a center eg aaaa, bbbb so aaa become single big -<A.-> then not like me search aa aaa aaaa to verify the palindromic pattern
so this is beauty of dynamic programming to see the optimization and redundant
my one is more brute force method (lazy to think haha) good lesson from bro algo


*/