/*
		https://leetcode.com/problems/maximum-subarray
		Problem:-53

		Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

		Example:

		Input: [-2,1,-3,4,-1,2,1,-5,4],
		Output: 6
		Explanation: [4,-1,2,1] has the largest sum = 6.

		Follow up:

		If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

		Solution:-

		This problem is very easy but hard to explain,still let me give it a try
		Now lets assume that you are at the nth position 
		So the question of that element being in the final subarray is answered by asking the fact
		that is the ***BEST SUM OF PREVIOUS*** +this element >this element	
		If yes then it should be in the final subarray,else it should be independent
		In nutshell you have to check whethere an element is fit to be in the final subarray			
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int dp[nums.size()];
    	int sum=nums[0];
    	dp[0]=nums[0];
    	for(int i=1;i<nums.size();i++){
    		if(nums[i]<dp[i-1]+nums[i]){
    			dp[i]=dp[i-1]+nums[i];
    		}
    		else{
    			dp[i]=nums[i];
    		}
    		if(dp[i]>sum){
    			sum=dp[i];
    		}
    	}
    	return sum;
    }
};

int main(int argc, char const *argv[])
{
	int n,length;
	Solution s;
	vector<int>v;
	cin>>length;
	for(int i=0;i<length;i++){
		cin>>n;
		v.push_back(n);	
	}
	cout<<s.maxSubArray(v);
	return 0;
}