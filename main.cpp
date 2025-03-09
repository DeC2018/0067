#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string ans = "";

        while(i >= 0 || j >= 0 || carry){
            if(i >= 0) 
                carry += a[i--] - '0';
            if(j >= 0) 
                carry += b[j--] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    string a1 = "11";
    string b1 = "1";
    string result1 = solution.addBinary(a1, b1);
    cout << "Input: a = \"11\", b = \"1\"" << endl;
    cout << "Output: \"" << result1 << "\"" << endl;

    // Example 2
    string a2 = "1010";
    string b2 = "1011";
    string result2 = solution.addBinary(a2, b2);
    cout << "Input: a = \"1010\", b = \"1011\"" << endl;
    cout << "Output: \"" << result2 << "\"" << endl;

    return 0;
}
