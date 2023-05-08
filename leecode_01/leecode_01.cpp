#include <iostream>
#include <vector>
#include <map>
using namespace std;

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。



// 暴力方法
class Solution1 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // 定义两个U表 i,j
        int i = 0, j = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return { i,j };
                }
            }

        }
        return{ i,j };
    }
};

class Solution2
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> a;//提供一对一的hash
        vector<int> b(2, -1);//用来承载结果，初始化一个大小为2，值为-1的容器b
        for (int i = 0; i < nums.size(); i++)
        {
            if (a.count(target - nums[i]) > 0)
            {
                b[0] = a[target - nums[i]];
                b[1] = i;
                break;
            }
            a[nums[i]] = i;//反过来放入map中，用来获取结果下标
        }
        return b;

    }
};
int main()
{
    Solution1 s1;
    vector<int> nums;
    int target = 9;

    vector<int> result;

    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    result = s1.twoSum(nums, target);

    cout << "[" << result[0] << "," << result[1] << "]" << endl;

    Solution2 s2;

    auto i = s2.twoSum(nums, target);

    cout << "[" << i[0] << "," << i[1] << "]" << endl;

}