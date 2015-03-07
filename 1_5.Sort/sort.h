/*************************************************************************
	> File Name:        sort.h
	> Description:      
                        （1）实现常用的各种排序
                        （2）利用回调函数实现
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

//字符串数组，通过该数组适配switch
static string sort_type[] = {"BubbleSort", "SelectSort", "InsertSort",
                            "ShellSortSh", "ShellSortKn", "IMergeSort", 
                             "HeapSort","QuickSort"
                            };
class Sort {
public:
    //Sort构造函数
    Sort(vector<int> &v, string sort_name){
        int len = 8, i;
        //判断要采取何种排序
        for(i = 0; i < len; ++i){
            if(sort_name == sort_type[i]){
                break;
            }
        }
        switch(i){
            case 0:     CallSort = BubbleSort;  break;
            case 1:     CallSort = SelectSort;  break;
            case 2:     CallSort = InsertSort;  break;
            case 3:     CallSort = ShellSortSh; break;
            case 4:     CallSort = ShellSortKn; break;
            case 5:     CallSort = IMergeSort;  break;
            case 6:     CallSort = HeapSort;    break;
            case 7:     CallSort = QuickSort;   break;
            default:    cout << "无此排序！" << endl;   return;
        }
        CallSort(v);
    }
    //两数交换函数
    static void swap(int &num1, int &num2){
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    //冒泡排序
    static void BubbleSort(vector<int> &v){
        int len = v.size(), flag;       //数组长度 & 交换标记变量
        for(int i = 0; i < len; ++i){
            flag = 0;                   //初始化标记为0
            for(int j = 1; j < len - i; ++j){
                if(v[j] < v[j - 1]){
                    swap(v[j],v[j - 1]);
                    flag = 1;           //发生交换，标记变量置1    
                }
            }
            if(flag == 0)   //一轮比较后，如未发生交换，说明已排好序
                break;
        }
    }
    //选择排序
    static void SelectSort(vector<int> &v){
        int len = v.size(), min_idx;    //数组长度 & 无序区最小元素位置
        for(int i = 0; i < len; ++i){   //i：无序区中开头位置
            min_idx = i;
            //寻找无序区中最小元素的位置
            for(int j = i + 1; j < len; ++j){   
                if(v[min_idx] > v[j])
                    min_idx = j;
            }
            //最小元素位置如不等于i，则交换位置
            if(min_idx != i){
                swap(v[min_idx], v[i]);
            }
        }
    }
    //插入排序
    static void InsertSort(vector<int> &v){
        int len = v.size(), tmp, i, j;
        for(i = 1; i < len; ++i){
            tmp = v[i];
            for(j = i; j > 0 && tmp < v[j - 1]; --j)
                v[j] = v[j - 1];
            v[j] = tmp;
        }
        
    }    
    //希尔排序(希尔增量)
    static void ShellSortSh(vector<int> &v){
        int len = v.size();
        int gap, i, j, tmp;
        /* 形式一
        for(gap = len / 2; gap > 0; gap /= 2){
            for(i = gap; i < len; ++i){
                tmp = v[i];
                for(j = i; j >= gap && tmp < v[j - gap]; j -= gap)
                    v[j] = v[j - gap];
                v[j] = tmp;
            }
        }
        */
        /* 形式二 */
        for(gap = 1; gap <= (len - 1) / 4; gap = 2 * gap);
        for(; gap > 0; gap /= 2){
            for(i = gap; i < len; ++i){
                tmp = v[i];
                for(j = i; j >= gap && tmp < v[j - gap]; j -= gap)
                    v[j] = v[j - gap];
                v[j] = tmp;
            }
        }
    }
    //希尔排序(Knuth增量)
    static void ShellSortKn(vector<int> &v){
        int len = v.size();
        int gap, i, j, tmp;
        for(gap = 1; gap <= (len - 1) / 3; gap = 3 * gap + 1);
        for(; gap > 0; gap /= 3){
            for(i = gap; i < len; ++i){
                tmp = v[i];
                for(j = i; j >= gap && tmp < v[j - gap]; j -= gap)
                    v[j] = v[j - gap];
                v[j] = tmp;
            }
        }
    }
    //归并排序外部接口
    static void IMergeSort(vector<int> &v){
        int len = v.size();
        MergeSortUpToDown(v, 0, len - 1);
        
    }
    //自顶向下归并排序实现
    static void MergeSortUpToDown(vector<int> &v, int start, int end){
        if(v.empty() || start >= end)
            return;
        int mid = (start + end) / 2;
        MergeSortUpToDown(v, start, mid);
        MergeSortUpToDown(v, mid + 1, end);
        Merge(v, start, mid, end);
    }
    //归并实现关键代码
    static void Merge(vector<int> &v, int start, int mid, int end){
        vector<int> tmp;
        int leftPos = start;
        int leftEnd = mid;
        int rightPos = mid + 1;
        int rightEnd = end;
        int tmpPos = leftPos;
        int numElement = rightEnd - leftPos + 1;

        while(leftPos <= leftEnd && rightPos <= rightEnd){
            if(v[leftPos] <= v[rightPos])
                tmp[tmpPos++] = v[leftPos++];
            else
                tmp[tmpPos++] = v[rightPos++];
        }
        while(leftPos <= leftEnd)
            tmp[tmpPos++] = v[leftPos++];
        while(rightPos <= rightEnd)
            tmp[tmpPos++] = v[rightPos++];

        for(int i = 0; i < numElement; ++i, --rightEnd){
            v[rightEnd] = tmp[rightEnd];
        }
    }
    //堆排序
    static void HeapSort(vector<int> &v){
        cout << "callback test" << endl;
    }
    //快速排序
    static void QuickSort(vector<int> &v){
        cout << "callback test" << endl;
    }
private:
    void (*CallSort)(vector<int> &v);
};

#endif
