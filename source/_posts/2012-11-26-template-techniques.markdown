---
layout: post
title: "Template techniques"
date: 2012-11-26 07:19
comments: true
categories: [c++]
---
C++模板的类型：
{% codeblock lang:cpp %}
// Type 1
tempalte <class T>
inline const T& max (cont T& a, cont T& b)
{
	return (a > b) ? a : b;
}

// Type 2
template <int theValue>
void add(int& elem)
{
	elem += theValue;
}

void f1()
{
	vector<int> col1;
	for_each(col1.begin(), col1.end(), add<10>);
}
{% endcodeblock %}
