/*************************************************************************
	> File Name:        sort.h
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2015年03月06日 星期五 20时33分45秒
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Sort {
public:
    //Sort构造函数
    Sort(vector<int> &v, string sort_name){
        int len = 7, i;
        
        for(i = 0; i < len; ++i){
            if(sort_name == sort_type[i]){
                break;
            }
        }
        switch(i){
            case 0:     CallSort = BubbleSort;  break;
            //case 1:     CallSort = SelectSort;  break;
            default:    cout << "无此排序！" << endl;
        }
        CallSort(v);
    }

    static void BubbleSort(vector<int> &v){
        cout << "callback test" << endl;
    }

private:
    static string sort_type[];
    
    void (*CallSort)(vector<int> &v);
};
string sort_type[] = {"BubbleSort", "SelectSort", "InsertSort",
                     "ShellSort", "MergeSort", "HeapSort","QuickSort"
                    };

#endif
