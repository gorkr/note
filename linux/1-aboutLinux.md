#linux前瞻

####POSIX

POSIX表示可移植操作系统接口（Portable Operating System Interface of UNIX，缩写为 POSIX ），POSIX标准定义了操作系统应该为应用程序提供的接口标准。

POSIX标准意在期望获得[源代码](https://baike.baidu.com/item/%E6%BA%90%E4%BB%A3%E7%A0%81/3969)级别的[软件可移植性](https://baike.baidu.com/item/%E8%BD%AF%E4%BB%B6%E5%8F%AF%E7%A7%BB%E6%A4%8D%E6%80%A7/8320795)。换句话说，为一个POSIX兼容的操作系统编写的程序，应该可以在任何其它的POSIX操作系统（即使是来自另一个厂商）上编译执行。

####基本理念

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



