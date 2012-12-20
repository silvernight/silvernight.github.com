---
layout: post
title: "The C++ STANDARD LIBRARY CHAPTER 3"
date: 2012-11-20 09:20
comments: true
categories: [reading, notes, c++]
---
#C++标准库-读书笔记-第三章--一般概念
###3.2头文件
#include <stdlib.h>和#include <cstdlib>的区别在于后者的标识符只定义在namespace std中，而前者的标识符默认是全局作用域。
###3.3错误处理和异常处理
标准异常类别可分为三组：
	1. 语言本身支持的异常
	2. C++标准库发出的异常
	3. 程序作用域之外发出的异常

C++的异常继承体系：
![C++_Standard_Exceptions_Hierarchy][source/images/myimages/C++_Standard_Exceptions_Hierarchy.png]

####语言本身支持的异常
此类异常用意支撑某些语言特性，所以他们是核心语言的一部分。如果以下操作失败，就会抛出出这一类异常。

* new失败，抛出bad_alloc异常（除非若用new的nothorw版本）。由于这个异常可能于任何时间在任何较复杂的程序中发生，所以是最重要的一个异常。
* 运行阶段，当dynamic_cast失败会抛出bad_cast异常
* RTTI中，如果typid的参数为零或空，typeid抛出bad_typeid异常。
* 发生非预期异常，bad_exception异常会接手处理。
{% codeblock lang:cpp %}
class E1;
class E2;  // not derived from E1
void f() thorw(E1)	// throws only exceptions of type E1
{
	throw E1();		// throws exception of type E1
	throw E2();		// calls unexpected(), which calls terminate()
}
{% endcodeblock %}
然而若果你在你的异常规格总列出bad_exception，那么unexpected()总是会重新抛出(rethrows)bad_exception异常
{% codeblock lang:cpp %}
class E1;
class E2;  // not derived from E1

void f() thorw(E1, std::bad_exception)	
	// throws only exceptions of type E1 or
	// bad_exception for any other exception type
{
	throw E1();		// throws exception of type E1
	throw E2();		// calls unexpected(), which throws bad_exception
}
{% endcodeblock %}

####异常类型的头文件
基础类别exception和bad_exception定义于<exception>。bad_alloc定义于<new>。bad_cast和bad_typeid定义于<typeinfo>。ios_base::failure定义于<ios>。
其他异常类型定义于<stdexcept>
####异常类型的成员
{% codeblock lang:cpp %}
namespace std {
	class exception {
		public:
			virtual const char* what() const throw();
	};
}

try {
	
} catch (const std::exception& error) {
	// print implementation-defined error message
	std::cerr << error.what() << std::endl;
}
{% endcodeblock %}

####抛出标准异常
可以在自己的程序库或程序内部抛出某些标准异常，传递string参数作为what()的描述字符串。例如logic_error定义：
{% codeblock lang:cpp %}
namespace std {
	class logic_error : public exception {
		public:
			explicit logic_error (const string& whatstring);
	};
}
{% endcodeblock %}
提供这种功能的标准异常有：**logic_error**、**runtime_error**、ios_base::failure以及他们的衍生类型。

####3.3.4从标准异常华类型中派生新类型

###3.4配置器(Allocators)
C++标准程序库使用allocator来处理存储器配置和定址。
