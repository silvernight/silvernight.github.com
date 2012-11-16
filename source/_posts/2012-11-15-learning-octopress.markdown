---
layout: post
title: "Learning octopress"
date: 2012-11-15 14:11
comments: true
categories: octopress
---

#Learning Octopress

##Sharing Code Snippets

octopress的分享代码的功能非常强大。它提供了多种分享代码的功能。
如下：


   * A Sass port of Solarized syntax highlighting created specifically for Octopress.
   * Gist code embedding - by Brandon Tilly.
   * Insert code snippets from your filesystem with a download link.
   * Easy inline code blocks with &lt;figure&gt; and &lt;figcaption&gt; and optional download links.
   * Pygments caching - a Jekyll community plugin.
   * Table based line numbers added with javascript.

<!--more-->
###Solarized highlighting

Solarized has a beautiful syntax highlighting color scheme, but reproducing it requires a highly sophisticated highlighting engine. Pygments (the highlighter Jekyll uses) processes code snippets into styleable HTML, but it isn’t nearly as powerful as the highlighting engine in Vim for example.

######注意：为了避免被octopress解析，下面代码中的{和}与%的中间都加了个空格。
###Backtick Code blocks
####syntax
	``` [language] [title] [url] [link text]
	code snippet
	```

###Gist embedding

刚刚研究了一下gist，发现gist原来是github提供的一种代码分享的功能，可以在githbu上创建gist代码，然后通过gist id来引用代码，Gist代码会存放在git的仓库，因此可以用git clone来克隆gist代码非常方便。
在octopress中可以这样引用gist代码

```
	{ % gist gist_id [filename] % }
```

###Include Code Snippets

####syntax
```
	{ % include_code [title] [lang:language] path/to/file % }
```

###Inline Code blocks

```
{ % codeblock [title] [lang:objc] [url] [link text] % }
[rectangle setX: 10 y: 10 width: 20 height: 20];
{ % endcodeblock % }
```
