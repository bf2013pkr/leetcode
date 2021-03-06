#include<iostream>
#include<set>
#include<utility>
#include<vector>
#include<random>

using namespace std;
typedef set<pair<int,pair<int,int>>> fuck;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
	{	
		fuck ansset;
		vector<vector<int> >ans;
		if(nums.size()<3)return ans;
        shuffle(nums);
        
        sort(nums);
        /* n^2 time-complexity */ 
        for(int i = 0; i <nums.size()-2; i++)
    	{
    		if(nums[i] > 0)break;
    		int j= i+1;
			int k = nums.size()-1;
			while(j < k)
			{
				if(nums[k]+nums[j]>-nums[i])k--;
				else if (nums[k]+nums[j]<-nums[i])j++;
				else
				{
					ansset.insert(make_pair(nums[i],make_pair(nums[j],nums[k])));
					j++;
					k--;
				}
		
			}		
		}
		for(fuck::iterator i = ansset.begin(); i != ansset.end(); i++)
		{
			vector<int>temp;
			temp.push_back((*i).first);
			temp.push_back((*i).second.first);
			temp.push_back((*i).second.second);
			ans.push_back(temp);
		}
		return ans;
		
    }
/* TLE
    void sort (vector<int>& nums)
    {
    	for(int i = 0; i < nums.size()-1; i++)
    	{
    		for(int j = 0; j<nums.size()-i-1; j++)
    		{
    			if(nums[j]>nums[j+1])
    			{
    				int temp = nums[j];
    				nums[j] = nums[j+1];
    				nums[j+1] = temp;
				}
			}
		}
		for(int i = 0; i < nums.size(); i++)
			cout<<nums[i]<<' ';
	}
	*/
	void sort (vector<int>& nums)
    {
    	quicksort(nums,0,nums.size()-1);	
    }
    
    void quicksort(vector<int>& nums,int b,int e)
    {
    	if(e>b)
    	{
    	   int p = partition(nums,b,e);
    	   quicksort(nums,b,p-1);
    	   quicksort(nums,p+1,e);
		}
	}
	
	int partition(vector<int>& nums, int b, int e)
	{
		int i =b+1;
		int j = e;
		int pivot = nums[b];
		while (i <= j)
		{
			if(nums[i] >pivot)
			{
				swap(nums[i],nums[j]);
				j--;
			}
			else i++;
		}
		swap(nums[b],nums[i-1]);
		return i-1;
	}
    
	void shuffle(vector<int>&nums)
	{
		
		for(int i = 0; i < nums.size(); i++)
		{
			swap(nums[i],nums[rand()%(i+1)]);
		}
	}
};

int main()
{
	int ints[109] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int>arr;
	Solution so;
	for(int i = 0; i < 109; i++)
		arr.push_back(ints[i]);
	vector<vector<int>>ans = so.threeSum(arr);
	for(int i = 0; i<ans.size();i++)
		cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<endl;
}
