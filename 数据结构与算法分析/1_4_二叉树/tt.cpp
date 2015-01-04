BinTreeNode CreateBTree ( ){ 			/* 使用栈 , 按照先根遍历的顺序来生成一棵二叉树 */
	char ch [ 20 ]; B inTreeNode * head, * P, * t, * stack [ 50 ]; 	/* stack [ 50 ] 为堆栈 */
	int i = 0, top = 0;        			 /* top 为栈顶指针 */
	int flag = 0;           			/* 标志位 */
	cin > > ch;      				/* 对扩充二叉树按照先根遍历的顺序输入结点的信息 */
	if ( ch [ i ] = = ’#’) {
		return NULL;
	}    
	P = new B inTreeNode;
	if ( P = =NULL ) {
		return NULL;
	}
	P - > data = ch [ i ]; 
	P - > lchild =NULL; 
	P - > rchild =NULL;
	stack [ top ] = P; 
	top + + ;
	i + + ; 
	head = P;
	while ( i < strlen ( ch ) ){   
		if ( ch [ i ] = = ’#’&&flag = = 1 ) {       		/* 第一种情况 */
	  		top - - ; 
	  		t = stack [ top ];
	  		while ( stack [ top - 1 ] - > rchild = = t){ 
	  			top - - ; t = stack [ top ]; 
	  		}
		}
		else if ( ch [ i ] = = ’#’&&flag = = 0 ) 		/* 第二种情况 */
	     		flag = l:
		else{   
			P = new B inTreeNode;
			 if ( P = =NULL ) {
			 	retum NULL;
			 	P - > data = ch [ i ]; 
			 	P - > lchild =NULL; 
			 	P - > rchild =NULL;
			 }
			 if ( flag = = 0 ) {        			/* 第三种情况 */
			 	stack [ top - 1 ] - > lchild = P; 
			 	stack [ top ] = P; top + + ; 
			 }
			 else {         				/* 第四种情况 */
			 	stack [ top - 1 ] - > rchild = P;
			 	flag = 0; 
			 	stack [ top ] = P; 
			 	top + + ; 
			 }
		}
	  	i + + ;
	  }
	  return head; 
}