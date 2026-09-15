class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i + k - 1 < n; ) {

            bool found = false;

            // palindrome of length k
            if (isPalindrome(s, i, i + k - 1)) {
                ans++;
                i += k;
                found = true;
            }

            // palindrome of length k+1
            else if (i + k < n && isPalindrome(s, i, i + k)) {
                ans++;
                i += k + 1;
                found = true;
            }

            if (!found) i++;
        }

        return ans;
    }
};