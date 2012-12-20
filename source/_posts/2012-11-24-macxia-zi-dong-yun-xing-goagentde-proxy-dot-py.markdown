---
layout: post
title: "[转pcbeta]mac下自动运行goagent的proxy.py"
date: 2012-11-24 07:11
comments: true
categories: [mac]
---
在mac.pcbeta.com的论坛中发现了可以在mac下自动运行goagent的proxy.py脚本的方法：
1、终端下运行下面的命令：
{% codeblock lang:sh %}
sudo vi /Library/LaunchDaemons/com.go.agent.plist
{% endcodeblock %}
2、粘贴如下代码，并保存
{% codeblock lang:xml %}
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN"
        "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
        <key>Label</key>
        <string>com.go.agent</string>
        <key>ProgramArguments</key>
        <array>
<string>python</string>               
<string>/Volumes/LENOVO/soft/Proxy/goagent-goagent-91cd5e4/local/proxy.py</string>
        </array>
        <key>RunAtLoad</key>
        <true/>
</dict>
</plist>
{% endcodeblock %}
3、然后在终端执行如下命令，重启即可：
{% codeblock lang:sh %}
sudo chown root:wheel /Library/LaunchDaemons/com.go.agent.plist
{% endcodeblock %}
