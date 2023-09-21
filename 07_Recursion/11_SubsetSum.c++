/*
You are given an array 'nums'of 'n' integers.
Return all subset sums of 'nums' in a non-decreasing order.
Input: nums = [1, 2]
Output :0 1 2 3
*/

/*
Approach: using pick and not pick approach
1. Keep making not picking calls, when you are not adding the current element to the sum unitl the base condition fullfilled.
2. keep making picking calls, when you are adding the current element to the sum unitl the base condition fullfilled.
3. Once i reaches the end of the array, base condition will fullfilled. till now, what sum you have get stored it in answer.
4. Perform Backtracking by removing current element form the sum, when you return from the function call after base condition fullfilled.

TC: O(2^n), SC: O(n)
*/

/*
void findSubsetSums(int index, int sum, vector<int> &num, vector<int> &ans){
	if(index >= num.size()){
		ans.emplace_back(sum);
		return;
	}
	//not pick call
	findSubsetSums(index+1, sum, num, ans);
	//pick call
	findSubsetSums(index+1, sum+num[index], num, ans);
	//backtrack
	sum-=num[index];
}
vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	findSubsetSums(0, 0, num, ans);
	sort(ans.begin(), ans.end());
	return ans;	
}
*/