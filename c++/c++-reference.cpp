/*
	
	左值可以是右值引用类型。
	对表达式取地址，如果能，则为左值，否则为右值。

	有三种引用类型，左值引用、右值引用和通用引用。左值引用只能绑定左值，右值引用只能绑定右值，通用引用由初始化时绑定的值的类型确定。
	左值和右值是独立于他们的类型的，右值引用可能是左值可能是右值，如果这个右值引用已经被命名了，他就是左值。
	引用折叠规则：所有的右值引用叠加到右值引用上仍然是一个右值引用，其他引用折叠都为左值引用。当T&&为模板参数时，输入左值，它将变成左值引用，输入右值则变成具名的右值应用
	移动语义可以减少无谓的内存拷贝，要想实现移动语义，需要实现移动构造函数和移动赋值函数。
	std::forward()和universal references通用引用共同实现完美转发。	
	
	

	左值引用只能绑定左值，右值引用只能绑定右值
	常量左值引用可以算是一个“万能”的引用类型，它可以绑定非常量左值、常量左值、右值，而且在绑定右值的时候，常量左值引用还可以像右值引用一样将右值的生命期延长，缺点是，只能读不能改。


*/
void remove_reference(){
		int a[] = { 1,2,3 };
		decltype(*a) b1 = a[0];
		std::remove_reference<decltype(*a)>::type b2 = a[0];
		a[0] = 4;
		std::cout << b1 << std::endl; //输出4
		std::cout << b2 << std::endl; //输出1
}

