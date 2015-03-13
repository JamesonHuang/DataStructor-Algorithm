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
        if(v.empty()){
            cout << "数组为空" << endl;
            return;
        }
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
                if(v[j - 1] > v[j]){
                    swap(v[j - 1],v[j]);
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
        /* 形式一 */
        for(gap = len / 2; gap > 0; gap /= 2){
            //里面两层循环是实现插排的代码
            for(i = gap; i < len; ++i){
                tmp = v[i];
                for(j = i; j >= gap && tmp < v[j - gap]; j -= gap)
                    v[j] = v[j - gap];
                v[j] = tmp;
            }
        }
        
        /* 形式二: 
        //初始化最大步长
        for(gap = 1; gap <= (len - 1) / 4; gap = 2 * gap);      //普林斯顿大学给出的写法
        for(; gap > 0; gap /= 2){
            for(i = gap; i < len; ++i){
                tmp = v[i];
                for(j = i; j >= gap && tmp < v[j - gap]; j -= gap)
                    v[j] = v[j - gap];
                v[j] = tmp;
            }
        }
        */      
    }
    //希尔排序(Knuth增量)
    static void ShellSortKn(vector<int> &v){
        int len = v.size();
        int gap, i, j, tmp;
        //初始化最大步长
        //for(gap = 1; gap <= (len - 1) / 9; gap = 3 * gap + 1);    //普林斯顿大学给出的写法
        for(gap = 1; gap < len / 3; gap = 3 * gap + 1);
        
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
        //MergeSortDownToUp(v, len);
        
    }
    //自顶向下归并排序实现
    static void MergeSortUpToDown(vector<int> &v, int start, int end){
        if(start < end){
            int mid = (start + end) / 2;
            //递归分解
            MergeSortUpToDown(v, start, mid);
            MergeSortUpToDown(v, mid + 1, end);
            //合并
            Merge(v, start, mid, end);
        }
    }
    //归并实现关键代码
    static void Merge(vector<int> &v, int start, int mid, int end){
        //初始化临时数组
        vector<int> tmp( v.size() );
        //初始化位置坐标
        int leftPos = start, leftEnd = mid;
        int rightPos = mid + 1, rightEnd = end;
        int tmpPos = leftPos;
        int numElement = end - start + 1;
        //归并主实现
        while(leftPos <= leftEnd && rightPos <= rightEnd){
            if(v[leftPos] <= v[rightPos])
                tmp[tmpPos++] = v[leftPos++];
            else
                tmp[tmpPos++] = v[rightPos++];
        }
        //拷贝左半段剩余的的元素
        while(leftPos <= leftEnd)
            tmp[tmpPos++] = v[leftPos++];
        //拷贝右半段剩余的元素
        while(rightPos <= rightEnd)
            tmp[tmpPos++] = v[rightPos++];
        //拷贝回原数组
        //for(int i = rightEnd; i >= start; --rightEnd){
        for(int i = 0; i < numElement; ++i, --rightEnd){
            v[rightEnd] = tmp[rightEnd];
        }
    }

    //自底向上归并排序实现
    static void MergeSortDownToUp(vector<int> &v, int len){
        /* 拆分版：遍历实现相邻两组的元素进行归并排序
        for(int gap = 1; gap < len; gap *= 2){
            mergeGroups(v, len, gap);
        }
        */
        /* 合并版 */
        int i;
        //遍历实现相邻两组的元素进行归并排序
        for(int gap = 1; gap < len; gap *= 2){
            //相邻的子数组归并排序的主实现
            for(i = 0; i + 2 * gap - 1 < len; i += (2 * gap) ){
                Merge(v, i, i + gap - 1, i + 2 * gap - 1);
            }
            //组数为奇数时，剩余一个组未配对
            if(i + gap - 1 < len){
                Merge(v, i, i + gap - 1, len - 1);
            }
        }
    }
    //分组合并排序实现（将相邻的子数组进行合并排序）
    static void mergeGroups(vector<int> &v, int len, int gap){
        int i;
        //相邻的子数组归并排序的主实现
        for(i = 0; i + 2 * gap - 1 < len; i += (2 * gap) ){
            Merge(v, i, i + gap - 1, i + 2 * gap - 1);
        }
        //组数为奇数时，剩余一个组未配对
        if(i + gap - 1 < len){
            Merge(v, i, i + gap - 1, len - 1);
        }
    }
    
    //堆排序
    static void HeapSort(vector<int> &v){
        int len = v.size();
        //建立初始堆
        for(int i = len / 2; i >= 0; --i){
            percDown(v, i, len);
        }
        //deleteMax
        for(int j = len - 1; j > 0; --j){
            swap(v[0], v[j]);
            percDown(v, 0, j);
        }
    }
    //堆排序下滤实现
    static void percDown(vector<int> &v, int iter, int len){
        int child;
        int tmp = v[iter];      //create hole
        for( ; 2 * iter + 1 < len; iter = child){
            child = 2 * iter + 1;       //获取该节点的左孩子下标
            //如有右孩子，且右孩子大于左孩子，下标改成右孩子下标
            if(child != len - 1 && v[child] < v[child + 1] )
                child++;
            //孩子结点值大于该结点值，则下滤
            if(tmp < v[child])
                v[iter] = v[child];
            else    //否则，说明结点处于正确位置，可跳出循环
                break;
        }
        v[iter] = tmp;          //把hole堵上
    }
    //快速排序
    static void QuickSort(vector<int> &v){
        QuickSortRecursion(v, 0, v.size() - 1);
    }
    static void QuickSortRecursion(vector<int> &v, int left, int right){
        /* 优化做法 */
        if(left + 5 <= right){
            int pivot = getPivot(v, left, right);
            int front = left;
            int rear = right - 1;
            //int front = left + 1;
            //int rear = right - 2;
            while(1){
                while(v[++front] < pivot){ }
                while(v[--rear] > pivot){ }
                if(front < rear)
                    swap(v[front], v[rear]);
                else
                    break;
            }
            swap(v[front], v[right - 1]);
            QuickSortRecursion(v, left, front - 1);     //sort small elements
            QuickSortRecursion(v, front + 1, right);    //sort large elements
        }
        else{
            InsertSortForQSort(v, left, right);
        }
        
        /* 纯快排做法 
        if(right - left <= 1){                      //递归出口，小于两个元素情况的处理
            if(v[left] > v[right])
                swap(v[left],v[right]);
            return;
        }
        int pivot = getPivot(v, left, right);       //枢纽元
        int front = left;
        int rear = right - 1;
        while(1){
            //首尾指针向中间靠拢
            while(v[++front] < pivot){ }            
            while(v[--rear] > pivot){ }
            //front小于rear则交换元素
            if(front < rear)
                swap(v[front], v[rear]);
            else
                break;      //front、rear交错，则不再交换，跳出循环
        }
        swap(v[front], v[right - 1]);   //将枢纽元放到正确位置
        QuickSortRecursion(v, left, front - 1);     //sort small elements
        QuickSortRecursion(v, front + 1, right);    //sort large elements
        */
    }   
    //三数中值取枢纽元
    static int getPivot(vector<int> &v, int left, int right){
        int mid = (left + right) / 2;
        if(v[left] > v[mid])
            swap(v[left], v[mid]);
        if(v[left] > v[right])
            swap(v[left],v[right]);
        if(v[mid] > v[right])
            swap(v[mid], v[right]);
        swap(v[mid], v[right - 1]);
        return v[right - 1];
    }
private:
    void (*CallSort)(vector<int> &v);
    
    //适配快排的插入排序
    static void InsertSortForQSort(vector<int> &v,int left, int right){
        int tmp, i, j;
        for(i = left + 1; i <= right; ++i){
            tmp = v[i];
            for(j = i; j >= left && tmp < v[j - 1]; --j)
                v[j] = v[j - 1];
            v[j] = tmp;
        }
        
    }    
};

#endif
