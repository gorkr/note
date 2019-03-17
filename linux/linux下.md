 # 软件包管理

1. 源码包 (.tar.gz)

   经过源码包安装，更适合本机，能提高5%左右的效率。

2. 脚本安装包 (setup.sh)

3. 二进制包 (rpm, 已经经过编译，看不到源码，但是加快的安装速度)



rpm包的命名规则：

| httpd | -2.2.15 | -15      | -ei6.centos.l. | i686     | .rpm |
| ----- | ------- | -------- | -------------- | -------- | ---- |
| 包名  | 版本号  | 发布次数 | 适用linux版本  | 支持硬件 | 后缀 |



- 树形依赖

- 环形依赖  a->b->c->a

  解决方法是，用一条命令将abc同时安装。



```sh
rpm -ivh *****.rpm  # 安装rpm包
    -U  # 升级
    -e  # 卸载
    -q 包名  # 查询包是否被安装
    -qa  # 列出所有已经安装的包
    -qi 包名  # 查看包信息
    -ql 包名  # 包文件安装位置
```

rpm包默认安装路径

```sh
/etc/
/usr/bin
/usr/lib
/usr/share/doc  # 说明文档
/usr/share/man  # 使用手册
```

源码安装默认位置

```sh
/usr/local/软件名/
```

位置不同带来的影响：

```sh
rpm:
/etc/rc.d/init.d/httpd start
service httpd start

source code:
/usr/local/apache2/bin/apachetl start  # README文件内有
```



源码安装方法

```sh
/usr/local/src  # 源码文件存储位置
/usr/local  # 软件包安装位置

INSTALL 安装说明。  README  使用说明。
```

1. 解压，并进入目录

2. ./configure 软件配置与检查

   ```sh
   ./configure --prefix=directory  # prefix指定安装路径
   ```

3. `make`

4. `make install`



# shell和shell编程

```sh
echo -e "\e[1;31m abcd \e[0m"  # 红色输出abcd
# \e[1; 开启颜色模式.  \e[0m 关闭颜色模式.
```



两种执行脚本的方式

- ```sh
  chmod 755 hello.sh
  ./hello.sh  # 推荐方法
  ```

- ```sh
  bash hello.sh  # 并不推荐
  ```

`dos2unix`命令将windos下编写的script转换为unix可读取的格式. (unix和windows中回车符表示不同)



历史命令

`~/.bash_history`文件保存历史命令, 默认保存2000条, 可以在`/etc/profile`里修改`HISTORYSIZE`变量.



命令别名

```sh
alias vi='vim'  # 临时生效
```

优先级: 路径>别名>内建>PATH



常用快捷键

| 操作     | 效果        | 操作     | 效果 |
| -------- | ----------- | -------- | ---- |
| ctrl + u | 删除/剪切行 | ctrl + l | 清屏 |
| ctrl + y | 粘贴        | ctrl + r | 搜索 |
| ctrl + d | 退出终端    |          |      |



重定向

```sh
ls >> file 2>&!
ls >> file1 2>> file2
wc < file
```

```sh
command1; command2;  # 顺序执行
command1 && command2  # 1执行,2执行; 1不执行,2不执行.
command1 || commmand2  # 1执行,2不执行; 1不执行,2执行.

./configure && make && make install
```



符号

| 符号      | 意义                           |
| --------- | ------------------------------ |
| ''        | 其中所有特殊符号都无特殊意义.  |
| ""        | 除了'$','`','\'外都无特殊意义. |
| `` 和 $() | 执行命令  如: abc=$(date) .    |
| $         | 调用变量值                     |



用户自定义变量

- bash中变量的默认类型都为字符串类型.
- `${变量}123` 在变量后追加123.
- `set` 和 `unset`



正则表达

| 表达式 | 意义 |
| ------ | ---- |
| \\{n\\}  | 表示其前面的字符恰好出现n次, : [0-9]\\{4\\} |
| \\{n,\\} | 表示其前面的字符出现不少于n次 |
| \\{n,m\\} | n-m次 |



`grep` 用来提取行, `cut`用来提取列. 





环境变量

如果把环境变量写进配置文件里,那么这个环境变量在所有的shell中生效.  环境变量在**子进程**中也生效.

```sh
export 变量=值  # 声明环境变量
PATH="$PATH":/gorkr/sh  # 将/gorkr/sh也加入环境变量
```

`env`查看所有环境变量.

环境变量`$PS1`代表提示符格式.



位置参数变量

| 变量 | 意义                        |
| ---- | --------------------------- |
| $n   | $0 命令本身; $1 第一个参数. |
| $*   | 命令中所有参数              |
| $#   | 参数个数                    |



预定义变量

| 变量 | 意义                                     |
| ---- | ---------------------------------------- |
| $?   | 上一条命令的执行状态. 0正常执行,非0出错. |
| $$   | 当前进程的进程号                         |
| $!   | 后台运行的最后一个进程的进程号           |



接收键盘输入:

```sh
read -p "提示信息" -t 秒数 -n 字符数 -s 隐藏输入.
```



运算符:

```sh
declare 声明变量类型  -: 给变量设定类型
                    +: 删除变量类型
                   -i: 将变量声明为整型
                   -x: 将变量声明为环境变量
                   -p: 显示变量的类型
                   
gorkr@gorkr-PC:~$ a=1
gorkr@gorkr-PC:~$ b=2
gorkr@gorkr-PC:~$ c=$a+$b
gorkr@gorkr-PC:~$ echo $c
1+2
gorkr@gorkr-PC:~$ declare -i c=$a+$b
gorkr@gorkr-PC:~$ echo $c
3

# 变量=$(命令) 将命令执行结果赋值给变量.
gorkr@gorkr-PC:~$ d=$(expr $a + $b)
gorkr@gorkr-PC:~$ echo $d
3

# $((运算时)) 或 $[] 专门用来进行整形计算
gorkr@gorkr-PC:~$ f=$((a+b+c+d))
gorkr@gorkr-PC:~$ echo $f
9
```



环境变量配置文件

```sh
/etc/profile
/etc/profile.d/*.sh
~/.bash_profile
~/.bashrc
/etc/bashrc
```



本机欢迎信息:

```sh
/etc/issue
/etc/issue.net  # 远程登录
/etc/motd  # 登陆后的安全信息
```

























































---

