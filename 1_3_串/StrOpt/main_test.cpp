/*************************************************************************
	> File Name:        main_test.cpp
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2015年03月15日 星期日 10时47分44秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include "StrOpt.h"

using namespace std;

int main()
{
	/* strcmp & strcat test cases */
	string s1 = "aa";
	string s2 = "1234";
	char *s3 = "aa", *s4 = "1234";
	cout << StrCmp(s2, s1) << endl;
	cout << strcmp(s4, s3) << endl;
	StrCat(s1, s2);
	cout << s2 << endl;
	
    /* memset test cases: 
    char ch[10];
    StrOpt str_opt;
    str_opt.memset(ch, '1',10 * sizeof(char));
    cout << ch << endl;
    */
    /*
    int a[10];
    StrOpt str_opt;
    str_opt.memset(a, 0, 10 * sizeof(int));
    for(int i = 0; i < 10; ++i){
        cout << a[i] << "\t";
    }
    */
    /* strcpy & strncpy memcpy test case: 
    
    //string src = "testt dl";
    //string dest = "hello world";
    //string src,dest;
    char dest[] = "testt dl";
    char src[] = "hello world";
    StrOpt str_opt; 
    //str_opt.StrCpy(src, dest);
    //str_opt.StrNCpy(src, dest, 4);
    str_opt.MemCpy(dest, src, 7);
    cout << dest << endl;
    */
    
    /*itoa test cases: 
    int res;
    string str = "initial string";
    StrOpt str_opt;
    res = 45654;
    str_opt.itoa(res, str);
    cout << str << endl;
    */

    /* atoi test case: 
    res = str_opt.atoi(str);
    cout << res << endl;
    
    str = "-123";
    res = str_opt.atoi(str);
    cout << res << endl;
    
    str = "    -3 21adf";
    res = str_opt.atoi(str);
    cout << res << endl;

    str = "9999999999999999999999";
    res = str_opt.atoi(str);
    cout << res << endl;
    */
    
    

    return 0;
}
