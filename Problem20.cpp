/*
	Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

	An input string is valid if:

	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.
	Note that an empty string is also considered valid.

	Example 1:

	Input: "()"
	Output: true
	Example 2:

	Input: "()[]{}"
	Output: true
	Example 3:

	Input: "(]"
	Output: false
	Example 4:

	Input: "([)]"
	Output: false
	Example 5:

	Input: "{[]}"
	Output: true

	SOLUTION:-

	Using the idea that {[( should be pushed on the stack and after meeting every }]) 
	stack should be popped
	If in the end the stack is empty that means every opening bracket has got its closing bracket
	The catch here is [{]} this is invalid hence once we get the closing brace the stack top should
	be its equivalent opening brace
	if not the we have some invalid string like [{]} this and hence should return false
*/
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       char ch;
       for(char &ch :s){
       	if(ch==']'||ch==')'||ch=='}'){
       		if(!st.empty()&&((int)st.top()-(int)ch==-1||(int)st.top()-(int)ch==-2)){
       			st.pop();
       		}
       		else{
       			return false;
       		}
       	}
       	else{
       		st.push(ch);
       	}
       }
       if(st.empty()){
       	return true;
       }
       return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string str;
	cin>>str;
	cout<<s.isValid(str);
	return 0;
}