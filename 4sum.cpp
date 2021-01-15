#include"vector"
#include"iostream"
#include"unordered_map"
#include"algorithm"
#include"utility"
using namespace std;
vector<vector<int>> result;

vector<vector<int>> four_sum(vector<int>& nums, int& target)
{
	if (nums.size()< 4)
	{
		return result;
	}
	else
	{
		sort(nums.begin(), nums.end());
		unordered_multimap<int, pair<int, int>> cache;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				//返回两数之和跟这两个数的一个对应关系
				cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
				//插入以后是不是按照第一个值的大小排列的
			}
		}

		for (auto i = cache.begin(); i != cache.end(); i++)
		{
			int x = target - i->first; //目标减去每一种两数之和提出来
			auto range = cache.equal_range(x);//在两数之和中找出这个x作为目标
										//返回的是一个pair里面存放了两个迭代器
			for (auto j = range.first; j != range.second; j++)
			{
				auto a = i->second.first;
				auto b = i->second.second;
				auto c = j->second.first;
				auto d = j->second.second;
				if (a != c && a != d && b != c && b != d)
				{
					vector<int> vec = { nums[a],nums[b],nums[c],nums[d] };
					sort(vec.begin(), vec.end());
					result.push_back(vec);
				}
			}

		}
		sort(result.begin(), result.end());
		result.erase(unique(result.begin(), result.end()), result.end());
		return result;
	}
}






int main()
{
	vector<int> test_set = { 1,0,-1,0,-2,2 };
	int target = 0;
	vector<vector<int>> a = four_sum(test_set, target);
	for (int i =0;i<a.size();i++)
	{
		for (int j = 0; j < a[i].size();j++) cout << a[i][j] << " ";
		cout << endl;
	}
}
