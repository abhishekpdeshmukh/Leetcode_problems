/*
QUESTION:-

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].	

*/


/*
SOLUTION EXPLANATION

Since we have to lookup every element atleast once,the fastest algorithm if it exist will
be atleast O(n).Assuming such algorithm do exist I tried to solve it in linear time
Ok lets get this straight we dont have any additional information about the sorted nature
of the array hence it is obvious that we have to use a very efficient datastructure in 
addition to the given vector.Hence i took a unordered map.By iterating over every element 
we ask the question whether we have seen the complement of that element previously(complement =abs(target-current))
If we have,then we have found our pair of numbers/indices,else we just add the element and its index
to the unordered_map
*/
//Caution:-You can't directly submit it to leetcode,the output is not in the desired format
#include <iostream>
#include<unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,target;
	unordered_map<int,int>unmap;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){cin>>arr[i];}
	cin>>target;
	for(int j=0;j<n;j++){
		if(unmap.count(abs(target-arr[j]))){
			cout<<j<<" "<<unmap[abs(target-arr[j])]<<"\n";
			break;
		}
		else{
			unmap[arr[j]]=j;
		}
	}
	return 0;
}
