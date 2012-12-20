---
layout: post
title: "copy and swap technique"
date: 2012-11-26 09:26
comments: true
categories: [c++]
---
Copy and Swap 技术可以在一定程度上来解决对某个对象进行修改时抛出异常的问题。
例如，当对某个容器进行插入操作时可以这样实现：
{% codeblock lang:cpp %}
template <class T, class Cont, class Iter>
void insert (Cont& coll, const Iter& pos, const T& value)
{
    Cont tmp(coll);              /* copy container and all elements */
    tmp.insert(pos, value);      /* modify the copy */
    coll.swap(tmp);              /* use copy (in case no exception was thrown) */
}
{% endcodeblock %}
