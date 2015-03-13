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
    cout << "排序前：";
    for(int i = 0; i < 10; ++i){
        v.push_back(10 - i);
        cout << v[i] << "\t";
    }
    cout << endl;
    Sort *s;
    //s = new Sort(v, "BubbleSort");
    //s = new Sort(v, "SelectSort");
    //s = new Sort(v, "InsertSort");
    //s = new Sort(v, "ShellSortSh");
    //s = new Sort(v, "ShellSortKn");
    //s = new Sort(v, "IMergeSort");
    //s = new Sort(v, "HeapSort");
    s = new Sort(v, "QuickSort");
    
    cout << "排序后：";
    for(int i = 0; i < 10; ++i){
        cout << v[i] << "\t";
    }
    cout << endl;

    return 0;
}
