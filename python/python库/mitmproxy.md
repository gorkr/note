>转载自:https://blog.wolfogre.com/posts/usage-of-mitmproxy/``
> https://blog.csdn.net/claysystem/article/details/48600285?utm_source=blogxgwz1


打开ssr,手动配置代理后,无法使用mitmproxy.

## mitmproxy是什么

`mitmproxy`就是用于 MITM 的 proxy，MITM 即中间人攻击（Man-in-the-middle attack）。用于中间人攻击的代理首先会向正常的代理一样转发请求，保障服务端与客户端的通信，其次，会适时的查、记录其截获的数据，或篡改数据，引发服务端或客户端特定的行为。

不同于 `fiddler` 或 `wireshark 等抓包工具，`mitmproxy` 不仅可以截获请求帮助开发者查看、分析，更可以通过自定义脚本进行二次开发。举例来说，利用 fiddler 可以过滤出浏览器对某个特定 url 的请求，并查看、分析其数据，但实现不了高度定制化的需求，类似于：“截获对浏览器对该 url 的请求，将返回内容置空，并将真实的返回内容存到某个数据库，出现异常时发出邮件通知”。而对于 mitmproxy，这样的需求可以通过载入自定义 python 脚本轻松实现。

但 mitmproxy 并不会真的对无辜的人发起中间人攻击，由于 mitmproxy 工作在 HTTP 层，而当前 HTTPS 的普及让客户端拥有了检测并规避中间人攻击的能力，所以要让 mitmproxy 能够正常工作，**必须要让客户端（APP 或浏览器）主动信任 mitmproxy 的 SSL 证书，或忽略证书异常**，这也就意味着 APP 或浏览器是属于开发者本人的——显而易见，这不是在做黑产，而是在做开发或测试。

那这样的工具有什么实际意义呢？据我所知目前比较广泛的应用是做仿真爬虫，即利用手机模拟器、无头浏览器来爬取 APP 或网站的数据，mitmpproxy 作为代理可以拦截、存储爬虫获取到的数据，或修改数据调整爬虫的行为。

事实上，以上说的仅是 mitmproxy 以正向代理模式工作的情况，通过调整配置，mitmproxy 还可以作为透明代理、反向代理、上游代理、SOCKS 代理等，但这些工作模式针对 mitmproxy 来说似乎不大常用，故本文仅讨论正向代理模式。

## 安装

`sudo pip3 install mitmproxy`

完成后，系统将拥有 `mitmproxy`、`mitmdump`、`mitmweb` 三个命令，由于 mitmproxy 命令不支持在 windows 系统中运行（这没关系，不用担心），我们可以拿 mitmdump 测试一下安装是否成功，执行：

`mitmdump --version`

## 运行

要启动 mitmproxy 用 `mitmproxy`、`mitmdump`、`mitmweb` 这三个命令中的任意一个即可，这三个命令功能一致，且都可以加载自定义脚本，唯一的区别是交互界面的不同。

- `mitmproxy` 命令启动后，会提供一个命令行界面

- `mitmweb` 命令启动后，会提供一个 web 界面

- `mitmdump` 命令启动后——你应该猜到了，没有界面，程序默默运行，所以 mitmdump 无法提供过滤请求、查看数据的功能，只能结合自定义脚本，默默工作。

用法在命令行中输入:
`mitmproxy –p 8800 `(后面跟要代理的端口)

拦截HTTP请求的话要在使用的浏览器上面设置代理

里面会有两个选项卡request发出的请求和 response响应 TAB键进行这两个选项卡的切换
想退出的话 直接按q键
