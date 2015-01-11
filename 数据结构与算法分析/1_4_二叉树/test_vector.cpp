/*************************************************************************
	> File Name:        test_vector.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2015年01月11日 星期日 16时22分56秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
//#include "Solution.h"

using namespace std;

void testVector(vector<int> v, int arr[10]){
    cout << "传递过来的vector大小：" << v.size() << endl;
    cout << "传递过来的arr大小：   " << sizeof(arr) / sizeof(int) << endl;
    for(int i = 0; i < 10; ++i){
        cout << v[i] << "\t";
        cout << arr[i] << "\t";
    }
    cout <<endl;
}

int main()
{
    int arr[10];
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i);
        arr[i] = i;
        cout << arr[i] << "\t";
        cout << v[i] << "\t";
    }
    cout << endl;
    testVector(v, arr);
    return 0;
}
