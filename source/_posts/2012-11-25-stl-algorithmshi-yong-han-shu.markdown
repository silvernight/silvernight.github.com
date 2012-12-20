---
layout: post
title: "STL Algorithm实用函数"
date: 2012-11-25 18:52
comments: true
categories: [stl, c++]
---
###随机洗牌函数random_shuffle
如果要保证每次程序运行时的洗牌结果不一样，需要在调用该函数前，调用srand(time(NULL))
{% codeblock lang:cpp %}
nt main(int argc, const char *argv[])
{
	vector<int> ivec;
	for (int i=1; i<=10; ++i) 
		ivec.push_back(i);
	srand(time(NULL));
	random_shuffle(ivec.begin(), ivec.end());
	copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));
	return 0;

}
{% endcodeblock %}
