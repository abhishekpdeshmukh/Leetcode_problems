//.Question-:
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example 1:

// Input: 2
// Output: [0,1,1]
// Example 2:

// Input: 5
// Output: [0,1,1,2,1,2]
// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

	// Solution:-

	// The idea is very simple and elegant,we have to calculate the number of bits that are 1
	// The first solution that pops up in your mind is iterating over the range and finding
	// finding out the number of 1s for every number.But this is O(size of number*n),as bigger 
	// number will require more to find the number of 1s.So as always we find a pattern,we compute 
	// something and try to find future values using something we already know.The pattern goes 
	// like this :-
	// 1)if num is even :Num of 1 bits =number if 1 bits in num/2
	// 2)if numis odd:Num of 1 bits =1+number if 1 bits in num-1
	
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
    	int n;
    	vector<int>v3;
    	v3.push_back(0);
    	if(num==0)return v3;
    	v3.push_back(1);
    	for(int i=2;i<=num;i++){
    		n=0;
    		if(i%2==0){
			n=v3[i/2];
			}
			else{
				n=1+v3[i-1];
			}
			v3.push_back(n);
    	}	
    	return v3;
    }
};

int main(int argc, char const *argv[])
{
	int n;
    Solution s;
    vector<int>v1;
    cin>>n;
    v1=s.countBits(n);
    for(int i=0;i<v1.size();i++){
    	cout<<i<<" ->"<<v1[i]<<"\n";
    }
    cout<<"\n";
	return 0;
}