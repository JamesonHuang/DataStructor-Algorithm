/*************************************************************************
    > File Name:        StrOpt.h
    > Description:      
    > Conclusion:          
    > Author:           rh_Jameson
    > Created Time:     2015年03月15日 星期日 10时48分41秒
 ************************************************************************/

#ifndef _STROPT_H
#define _STROPT_H

#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<cassert>
//#include<cmem>
using namespace std;

class StrOpt {
public:
    /* 字符串转整型 */
    int atoi(const string s){
        int len = s.size(), iter = 0;   //串长 & 游标
        int num = 0, sign = 1;      //整型数字 & 符号位
        //判空
        if(s.empty() || s[iter] == '\0')    return 0;
        //跳过空格
        while(s[iter] == ' ' && iter < len) ++iter;
        //判断正负
        if(s[iter]== '+')   ++iter;
        if(s[iter] == '-'){
            sign = -1;
            ++iter;
        }
        for( ; iter < len; ++iter){
            //跳过中间可能出现的空格
            if(s[iter] == ' ')  ++iter;
            //屏蔽0-9以外的字符
            if(s[iter] < '0' || s[iter] > '9')  break;
            //溢出处理
            if(num > INT_MAX / 10 || 
               (num == INT_MAX / 10 && (s[iter] - '0') > INT_MAX % 10)
              ){
                  return sign == -1 ? INT_MIN : INT_MAX;
              }
            num = num * 10 + (s[iter] - '0');
        }
        return num * sign;
    }

    /* 整型转字符串 */
    void itoa(int num, string &str){
        int sign = num, iter = 0;   //符号标志 & 游标
        //如传入整数是负数，则先做abs()
        if(sign < 0){
            num = -num;
        }
        //逐位转换
        do{
            str[iter++] = num % 10 + '0';
            num /= 10;
        }while(num > 0);
        //如传入整数是负数，加上'-'        
        if(sign < 0){
            str[iter++] = '-';
        }
        str[iter] = '\0';       //添加结束符
        reverse(str, 0, iter - 1);
    }
    //逆置字符串
    void reverse(string &str, int first, int last){
        while(first < last){
            swap(str[first++], str[last--]);
        }
    }
    //交换字符
    void swap(char &a, char &b){
        char tmp = a;
        a = b;
        b = tmp;
    }

    /* 字符串拷贝 */
    void StrCpy(string &src, string &dest){
        //保证src,dest不为空
        assert(!src.empty() && !dest.empty());
        int iter = 0, dest_len = dest.size();
        //只要目标串或源串有一个到了尾部，循环结束
        while(iter < dest_len && (dest[iter] = src[iter]) != '\0'){
            ++iter;
        }
    }
    
    /* 字符串拷贝 */
    void StrNCpy(string &src, string &dest,int n){
        //保证src,dest不为空
        assert(!src.empty() && !dest.empty());
        //指定长度不能大于源串长度
        assert(n <= src.size());
        int iter = 0, dest_len = dest.size();
        //指定长度如大于目标串长度的处理
        if(n > dest_len)
            n = dest_len;
        //只要到达指定长度或源串到了尾部，循环结束
        while(iter < n && (dest[iter] = src[iter]) != '\0'){
            ++iter;
        }
        //结束符处理
        if(dest[iter] != '\0')
            dest[iter] = '\0';
    }

    /* 内存拷贝 */
    void* MemCpy(void *dest, void *src, int len){
        //转char*,使每次移动都是一个字节
        char *tmp_dest = (char *)dest;
        char *tmp_src = (char *)src;
        int iter = 0;
        //内存地址不重叠或目标串高位地址重叠源串低位地址时
        if(tmp_dest < tmp_src || tmp_dest > (tmp_src + len - 1)){
            while(iter++ < len)
                *tmp_dest++ = *tmp_src++;
        }
        else{   //源串低位地址重叠目标串高位地址时
            tmp_dest += len;
            tmp_src += len;
            iter = len;
            while(iter > 0){
                *tmp_dest-- = *tmp_src--;
            }
        }
    }
    /* 内存初始化 */
    void *memset(void *buffer,int c, size_t size){
        assert(buffer!=NULL);  
        //转char*,逐字节初始化
        char* ptr = (char *)buffer;
        while(size-- > 0){
            *ptr++ = (char)c;
        }
        return buffer;
    }

    /* strcmp */
	int StrCmp(string str1, string str2){
	    //保证str1和str2不为空
	    assert(!str1.empty() && !str2.empty());
	    int res = 0, iter = 0;
		int len = str1.size() > str2.size() ? str2.size() : str1.size();
	    //判断iter位置，str1和str2是否相同
	    while(iter < len && !(res = str1[iter] - str2[iter]) ){
			++iter;
	    }
	    if(res > 0)	    	return 1;
	    else if(res < 0)   	return -1;
	    //如果有一个字符串结束，作相应处理
		if(iter == len && res == 0){
			return str1.size() > str2.size() ? 1 : -1;
		}
	    return 0;
	}
	//strcat
	void StrCat(string &src, string &dest){
	    //保证str1和str2不为空
	    assert(!src.empty() && !dest.empty());
	    //重置大小
	    dest.resize(dest.size() + src.size() );
		int iter_dest = 0, iter_src = 0, len = dest.size();
	    //定位到目标串结尾处
	    while(dest[iter_dest] != '\0')	++iter_dest;
	    //将原串连接到目标串尾部
	    while(iter_dest < len && (dest[iter_dest++] = src[iter_src++]) != '\0');
	}

private:

};

#endif
