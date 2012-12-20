---
layout: post
title: "The C++ STANDARD LIBRARY CHAPTER 2"
date: 2012-11-20 08:13
comments: true
categories: [reading, notes]
---
#C++标准库-读书笔记-第二章

####2.1
1、标准程序库并非基于某本书或某一个现成的函数库，而是将各种不同的类（classes）整合而成。你会发现不同组件背后有不同的设计原则，string class 和 STL之间的差别就是很好的例子，
后者是一个数据结构和算法框架。

* string classes 被设计为安全易用的组件，其界面几乎不言自明，并能对许多可能的错误作检验。
* STL的设计目标，是将不同的算法和数据结构结合在一起，并获取最佳效率，所以STL并不非常便利，也不检验许多可能的逻辑错误。要运用STL强大的框架和优异的效率，你就必须通晓其概念并小心运用。

####2.2.1 template
{% codeblock lang:cpp %}
template <class T>
inline const T& max (const T& a, const T& b)
{
	return a < b ? b : a;
}
{% endcodeblock %}

######Nontype Templates（非类型模板参数）
{% codeblock lang:cpp %}
bitset<32> flags32;
bitset<50> flags50;
{% endcodeblock %}
这些bitsets由于使用不同的template参数，所以有不同的类型。

######Default Template Parameters
{% codeblock lang:cpp %}
template <class T, class container = vector<T> >
class MyClass;
MyClass<int> x1;		// equivalent to: MyClass<int, vector<int> >
{% endcodeblock %}

#####typename - 被用来作为类型之前的标识符。

#####成员模板
类成员模板可以是个template，但它既不能是virtual，也不能有预设参数。
{% codeblock lang:cpp %}
template <class T>
class MyClass
{
	private:
		T value;

	public:
		template <class X>
			void assign(const MyClass<X>& x)    /* allows different template types */
			{
				value = X.getValue();           /* different types can't access private or protected members */
			}
		T getValue () const
		{
			return value;
		}
		...
};

void f()
{
	MyClass<double> d;
	MyClass<int> i;

	d.assign(d);
	d.assign(i);	// OK, (int is assignable to double)
}
{% endcodeblock %}

**template copy constructor**
copy constructor with implicit type conversion does not hide implicit copy constructor
{% codeblock lang:cpp %}
template <class T>
class MyClass
{
	public:
		// copy constructor with implicit type conversion
		// does not hide implicit copy constructor
		template <class U>
			MyClass (const MyClass<U>& x);
};

void f()
{
	MyClass<double> xd;
	MyClass<double> xd2(xd);	// calls built-in copy constructor
	MyCLass<int>	xi(xd);		// calls template copy constructor
}
{% endcodeblock %}

**Nested Template Classes**
{% codeblock lang:cpp %}
template <class T>
class MyClass
{
	template <class T2>
		class NestedClass
		{
			
		};
};
{% endcodeblock %}


####namespace
如果某个函数的一个或多个引用类型，都定义在函数所在的namespace中，那么你不必为该函数指定namespace。这个规则称为Koening lookup。
例如：
{% codeblock lang:cpp %}
// define identifiers in namespace josuttis
namespace josuttis
{
	class File;
	void myGlobalFunc(const File&);
}

josuttis::File obj;
myGlobalFunc(obj);	// OK, lookup finds josuttis::myGlobalFunc()
{% endcodeblock %}

**using declaration**
{% codeblock lang:cpp %}
using josuttis::File;
using namespace josuttis;
{% endcodeblock %}

#####2.2.6关键字explicit
explicit可以禁止“但参数构造函数”被用于自动类型转换。
例如可以声明一个构造函数，以stack的初始大小为参数：
{% codeblock lang:cpp %}
class stack
{
	explicit Stack(int size);	// create stack with initial size
};
{% endcodeblock %}
**explicit阻止了一个int自动转型为Stack**
{% codeblock lang:cpp %}
Stack s;
s = 40;		// not permitted
{% endcodeblock %}
explicit 同样阻止了以下情况
{% codeblock lang:cpp %}
Stack s1(40);
Stack s2 = 40;	// ERROR
{% endcodeblock %}

#####2.2.8 常量静态成员的初始化
{% codeblock lang:cpp %}
class MyClass
{
	static const int num = 100;
	int elems[num];
};

const int MyClass::num;		// no initialization here?? 
{% endcodeblock %}
