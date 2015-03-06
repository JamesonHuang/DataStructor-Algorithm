/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2015年03月06日 星期五 13时23分05秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
//#include<algorithm>
#include "sort.h"

using namespace std;

int main()
{
    //Error test cases from leetcode.com
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(10 - i);
        cout << v[i] << "\t";
    }
    cout << endl;
    Sort *s = new Sort(v, "BubbleSort");

    return 0;
}
