// exci3.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
#include<stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int num = timeSeries.size();
		int dura_time_end = 0;
		int dura_time_all = 0;
		if (num == 0)
		{
			return 0;
		}
		if (num ==1)
		{
			dura_time_all = duration;
			return dura_time_all;
		}
		dura_time_end = timeSeries[0] + duration;

		for (int index = 1; index < num; index++)
		{
			if (dura_time_end <= timeSeries[index])
			{
				dura_time_all += duration;
			}
			else
			{
				dura_time_all += timeSeries[index] - timeSeries[index - 1];
			}
			dura_time_end = timeSeries[index] + duration;
		}
		dura_time_all += duration;
		return dura_time_all;
	}
};

void main()
{
	vector<int> vec = { 1,4 };
	Solution s;
	int a = s.findPoisonedDuration(vec, 2);
	cout << a << endl;
	cout << "hello word" << endl;
	system("pause");
    
}

