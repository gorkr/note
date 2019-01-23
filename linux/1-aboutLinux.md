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



# 文件系统和命令行

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

