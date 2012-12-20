---
layout: post
title: "ostream_iterator应用实例"
date: 2012-11-25 09:40
comments: true
categories: [stl, c++]
---
最近在恶补STL，刚刚发现了ostream_iterator的妙用。
##一条代码输出vector容器的内容
{% codeblock printout vector elements lang:cpp %}
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(int argc, const char *argv[])
{
	vector<int> vec;
	for (int i = 1; i <= 10; ++i) 
		vec.push_back(i);
	// 使用copy复制vec的所有元素到标准输出，并以空格分隔
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ""));	// 注意ostream_iterator的模板参数类型是int
	ostream_iterator<double> os_iter(cout, " ~ ");
    *os_iter = 1.0;            /* 向cout缓冲区写入数据1.0 */
	*os_iter = 2.0;            /* 向cout缓冲区写入数据2.0 */
	*os_iter = 3.0;            /* 向cout缓冲区写入数据3.0 */
	return 0;
}
{% endcodeblock %}

Result:
```
1 2 3 4 5 6 7 8 9 10 1 ~ 2 ~ 3 ~
```

##一条代码输出map容器的内容
由于map容器存储的元素是键值对，所以不能像vector容器一样直接输出元素，
需要重载<<运算符。
详情参考<http://www.cppblog.com/Young/archive/2012/11/18/195333.aspx>
这里我采用了里面介绍的比较简单的第二种方法，使用transform函数取代copy函数。
{% include_code cpp/stl/PrintOutMapContents.cpp %}


##逐个单词读取文件，并输出到控制台
{% codeblock lang:cpp %}
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(int argc, const char *argv[])
{
	ifstream ifs("FindInArray.cpp");
	if (!ifs) {
		cout << "file is not found";
	}
	istream_iterator<string> ibeg(ifs);
	istream_iterator<string> iend;
	vector<string> vec(ibeg, iend);
	copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, " "));

}
{% endcodeblock %}
 
##使用istream_iterator,ostream_iterator读取文件并输出到另一个文件
{% include_code cpp/stl/RWFileByIOstream_iterator.cpp %}
