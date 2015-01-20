#include<iostream>
#include<cstdlib>
#include"BTree.h"
using namespace std;
int main(){
	const int n=15;
	int i,a[n]={10,5,15,8,3,18,13,12,14,16,20,1,4,6,9};
	BinaryTree<int> btree;
	btree.Creat(a,n);
	cout<<"输入数据："<<endl;
	for(i=0;i<n;i++) cout<<a[i]<<'\t';
	cout<<endl<<"中序："<<endl;
	btree.InOrder();    //中序遍历输出升序
	cout<<endl<<"前序："<<endl;
	btree.PreOrder();
	cout<<endl<<"后序："<<endl;
	btree.PostOrder();
	cout<<endl;
	return 0;
}