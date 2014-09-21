数据结构与算法分析
============

##Content:

>###1_1_线性表（顺序表、链表） 

>>####* [Main.cpp](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_1_%E7%BA%BF%E6%80%A7%E8%A1%A8%EF%BC%88%E9%A1%BA%E5%BA%8F%E8%A1%A8%E3%80%81%E9%93%BE%E8%A1%A8%EF%BC%89/Main.cpp)

>>>1、使用顺序表的基本操作

>>>2、指针初始化或者不初始化均不等于NULL

>>>3、使用链表的基本操作

>>>4、使用双向循环链表的基本操作LinkList.h

>>####* [Sqlist.h](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_1_%E7%BA%BF%E6%80%A7%E8%A1%A8%EF%BC%88%E9%A1%BA%E5%BA%8F%E8%A1%A8%E3%80%81%E9%93%BE%E8%A1%A8%EF%BC%89/Sqlist.h)

>>>声明顺序表的基本操作

>>####* [Sqlist.cpp](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_1_%E7%BA%BF%E6%80%A7%E8%A1%A8%EF%BC%88%E9%A1%BA%E5%BA%8F%E8%A1%A8%E3%80%81%E9%93%BE%E8%A1%A8%EF%BC%89/Sqlist.cpp)

>>>实现顺序表的基本操作

>>####* [LinkList.h](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_1_%E7%BA%BF%E6%80%A7%E8%A1%A8%EF%BC%88%E9%A1%BA%E5%BA%8F%E8%A1%A8%E3%80%81%E9%93%BE%E8%A1%A8%EF%BC%89/LinkList.h)

>>>声明链表的基本操作

>>####* [LinkList.cpp](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_1_%E7%BA%BF%E6%80%A7%E8%A1%A8%EF%BC%88%E9%A1%BA%E5%BA%8F%E8%A1%A8%E3%80%81%E9%93%BE%E8%A1%A8%EF%BC%89/LinkList.cpp)

>>>实现链表的基本操作

>>####* [DLinkList.h](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_1_%E7%BA%BF%E6%80%A7%E8%A1%A8%EF%BC%88%E9%A1%BA%E5%BA%8F%E8%A1%A8%E3%80%81%E9%93%BE%E8%A1%A8%EF%BC%89/DLinkList.h)

>>>声明双向循环链表的基本操作

>>####* [DLinkList.cpp](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_1_%E7%BA%BF%E6%80%A7%E8%A1%A8%EF%BC%88%E9%A1%BA%E5%BA%8F%E8%A1%A8%E3%80%81%E9%93%BE%E8%A1%A8%EF%BC%89/DLinkList.cpp)

>>>实现双向循环链表的基本操作


>###1_2_栈_队(面向对象C++实现) 

>>####* [Main.cpp](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_2_%E6%A0%88_%E9%98%9F(%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E5%AE%9E%E7%8E%B0)/Main.cpp)

>>>1、实现顺序栈、链栈

>>>2、实现顺序队、链队、循环队列

>>>3、测试顺序栈的基本操作

>>>4、测试链栈的基本操作

>>>5、实现顺序循环队列操作

>>>6、测试链式循环队列操作

>>PS:因为使用了模板编程的方式，vs2010环境下，无法实现类模板分离编译，因此，实现代码也放在头文件中，找时间测试下gcc下可否实现类模板分离编译~~


>>####* [SqStack.h](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_2_%E6%A0%88_%E9%98%9F(%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E5%AE%9E%E7%8E%B0)/SqStack.h)

>>>+ 栈的构造函数，初始化栈

>>>+ 析构函数，销毁栈

>>>+ 获取栈的长度

>>>+ 判断栈是否为空

>>>+ 入栈

>>>+ 出栈

>>>+ 获取栈顶元素

>>>+ 便利输出栈中元素


>>####* [LinkStack.h](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_2_%E6%A0%88_%E9%98%9F(%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E5%AE%9E%E7%8E%B0)/LinkStack.h)

>>>+ 构造函数，初始化链栈

>>>+ 析构函数，销毁链栈

>>>+ 返回链栈长度

>>>+ 判断链栈是否为

>>>+ 压栈

>>>+ 弹栈

>>>+ 获取栈顶元素

>>>+ 遍历输出栈中的元素
	
>>>+ 栈的应用：中缀转后缀


>>####* [circularLinkQueue.h](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_2_%E6%A0%88_%E9%98%9F(%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E5%AE%9E%E7%8E%B0)/circularLinkQueue.h)

>>>声明链表的基本操作
>>>+ 循环队列构造函数，初始化队列

>>>+ 析构函数，销毁队列

>>>+ 判断队列是否为空

>>>+ 返回队列长度

>>>+ 入队

>>>+ 出队

>>>+ 获取队首元素

>>>+ 获取队尾元素

>>>+ 遍历输出队中的元素


>>####* [circularSqQueue.h](https://github.com/JamesonHuang/DataStructor/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E5%88%86%E6%9E%90/1_2_%E6%A0%88_%E9%98%9F(%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E5%AE%9E%E7%8E%B0)/circularSqQueue.h)

>>>+ 循环队列构造函数，初始化队列

>>>+ 析构函数，销毁队列

>>>+ 判断队列是否为空

>>>+ 返回队列长度

>>>+ 入队

>>>+ 出队

>>>+ 获取队首元素

>>>+ 获取队尾元素

>>>+ 遍历输出队的元素

