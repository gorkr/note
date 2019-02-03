# linux前瞻

#### POSIX

POSIX表示可移植操作系统接口（Portable Operating System Interface of UNIX，缩写为 POSIX ），POSIX标准定义了操作系统应该为应用程序提供的接口标准。

POSIX标准意在期望获得[源代码](https://baike.baidu.com/item/%E6%BA%90%E4%BB%A3%E7%A0%81/3969)级别的[软件可移植性](https://baike.baidu.com/item/%E8%BD%AF%E4%BB%B6%E5%8F%AF%E7%A7%BB%E6%A4%8D%E6%80%A7/8320795)。换句话说，为一个POSIX兼容的操作系统编写的程序，应该可以在任何其它的POSIX操作系统（即使是来自另一个厂商）上编译执行。

#### 基本理念

**everything is a file, if not, it's a process.** 

KISS

- Keep It Sample Stupid. 保持简单，并且一目了然。

RTFM

- Read The Fucking Manual.

kernel + userland

- userland:  操作系统中不属于kernel的呢一部分。

关于 open source:

- 开源并不意味着免费，开发者可以对他们的开源软件收取费用。
- 某些linux发行版，kernel开源，但是userland并不开源。

开源软件协议

- GPL, BSD, MPL, Apache...



#  文件系统和命令行

linux文件系统是 **树** 结构， 有单一的根， 唯一的入口。

可移动设备

- 需要将新的文件系统附加到现有的层次结构。

- 将文件系统bind到一个目录下, 通常位于 `/mnt/`。
- 使用`mount`命令。

硬件设备也被linux抽象为文件。并存储在`/dev/`下。例如，`/dev/sda`是硬盘的抽象，`/dev/snd`是声卡的抽象。

系统设置在`/proc/sys`下。



#### terminal, shell and console

terminal

- 终端([Terminal](http://en.wikipedia.org/wiki/Computer_terminal))也是一台物理设备，只用于输入输出，本身没有强大的计算能力。一台计算机只有一个控制台，在计算资源紧张的时代，人们想共享一台计算机，可以通过终端连接到服务器上，将指令输入终端，终端传送给计算机，计算机完成指令后，将输出传送给终端，终端将结果显示给用户。

terminal emulator

- 终端模拟器([Terminal Emulator](http://en.wikipedia.org/wiki/Terminal_emulator))，是一个程序，这些程序用来模拟物理终端。图形用户界面中的终端模拟器一般称为终端窗口(Terminal Window)，我们在Ubuntu下打开的gnome-terminal就属于此类。

shell

- 我们在终端模拟器中输入命令时，终端模拟器本身并不解释执行这些命令，它只负责输入输出，真正解释执行这些命令的，是shell。平时使用的sh, bash, csh是shell的不用实现。

console

- 控制台([Console](http://en.wikipedia.org/wiki/System_console))是物理设备，用于输入输出，它直接连接在计算机上，是计算机系统的一部分。计算机输出的信息会显示在控制台上，例如BIOS的输出，内核的输出。





#### symbolic link 和 hard link

**linux EXT文件系统**

Linux的Ext文件系统是如何与磁盘内存产生对应的呢？我们知道，在使用磁盘内存之前，需要为磁盘分区，然后为所分区域格式化出一个统一的文件系统（也有例外，如LVM与磁盘阵列技术）。那么，在这样一个统一的文件系统中，根据数据的不同，就可以将内存分为以下3种类型：

- inode 记录文件的属性，一个文件占用一个inode，同时记录此文件的数据所在的block号码
- block 实际记录文件的内容，如果文件太大，则会占用多个block
- super block 记录文件系统的整体信息，包括inode/block的总量、使用量、剩余量，以及文件系统的格式与相关信息等

因此对于一个文件来说，它的inode号就类似于id的作用，用于存放关于该文件的一些基本信息。

**硬链接（hard link）**
硬链接实际上是一个指针，指向源文件的inode，系统并不为它重新分配inode。硬连接不会建产新的inode，硬连接不管有多少个，都指向的是同一个inode节点，只是新建一个hard link会把结点连接数增加，只要结点的连接数不是0，文件就一直存在，不管你删除的是源文件还是连接的文件。只要有一个存在，文件就存在（其实就是引用计数的概念)。当你修改源文件或者连接文件任何一个的时候，其他的文件都会做同步的修改。

**软链接（soft link）**
软链接最直观的解释：相当于Windows系统的快捷方式，是一个独立文件（拥有独立的inode,与源文件inode无关），该文件的内容是源文件的路径指针，通过该链接可以访问到源文件。所以删除软链接文件对源文件无影响，但是删除源文件，软链接文件就会找不到要指向的文件（可以类比Windows上快捷方式，你点击快捷方式可以访问某个文件，但是删除快捷方式，对源文件无任何影响）。



#### 流和重定向

0 stdin, 1 stdout, 2 stderr

- `2>&1` 将标准错误也重定向到标准输出中。
- `>>`  追加模式





# 常用命令

#### `cut`命令

```shell
-b：仅显示行中指定直接范围的内容；

-c：仅显示行中指定范围的字符；

-d：指定字段的分隔符，默认的字段分隔符为“TAB”；

-f：显示指定字段的内容；
```

1. 分割并提取字段

    ```shell
    gorkr@gorkr-PC:~$ cat test
    no name mark percent
    01 bob 12 11
    02 tom 21 22
    gorkr@gorkr-PC:~$ cut -d' ' -f2,3 test
    name mark
    bob 12
    tom 21
    gorkr@gorkr-PC:~$ cut -d' ' -f2,3 --complement test
    no percent
    01 11
    02 22
    ```

2. 选取字段

    ```shell
    gorkr@gorkr-PC:~$ cut -c1-4 test
    no n
    01 b
    02 t
    ```

#### `paste`命令

```shell
-d: 用指定的间隔字符取代跳格字符。
-s: 串列进行而非平行处理。
```

```shell
gorkr@gorkr-PC:~$ cat t1
a
b
c
d
gorkr@gorkr-PC:~$ cat t2
1
2
3
4
gorkr@gorkr-PC:~$ paste t1 t2 > s1
gorkr@gorkr-PC:~$ cat s1
a	1
b	2
c	3
d	4
gorkr@gorkr-PC:~$ paste -d':' t1 t2
a:1
b:2
c:3
d:4
gorkr@gorkr-PC:~$ paste t1 -s
a	b	c	d
gorkr@gorkr-PC:~$ paste t1 t2 -s
a	b	c	d
1	2	3	4

```

#### `sort`命令

```shell
gorkr@gorkr-PC:~$ cat seq 
banana
apple
pear
orange
apple
pear

gorkr@gorkr-PC:~$ sort seq

apple
apple
banana
orange
pear
pear
gorkr@gorkr-PC:~$ sort seq -u

apple
banana
orange
pear
gorkr@gorkr-PC:~$ sort seq -u -o seq
gorkr@gorkr-PC:~$ cat seq

apple
banana
orange
pear

```

#### `wc`命令

在默认的情况下，wc将计算指定文件的行数、字数，以及字节数。

```shell
gorkr@gorkr-PC:~$ wc seq 
 5  4 26 seq           
```

####`nl`命令

```shell
gorkr@gorkr-PC:~$ nl -s'ge  ' seq
          
     1ge  apple
     2ge  banana
     3ge  orange
     4ge  pear
gorkr@gorkr-PC:~$ nl -v 3 seq
       
     3	apple
     4	banana
     5	orange
     6	pear
gorkr@gorkr-PC:~$ nl -i 3 seq
       
     1	apple
     4	banana
     7	orange
    10	pear
```

#### `tr`命令

1. 删除文件中的空行

```shell
$ echo -e "1\n\n2\n\n\n3" | tr -s '\n' #输出1\n2\n3
```

  如果参数-s替换为-d，就是删除所有换行符，输出结果为123。

2. 删除重复字符

```shell
$ echo "Hellooo    Javaaa" | tr -s "[ ao]" #输出Hello Java
```

  说明：-s是删除所有重复出现字符序列，只保留第一个。再用下面一个例子加深一下这句话的理解。

```shell
$ echo "Heoolloooo oo Pythonnnnn" | tr -s 'on' #删除字符on，输出Heollo o Python
```

3. 删除空格

```shell
$ echo "   Hello World  " | tr -d '[ \t]' #删除空格，包括tab键。输出HelloWorld
```

 说明：这里tr命令会删除包括中间的空格，如果只需要删除行首或者尾部的空格，可以使用sed命令。

4. 大小写替换，shell编程中可用于忽略大小写的字符串判断场景。

```shell
$ echo "Hello World" | tr '[a-z]' '[A-Z]' #小写转大写，输出HELLO WORLD
$ echo "Hello World" | tr '[A-Z]' '[a-z]' #大写转小写，输出hello world
$ echo "Hello World" | tr '[A-Za-z]' '[a-zA-Z]' #大小写互换，输出hELLO wORLD
```

5. 删除数字或字母，在shell编程中可用于判断输入是否为纯数字或字母。

```shell
$ echo "hello 123World456" | tr -d '[0-9]' #删除数字，输出hello World
$ echo "hello123World456" | tr -d '[a-zA-Z]' #删除字母，输出123456
```

6. 将多行内容合并为一行。

```shell
$ echo -e "1\n2\n3\n4" | tr -d '\n' #输出1234
```

7. 将多个连续空格合并为一个空格，并将空格替换为破折号‘-’。

```shell
$ echo "2018       06  01" |tr -s ' ' '-' #输出2018-06-01
```

8. 删除非数字字符，主要用于了解下-c参数的作用。

```shell
$ echo "2018abcdefdf06zzz01" |tr -d -c '[0-9]' #输出20180601
```

#### 搜索

`find` 命令 和 `locate`,`updatedb`。  



# 打包和压缩

**元数据**（**Metadata**）
为描述数据的数据（data about data），主要是描述数据属性（property）的信息，用来支持如指示存储位置、历史数据、资源查找、文件记录等功能。元数据算是一种电子式目录，为了达到编制目录的目的，必须在描述并收藏数据的内容或特色，进而达成协助数据检索的目的。

压缩并不会破坏数据。

#### `tar`命令

```
-v: verbose mode
-t: 列出，但不解包
-x: 解包
-c: 打包
-z: to compress or decompress *.gz
-j: to compress or decompress *.bz2  #就算不添加zj参数，tar也会自动执行解压缩。
-f: 指定对象
```

#### `Gzip` and `bzip2`

他们再压缩/解压完成后默认会删除源文件。

bz2压缩率更高，gz压缩速率更快。

压缩：

```shell
gzip file
bzip2 file
```

解压：

``` shell
gzip -d file.gz
gunzip file.gz
bzip2 -d file.bz2
bunzip2 file.bz2
```

#### `(bz|z)(cat|less|more)`命令

```shell
zcat /proc/config.gz
bzcat file.bz2
```



# 用户，群组和权限

**CRUD **增加(Create)、读取查询(Retrieve)、更新(Update)和删除(Delete)



- 系统管理员：root, 0 
- 系统用户：系统用户通常是不可登陆的，执行某些服务及进程的帐号 。 1-999
- 登录用户：一般用户， 1000-

```shell
/etc/passwd: 用户帐号的相关信息
/etc/group: 组帐号的相关信息
/etc/shadow: 用户密码及相关属性
/etc/gshadow: 组密码及相关属性
```

#### 目录权限

- r 可以查阅目录下的文件名数据。例如可以使用`ls`。
- w 可以增改删
- x 可进入该目录成为工作目录。即`cd`。

要读一个文件时首先要有这个文件所在目录的x权限。

#### linux文件类型 

- 正规文件： `-`， 包括纯文本，二进制文件 和 数据格式文件。
- 目录：`d` 。
- 硬链接： `l`。
- 设备与配置文件， 通常存在与`/dev/`下
  - 区块设备档(block)： `b` , 如硬盘。
  - 字符设备文件(character)： `c`, 串行端口的接口设备， 例如键盘，鼠标。
- 资料接口文件(sockets)： 被用于网络上的数据承接，`s`,通常位于`/run`,`/tmp`。
- 数据输送文件(FIFO, pipe)： 解决多个程序同时存取一个文件造成的错误问题。`p`。        

#### 默认权限与隐藏权限

umask 权限默认值  ， 0022

建立文件时 ： (-rw-rw-rw-) - 0022 = -rw-r--r--

建立目录时 ： (drwxrwxrwx) - 0022 = drwxr-xr-x



##### 权限s 分为SUID 和 SGID。

 当s出现在**owner**权限的x上时 使用者在执行时拥有owner的权限,称为SUID。例如 `passwd`命令

```shell
gorkr@gorkr-PC:~$ ll /usr/bin/passwd
-rwsr-xr-x 1 root root 59640 4月  12  2018 /usr/bin/passwd
```

gorkr可执行`passwd`, 但它的owner是root. 因为s权限，所以当gorkr执行`passwd`时，将暂时获得root的权限即rwx. 所以`/etc/shadow`就能被gorkr所执行的`passwd`所修改

SUID只能作用在`binary file`上，不能作用于`shell script`.



当s出现在group权限的x上时，使用者执行时拥有group的权利,称为GUID。例如`locate`命令。

SGID也可作用于目录，主要用途：若用户在目录下新建文件，该文件的群组与此目录的群组相同。



权限t即SBIT,只对目录有效。 当甲这个用户于A目录具有群组或者其他人的身份，并且拥有目录的w权限，这表示 甲用户对该目录内任何人建立的文件或目录均可进行‘增改善’ ， 不过在A上加入SBIT时，甲就只能对自己建立的目录进行操作。



在3位数之前，再加一位表示特殊权限。

- 4 SUID
- 2 SGID
- 1 SBIT

```shell
gorkr@gorkr-PC:~$ cd /tmp
gorkr@gorkr-PC:/tmp$ touch test
gorkr@gorkr-PC:/tmp$ ll test 
-rw-r--r-- 1 gorkr gorkr 0 1月  23 10:45 test
gorkr@gorkr-PC:/tmp$ chmod 4755 test 
gorkr@gorkr-PC:/tmp$ ll test
-rwsr-xr-x 1 gorkr gorkr 0 1月  23 10:45 test
```



# `sudo`和Aliases

```shell
sudo -l     #列出当前用户可以执行的特权命令
```

####`visudo`

Linux默认是没有将用户添加到sudoers列表中的，需要root手动将账户添加到sudoers列表中，才能让普通账户执行sudo命令。

sudo 配置文件存储于`/etc/sudoers`。只用root用户有修改的权限。但推荐使用`visudo`命令，而不是直接修改配置文件。

```shell
root@gorkr-PC:/home/gorkr# export EDITOR=/usr/bin/vim
root@gorkr-PC:/home/gorkr# visudo
```

```shell
bill ALL = (ALL) NOPASSWD:/sbin/reboot
%wheel ALL = (ALL) ALL, !/bin/su
```

#### `Aliases`

在`visudo`通过创建别名，使命令管理更为方便。

```shell
Cmnd_Alias BACKUPS = /usr/bin/tar,/usr/bin/rsync,/usr/bin/dump
User_Alias BOPS = john, bill, sarah, %wheel
BOPS ALL = (ALL) NOPASSWD:BACKUPS
```

####`sudoedit`

`sudoedit` = `sudo -e`

要使用sudoedit，sudoers中的条目应该是，例如，这样的东西：

```shell
%newsudo ALL = sudoedit /path/to/file
```

而“newsudo”组的一部分用户将能够通过运行以下命令来编辑该文件：

sudoedit /path/to/file

那么这个命令会做什么呢，它会首先创建你要编辑的文件的临时副本。 然后，命令将搜索SUDO_EDITOR，VISUAL和EDITOR环境变量（按此顺序），以确定应调用哪个编辑器来打开刚刚创建的临时副本。 用户完成修改工作后，更改将复制回原始文件。



# ACL

Access Control List, ACL可以针对单一的文件或目录来进行r,w,x的权限规范。

`getfacl` `setfacl`

```shell
gorkr@gorkr-PC:~/test$ ll
总用量 0
-rw-r--r-- 1 gorkr gorkr 0 1月  25 13:50 ms
gorkr@gorkr-PC:~/test$ setfacl -m u:gorkr:rx ms
#等同于u::rx , ::为空，文件的owner
gorkr@gorkr-PC:~/test$ ll
总用量 0
-rw-r-xr--+ 1 gorkr gorkr 0 1月  25 13:50 ms
gorkr@gorkr-PC:~/test$ getfacl ms
# file: ms
# owner: gorkr
# group: gorkr
user::rw-
user:gorkr:r-x
group::r--
mask::r-x
other::r--
gorkr@gorkr-PC:~/test$ mkdir childtest
gorkr@gorkr-PC:~/test$ ll
总用量 4
drwxr-xr-x  2 gorkr gorkr 4096 1月  25 17:05 childtest
-rw-r-xr--+ 1 gorkr gorkr    0 1月  25 13:50 ms
#说明acl会继承
```

同理可设置`g`组权限 ，`m`设置mask。

**mask**的意义是，用户或组设定的权限必须要存在于mask才能生效。

`setfal -b 档名` 取消全部acl, `-x`取消单一acl。

acl拥有继承的属性。



# 进程

程序存放在实体磁盘中，通过用户命令触发。触发后会加载到内存中成为一个个体，就是**进程**。

系统透过PID来判断该process是否有权限进行工作。又这个进程衍生出来的子进程，一般也会沿用相关权限。

##### 进程状态：

- running: has cpu time
- runnable: waits for cpu time
- sleeping:  does nothing/ waits for something
- zombie/defunt

##### fork and exec: 进程呼叫的流程

linux的进程呼叫通常成为`fork-and-exec`的流程。进程都会由父进程以复制(fork)的方式产生一个一模一样的子进程，然后被复制出来的子进程再以exec的方式来执行实际要进行的程序，最终成为一个真正的子进程。(期间会产生一个PPID)

如果父进程die, 子进程也die。

##### zombie

一个进程已经执行完毕，或者因故应该要终止了，但该进程的父进程却无法完整的将该进程结束掉，而造成这个进程一直存在于内存中，就成为zombie。想要杀掉zombie，就要找到并kill父进程。

##### Daemon

常住于内存中的进程通常都是负责一些系统所提供的功能以服务用户的各项活动，因此这些常驻程序就被称为: Daemon 。



`pgrep` pgrep 是通过程序的名字来查询进程的工具，一般是用来判断程序是否正在运行。 `pkill` 同理。

 `kill -l` 列出所有的signal.

| 数字 | 描述    | 详细                                   |
| ---- | ------- | -------------------------------------- |
| 15   | SIGTERM | 尝试以正常方式终止一项工作             |
| 9    | SIGKILL | 立即强制删除一个工作                   |
| 2    |         | Ctrl+c                                 |
| 1    | SIGHUP  | 重新读取一次参数的配置文件(类似reload) |



# 任务排程

`crontab` 和 `at`， 配置文件位于`/var/spool/(cron|at)`下。

需要在`/etc`下存在cron.allow,cron.deny, at.allow, at.deny.

- allow文件存在时，只有allow中列出的用户允许使用排程，同时deny文件将不会被解析。
- allow文件不存在时，只有deny文件中被列出的用户不能使用盘排程。
- 都不存在时，只允许root。

