/*
Problem Statement: School is organizing a team contest. You are given an array 'SKILL' containing the skill level of 'N' candidates. Two candidates(having index 'i' and 'j') can pair up to form a team
if for index i < j, SKILL[i] > 2*SKILL[j] Your task is the return the count of all the possible pairs to take part in the contest.
*/

/*
Approach: Using merge sort algorithm
TC:O(N logN) [merge sort] + O(N logN)[pair function uses same kind of approach as merge sort]
SC: O(N)
*/
/*
void merge(vector<int>&skill, int low, int mid, int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(skill[left] > skill[right]) temp.push_back(skill[right++]);
        else temp.push_back(skill[left++]);
    }
    while(left <= mid){
        temp.push_back(skill[left++]);
    }
    while(right <= high){
        temp.push_back(skill[right++]);
    }

    for(int i=low; i<=high; i++){
        skill[i] = temp[i-low];
    }
}
int pairs(vector<int>&skill, int low, int mid, int high){
    int cnt = 0;
    int right = mid+1;
    for(int i=low; i<=mid; i++){
        while(right <= high && skill[i] > 2*skill[right]) right++;
        cnt += right - (mid+1);
    }
    return cnt;
}
int mergeSort(vector<int>&skill, int low, int high){
    int cnt = 0;
    if(low>=high) return cnt;
    int mid = low+(high-low)/2;
    cnt += mergeSort(skill, low, mid);
    cnt += mergeSort(skill, mid+1, high);
    //find reverse pairs before merging
    cnt += pairs(skill, low, mid, high);
    merge(skill, low, mid, high);
    return cnt;
}
int team(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n-1);
}

*/