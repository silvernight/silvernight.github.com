---
layout: post
title: "vim自动化命令"
date: 2012-11-26 19:30
comments: true
categories: [vim]
---
参考链接:<http://www.ibm.com/developerworks/cn/linux/l-vim-script-5/>
刚刚联想到snipmate的代码补全时循环变量的自动复写更新的功能很有趣。
于是自己想简单模拟写了一条自动命令，写得很粗糙：
{% codeblock lang:vim %}
augroup repeatline
autocmd CursorMovedI *.txt :call setline(line('.')+1, getline('.'))
augroup END
{% endcodeblock %}
