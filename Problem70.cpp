/*
	Problem 70:-https://leetcode.com/problems/climbing-stairs/
	
	You are climbing a stair case. It takes n steps to reach to the top.

	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

	Note: Given n will be a positive integer.

	Example 1:

	Input: 2
	Output: 2
	Explanation: There are two ways to climb to the top.
	1. 1 step + 1 step
	2. 2 steps
	Example 2:

	Input: 3
	Output: 3
	Explanation: There are three ways to climb to the top.
	1. 1 step + 1 step + 1 step
	2. 1 step + 2 steps
	3. 2 steps + 1 step

	Solution:-

	This is a simple dynamic programming problem whoes solution is exactly like the fibonacii
	series.Here just take any random mth step and ask the question how many ways exist to
	get here.The answer is the number of ways required we can to step-1 plus the number of ways
	we can go to step -2
	dp[step]=dp[step-1]+dp[step-2]
	which is the same as fibonacci
	f(n)=f(n-1)+f(n-2)
*/
#include<iostream>
#include<vector>
class Solution {
public:
    int climbStairs(int n) {
        int array[n+1];
        array[0]=1;
        array[1]=1;
        for(int i=2;i<=n;i++){
            array[i]=(array[i-1]+array[i-2]);
        }
        return array[n];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int n;
	std::cin>>n;
	std::cout<<s.climbStairs(n);
	return 0;
}