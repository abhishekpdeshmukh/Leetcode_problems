/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

----------------------------------------------------------------------------------------
SOLUTION EXPLANATION:-

    Extract the digits from the number by using the simple digit=number%10 logic
    Keep pushing the digits onto the stack which will ineffect reverse the digits of number
    then just start creating the reverse the number by multiplying by its positional power
    and adding to previous number
    ie-: units place-multiplier=1
         tense place-multiplier=10
    So on and so forth
*/
#include<iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        stack<int>v;
        int digit=0,originalnumber=0,newnumber=0,multiplier=1;
        originalnumber=x;
        if(x<0){
            return false;
        }
        while(x>0){
            digit=x%10;
            v.push(digit);
            x=(int)x/10;
        }
        while(!v.empty()){
            newnumber+=v.top()*multiplier;
            v.pop();
            multiplier*=10; 
        }
        if(newnumber==originalnumber){
            return true;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution t;
    int n;
    cin>>n;
    cout<<t.isPalindrome(n);
    return 0;
}