/*********************************************************************
	@ Title:		1_6.实现串的基本操作	

	@ Description:		1、测试使用串的基本操作
						
				2、实现串的基本操作

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/09/11
**********************************************************************/

#include<iostream>
#include"SqString.h"
using namespace std;



//-------------2、实现每输出10个元素，就换行，再输出-----------------//



int main()
{

	SqString s, t;
	t.strAssign("hello");	
	s.strCopy( &(t.getSqStr()) );
	
	return 0;
}