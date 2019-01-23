

everything is file, or processing. 



`dpkg-reconfigure keyboard-configuration`

`service keyboard-setup restart`

//////ip a  //显示ip配置

```shell
gorkr@gorkr-PC:~$ ssh supinfo@192.168.39.132
// 用户名@ip地址

The authenticity of host '192.168.39.132 (192.168.39.132)'         can't be established.
ECDSA key fingerprint is SHA256:HobZBthxKcXQgjWfagXm+SUHWlLhY/kjkaImOBoHOe0.
Are you sure you want to continue connecting (yes/no)? y
Please type 'yes' or 'no': yes
Warning: Permanently added '192.168.39.132' (ECDSA) to the list of known hosts.
supinfo@192.168.39.132's passwo
```
sudo su

exit //退出root

pwd //当前目录

nano //修改文件

tuch  filename//创建空文件

mkdir -p 1/2/3/4 如果123不存在，则创建123

rmdir -p

man man

chown  group:user //change owner  :happy:

grep 匹配文本 文件// 搜索文件里的内容  

ls /etc/ | grep .conf --color

 sudo grep -nHR --color Port /etc/

supinfo@debian-master:~$ grep -nHR --color Port /etc/ 2>erro  //吧错误都输出到了erro , 其他信息标准输出



cut -f1 -d ':' erro  //每一行的第一组

cut -f1,2 -d ':' erro 



Linux paste命令用于合并文件的列。paste指令会把每个文件以列对列的方式，一列列地加以合并。  -s 按行合并。

find /home/supinfo/ | cpio -ov > /tmp/home-archive.cpio

cpio -it < /tmp/home-archive.cpio

 cpio -id --no-absolute-filename < /tmp/home-archive.cpio 

 tar -cf /tmp/home-supinfo.tar /home/supinfo/q

supinfo@debian-master:~$ tar -czf /tmp/home-supinfo.tar.gz /home/supinfo/
tar: Removing leading `/' from member names
supinfo@debian-master:~$ tar -cjf /tmp/home-supinfo.tar.bz2 /home/supinfo/
tar: Removing leading `/' from member names



wget // 网络下载

wget http://ftp.gnu.org/gnu/hello/hello-2.7.tar.gz  //会显示解析过程，包括ip

http 默认端口80   https 默认端口443

tar -tf hello-2.7.tar.gz 

tar -xzvf

tar -xf hello-2.7.tar.gz d

supinfo@debian-master:~$ mkdir hello
supinfo@debian-master:~$ tar -xf hello-2.7.tar.gz -C hello/



bzip2 -v erro2

bunzip2 erro2.bz2 

gzip -v erro1

gunzip erro1.gz 

supinfo@debian-master:~$ gzip -1 erro1
supinfo@debian-master:~$ gzip -9 erro2

zcat(zless,zmore,zmost) erro1.gz  //查看内容，但不解压

-v verbose mode 详细模式， 列出过程。

 nano /etc/apt/sources.list// 修改apt源

vimtutor 打开vim引导

w 移动光标到单词末尾  $移动光标到行末   b单词开头 



s权限： 设置使文件在执行阶段具有文件所有者的权限，相当于临时拥有文件所有者的身份. 典型的文件是passwd. 如果一般用户执行该文件, 则在执行过程中, 该文件可以获得root权限, 从而可以更改用户的密码.

t权限：要删除一个文档，您不一定要有这个文档的写权限，但您一定要有这个文档的上级目录的写权限。也就是说，您即使没有一个文档的写权限，但您有这个文档的上级目录的写权限，您 也能够把这个文档给删除，而假如没有一个目录的写权限，也就不能在这个目录下创建文档。在一个目录上设了t权限位后，（如/home，权限为1777)任何的用户都能够在这个目录下创建文档，但只能删除自己创建的文档(root除外)，这就对任何用户能写的目录下的用户文档 启到了保护的作用。



adduser  

root@debian-master:/home/supinfo# useradd dummy
root@debian-master:/home/supinfo# cat /etc/passwd | grep dummy
dummy:x:1001:1001::/home/dummy:   //没有floder, 没有shell

root@debian-master:/home/supinfo# usermod -s /bin/bash dummy

mkdir /home/dummy

chown dummy:dummy /home/dummy/

 useradd -D -s /bin/bash //设置每次新建用户是，自动添加bash.、

mkdir /etc/skel/{Document,Virtual\ Machines,Movices}  //skel是一个样本文件，每次创建新用户都会创建一个与skel一样的文件夹



su user 切换不同用户。

创建一个webmaster组，并将supinfo添加进入组。
```shell

sudo groupadd -r webmaster
grep webmaster /etc/group
sudo gpasswd -a supinfo webmaster

supinfo@debian-master:~$ groups
supinfo cdrom floppy audio dip video plugdev netdev
supinfo@debian-master:~$ newgrp webmaster //激活组
supinfo@debian-master:~$ groups
webmaster cdrom floppy audio dip video plugdev netdev supinfo
```

```shell
//修改组密码
supinfo@debian-master:~$ sudo gpasswd accounting
Changing the password for group accounting
New Password: 
```
```shell
supinfo@debian-master:~$ ls /usr/bin | grep gpasswd
gpasswd
```


则么查看组内有什么用户。

更改文件权限
```shell
supinfo@debian-master:~$ ls -l /etc/passwd
-rw-r--r-- 1 root root 1567 Jan 17 03:39 /etc/passwd
supinfo@debian-master:~$ sudo chmod 640 /etc/passwd
supinfo@debian-master:~$ ls -l /etc/passwd
-rw-r----- 1 0 root 1567 Jan 17 03:39 /etc/passwd

or

supinfo@debian-master:~$ ls -l /etc/passwd
-rw-r--r-- 1 root root 1567 Jan 17 03:39 /etc/passwd
supinfo@debian-master:~$ sudo chmod o-r /etc/passwd
supinfo@debian-master:~$ ls -l /etc/passwd
-rw-r----- 1 0 root 1567 Jan 17 03:39 /etc/passwd

or

supinfo@debian-master:~$ sudo chmod o+rwx /etc/passwd
supinfo@debian-master:~$ ls -l /etc/passwd
-rw-r--rwx 1 root root 1567 Jan 17 03:39 /etc/passwd
supinfo@debian-master:~$ sudo chmod o= /etc/passwd
supinfo@debian-master:~$ ls -l /etc/passwd
-rw-r----- 1 0 root 1567 Jan 17 03:39 /etc/passwd
```

```shell
supinfo@debian-master:~$ ls -l /home/supinfo/
total 660
-rw-r--r--  1 1000 supinfo    855 Jan 15 10:35 dmesg-10-20
-rw-r--r--  1 1000 supinfo    639 Jan 16 04:44 erro
-rw-r--r--  1 1000 supinfo    706 Jan 16 04:43 errO
-rw-r--r--  1 1000 supinfo    194 Jan 16 04:22 erro1.gz
-rw-r--r--  1 1000 supinfo    186 Jan 16 04:21 erro2.gz
-rw-r--r--  1 1000 supinfo  32440 Jan 15 10:41 grep-manual
drwxr-xr-x  3 1000 supinfo   4096 Jan 16 04:15 hello
drwxr-xr-x 10 1000 supinfo   4096 Mar 28  2011 hello-2.7
-rw-r--r--  1 1000 supinfo 599680 Mar 29  2011 hello-2.7.tar.gz
drwxr-xr-x  3 1000 supinfo   4096 Jan 16 03:41 home
-rw-r--r--  1 1000 supinfo    855 Jan 15 10:36 message-end
-rw-r--r--  1 1000 supinfo      0 Jan 15 13:14 pic.png
drwxr-xr-x  2 1000 supinfo   4096 Jan 15 12:32 sandbox
-rw-r--r--  1 1000 supinfo      0 Jan 15 07:54 test
-rw-r--r--  1 1000 supinfo      0 Jan 15 07:54 test.conf
supinfo@debian-master:~$ ls -l /etc/passwd
-rw-r----- 1 0 root 1567 Jan 17 03:39 /etc/passwd
supinfo@debian-master:~$ sudo chmod o+r /etc/passwd
supinfo@debian-master:~$ ls -l /home/supinfo/
total 660
-rw-r--r--  1 supinfo supinfo    855 Jan 15 10:35 dmesg-10-20
-rw-r--r--  1 supinfo supinfo    639 Jan 16 04:44 erro
-rw-r--r--  1 supinfo supinfo    706 Jan 16 04:43 errO
-rw-r--r--  1 supinfo supinfo    194 Jan 16 04:22 erro1.gz
-rw-r--r--  1 supinfo supinfo    186 Jan 16 04:21 erro2.gz
-rw-r--r--  1 supinfo supinfo  32440 Jan 15 10:41 grep-manual
drwxr-xr-x  3 supinfo supinfo   4096 Jan 16 04:15 hello
drwxr-xr-x 10 supinfo supinfo   4096 Mar 28  2011 hello-2.7
-rw-r--r--  1 supinfo supinfo 599680 Mar 29  2011 hello-2.7.tar.gz
drwxr-xr-x  3 supinfo supinfo   4096 Jan 16 03:41 home
-rw-r--r--  1 supinfo supinfo    855 Jan 15 10:36 message-end
-rw-r--r--  1 supinfo supinfo      0 Jan 15 13:14 pic.png
drwxr-xr-x  2 supinfo supinfo   4096 Jan 15 12:32 sandbox
-rw-r--r--  1 supinfo supinfo      0 Jan 15 07:54 test
-rw-r--r--  1 supinfo supinfo      0 Jan 15 07:54 test.conf

```
supinfo@debian-master:~$ chmod o= /home/supinfo -R   //-R 迭代的修改

supinfo@debian-master:~$ find /home/supinfo/ -type d -exec chmod 750 {} \;



![1547695965147](/tmp/1547695965147.png)



![1547696034807](/tmp/1547696034807.png)

```
/
root@debian-master:/home/supinfo# ls -l messages
-rw-r----- 1 root root 782174 Jan 17 04:39 messages
root@debian-master:/home/supinfo# chown supinfo  messages
root@debian-master:/home/supinfo# ls -l messages
-rw-r----- 1 supinfo root 782174 Jan 17 04:39 messages

```

root@debian-master:/home/supinfo# export EDITOR=/usr/bin/vim //将默认编辑器变为vim 
root@debian-master:/home/supinfo# visudo 



supinfo@debian-master:~$ sudo timedatectl set-timezone 'Asia/Shanghai'

```
supinfo@debian-master:~$ ls /etc/init.d
apache2              console-setup.sh  dbus        keyboard-setup.sh  networking  rsyslog  sudo
apache-htcacheclean  cron              hwclock.sh  kmod               procps      ssh      udev
supinfo@debian-master:~$ sudo service ssh status
● ssh.service - OpenBSD Secure Shell server
   Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: enabled)

```

```
supinfo@debian-master:~$ ls /etc/init.d
apache2              console-setup.sh  dbus        keyboard-setup.sh  networking  rsyslog  sudo
apache-htcacheclean  cron              hwclock.sh  kmod               procps      ssh      udev
supinfo@debian-master:~$ sudo service ssh status
● ssh.service - OpenBSD Secure Shell server
   Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: enabled)

```

alias 建立别名 比如 ll

```shell
//.bashrc 更改shell上的命令

root@debian-master:/home/supinfo# vim ~/.bashrc
root@debian-master:/home/supinfo# source ~/.bashrc
root@debian-master:/home/supinfo# ll
total 1436
drwxr-xr-x  2 supinfo supinfo   4096 Jan 17 12:13 1
-rw-r-----  1 supinfo supinfo    855 Jan 15 17:35 dmesg-10-20
```
acl

```shell

root@debian-master:/home/supinfo# find /etc/apache2/ -type f -exec setfacl -m "g:webmaster:rw" {} \;
root@debian-master:/home/supinfo# ll /etc/apache2/
total 80
-rw-rw-r--+ 1 root root  7224 Nov  4 02:46 apache2.conf
drwxr-xr-x  2 root root  4096 Jan 17 15:01 conf-available
drwxr-xr-x  2 root root  4096 Jan 17 15:01 conf-enabled
-rw-rw-r--+ 1 root root  1782 Nov  3 19:34 envvars
-rw-rw-r--+ 1 root root 31063 Nov  3 19:34 magic
drwxr-xr-x  2 root root 12288 Jan 17 15:01 mods-available
drwxr-xr-x  2 root root  4096 Jan 17 15:01 mods-enabled
-rw-rw-r--+ 1 root root   320 Nov  3 19:34 ports.conf
drwxr-xr-x  2 root root  4096 Jan 17 15:01 sites-available
drwxr-xr-x  2 root root  4096 Jan 17 15:01 sites-enabled
```

yes

NAME
       yes - output a string repeatedly until killed



```shell
supinfo@debian-master:~$ yes > /dev/null &
[1] 639
supinfo@debian-master:~$ cat /dev/zero > /dev/null &
[2] 641
supinfo@debian-master:~$ cat /dev/null
supinfo@debian-master:~$ jobs
[1]-  Running                 yes > /dev/null &
[2]+  Running                 cat /dev/zero > /dev/null &
supinfo@debian-master:~$ fg
cat /dev/zero > /dev/null
ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttyyyyyyyyyyyyyyyyyyyyyyyyyy
^Z
[2]+  Stopped                 cat /dev/zero > /dev/null
supinfo@debian-master:~$ jobs
[1]-  Running                 yes > /dev/null &
[2]+  Stopped                 cat /dev/zero > /dev/null
supinfo@debian-master:~$ fg
cat /dev/zero > /dev/null
^Z
[2]+  Stopped                 cat /dev/zero > /dev/null
supinfo@debian-master:~$ fg %1
yes > /dev/null
^C                  
supinfo@debian-master:~$ jons
-bash: jons: command not found
supinfo@debian-master:~$ jobs
[2]+  Stopped                 cat /dev/zero > /dev/null
supinfo@debian-master:~$ kill %2

[2]+  Stopped                 cat /dev/zero > /dev/null
supinfo@debian-master:~$ jobs
[2]+  Terminated              cat /dev/zero > /dev/null


```
当你退出时登录时，所有进程都会被kill

```shell
supinfo@debian-master:~$ cat /dev/zero > dev/null &
[1] 663
supinfo@debian-master:~$ -bash: dev/null: No such file or directory

[1]+  Exit 1                  cat /dev/zero > dev/null
supinfo@debian-master:~$ cat /dev/zero > /dev/null &
[1] 664
supinfo@debian-master:~$ jobs 
[1]+  Running                 cat /dev/zero > /dev/null &
supinfo@debian-master:~$ exit
logout
Connection to 192.168.39.132 closed.
gorkr@gorkr-PC:~$ ssh supinfo@192.168.39.132
supinfo@192.168.39.132's password: 
Linux debian-master 4.9.0-3-amd64 #1 SMP Debian 4.9.30-2+deb9u5 (2017-09-19) x86_64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
Last login: Fri Jan 18 10:41:46 2019 from 192.168.39.1
supinfo@debian-master:~$ jobs

```

disown  分离进程， 成为系统进程。

默认nice是0

普通用户只能 增加ni不能减少ni 。 即只能降低优先级。

```
supinfo@debian-master:~$ ls /etc/init.d/cron -l
-rwxr-xr-x 1 root root 3049 May  3  2015 /etc/init.d/cron
supinfo@debian-master:~$ /etc/init.d/cron status
● cron.service - Regular background program processing daemon
```

```shell
supinfo@debian-master:~$ sudo touch /etc/cron.allow
supinfo@debian-master:~$ crontab -e
You (supinfo) are not allowed to use this program (crontab)
See crontab(1) for more information
supinfo@debian-master:~$ su
Password: 
root@debian-master:/home/supinfo# echo "supinfo" > /etc/cron.allow
root@debian-master:/home/supinfo# exit
exit
supinfo@debian-master:~$ crontab -e
no crontab for supinfo - using an empty one

Select an editor.  To change later, run 'select-editor'.
  1. /bin/nano        <---- easiest
  2. /usr/bin/vim.basic
  3. /usr/bin/vim.tiny

Choose 1-3 [1]: 


# m h  dom mon dow   command
0,15,30,45 * * * * /bin/date > /home/supinfo/date.cron


0 12,18 * * mon-fri /usr/bin/updatedb


```

`>>`向文件中追加，而不是覆盖。

crontab -r  移除crontab

```shell
root@debian-master:/home/supinfo# at 15:15
warning: commands will be executed using /bin/sh
at> reboot
at> <EOT>
job 2 at Fri Jan 18 15:15:00 2019
supinfo@debian-master:~$ sudo atq
1	Fri Jan 18 15:15:00 2019 a root

```

```shell
upinfo@debian-master:~$ at noon tomorrow
warning: commands will be executed using /bin/sh
at> reboot
at> <EOT>
job 3 at Sat Jan 19 12:00:00 2019
supinfo@debian-master:~$ at now + 6 hours
warning: commands will be executed using /bin/sh
at> sudo apt-get update 
at> <EOT>
job 4 at Fri Jan 18 21:18:00 2019
supinfo@debian-master:~$ atq
4	Fri Jan 18 21:18:00 2019 a supinfo
3	Sat Jan 19 12:00:00 2019 a supinfo
supinfo@debian-master:~$ atrm 3
supinfo@debian-master:~$ atq
4	Fri Jan 18 21:18:00 2019 a supinfo

```

```
supinfo@debian-master:~$ ls -du /var/log/messages
/var/log/messages
supinfo@debian-master:~$ ^du^lh^
ls -lh /var/log/messages
-rw-r----- 1 root adm 1.3M Jan 18 15:15 /var/log/messages

```

upinfo@debian-master:~$ touch supinfo{1,2,3}

```shell
supinfo@debian-master:~$ ls -de /home/supinfo/sandbox/
ls: invalid option -- 'e'
Try 'ls --help' for more information.
supinfo@debian-master:~$ ^de^lh^
ls -lh /home/supinfo/sandbox/
total 12K
drwxr-xr-x 2 supinfo supinfo 4.0K Jan 18 16:43 bin
drwxr-xr-x 2 supinfo supinfo 4.0K Jan 18 16:43 sbin
drwxr-xr-x 2 supinfo supinfo 4.0K Jan 18 16:43 user

```

history -c 清空历史。

```
supinfo@debian-master:~$ echo "export EDITOR=/usr/bin/vim" >> .bashrc
supinfo@debian-master:~$ source .bashrc

```

supinfo@debian-master:~$ export PAGER=/usr/bin/most

```shell
gorkr@gorkr-PC:~$ alias up="sudo apt-get update"
gorkr@gorkr-PC:~$ up
[sudo] gorkr 的密码：
命中:1 http://packages.deepin.com/deepin panda InRelease

gorkr@gorkr-PC:~$ unalias up
gorkr@gorkr-PC:~$ up

```

PPID

```shell
gorkr@gorkr-PC:~$ bash
gorkr@gorkr-PC:~$ ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000  8197  7424  0  80   0 -  5765 -      pts/1    00:00:00 bash
0 S  1000  8483  8197  0  80   0 -  5770 -      pts/1    00:00:00 bash
0 R  1000  8488  8483  0  80   0 -  7303 -      pts/1    00:00:00 ps

```

2>&1

- 2 stderr , 1 stdout.  将标准错误也定向到标准输出中。

BASH 的PID可以有变量$$ 取得
```
echo $$
```



 `kill -l` 列出所有的signal.

kill -singal PId, kill -singnal %Jobid, killall -signal commandName.

PRI(new) = PRI(old) + Nices

```shell
gorkr@gorkr-PC:~$ free -m
              total        used        free      shared  buff/cache   available
Mem:           7907         712        5310         377        1884        6566
Swap:          8112           0        8112

```

`uptime` 系统启动的时间与工作负载。 `uname` 系统与核心相关的信息。

```shell
gorkr@gorkr-PC:~$ netstat -tulnp
```

`dmesg`分析核心产生的信息。

```shell
gorkr@gorkr-PC:~$ sudo dmesg | grep -i sda
[    2.535880] sd 0:0:0:0: [sda] 250069680 512-byte logical blocks: (128 GB/119 GiB)
[    2.535906] sd 0:0:0:0: [sda] Write Protect is off
[    2.535908] sd 0:0:0:0: [sda] Mode Sense: 00 3a 00 00
[    2.535918] sd 0:0:0:0: [sda] Write cache: enabled, read cache: enabled, doesn't support DPO or FUA
[    2.537953]  sda: sda1 sda2 sda3 sda4
[    2.538189] sd 0:0:0:0: [sda] Attached SCSI disk

```
`vmstat` 实时监控系统资源分配。

```shell
gorkr@gorkr-PC:~$ vmstat 5
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 0  0      0 5009008  80280 2012752    0    0   132    22   92  229  1  0 96  2  0
 1  0      0 5010240  80280 2011748    0    0     0     0  319  786  0  0 99  0  0
 1  0      0 5009732  80280 2012032    0    0     1     0  538 1031  0  0 98  1  0
 1  0      0 5010036  80280 2011732    0    0     0    55  330  782  1  0 99  0  0
 1  0      0 5009988  80280 2011676    0    0     0     0  333  766  0  0 99  0  0

```

`chattr`  `lsattr` 配置文件或目录的隐藏属性。



####权限s 分为SUID 和 SGID。



 当s出现在**owner**权限的x上时 使用者在执行时拥有owner的权限,称为SUID。例如 `passwd`命令

```shell
gorkr@gorkr-PC:~$ ll /usr/bin/passwd
-rwsr-xr-x 1 root root 59640 4月  12  2018 /usr/bin/passwd
```

gorkr可执行`passwd`, 但它的owner是root. 因为s权限，所以当gorkr执行`passwd`时，将暂时获得root的权限即rwx. 所以`/etc/shadow`就能被gorkr所执行的`passwd`所修改

SUID只能作用在`binary file`上，不能作用于`shell script`.



当s出现在group权限的x上时，使用者执行时拥有group的权利,称为GUID。例如`locate`命令

SGID也可作用于目录，主要用途：若用户在目录下新建文件，该文件的群组与此目录的群组相同。



权限t即SBIT,只对目录有效。 当甲这个用户于A目录具有群组或者其他人的身份，并且拥有目录的w权限，这表示 甲用户对该目录内任何人建立的文件或目录均可进行‘增改善’ ， 不过在A上加入SBIT时，甲就只能对自己建立的目录进行操作。



在3为数之前，再加一位表示特殊权限。

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



#### `/proc/*` 内存

内存中的数据都写入到路径`/proc/`下，各个进程存在以pid命名的目录下。





**找出对当前目录的占用**

```shell
gorkr@gorkr-PC:~$ fuser -uv .
                     用户     进程号 权限   命令
/home/gorkr:         gorkr      5846 ..c.. (gorkr)startdde
                     gorkr      5975 ..c.. (gorkr)deepin-wm
                     gorkr      6019 ..c.. (gorkr)dde-session-dae
                     gorkr      6753 ..c.. (gorkr)deepin-cloud-pr
                     gorkr      6754 ..c.. (gorkr)dde-polkit-agen
                     gorkr      6765 ..c.. (gorkr)deepin-menu
                     gorkr      6947 ..c.. (gorkr)dde-osd
                     gorkr      7041 ..c.. (gorkr)deepin-terminal
                     gorkr      7046 ..c.. (gorkr)bash
                     gorkr      7057 ..c.. (gorkr)applet.py
                     gorkr      7152 ..c.. (gorkr)Typora
                     gorkr      7154 ..c.. (gorkr)Typora
                     gorkr      7185 ..c.. (gorkr)Typora
                     gorkr      7192 ..c.. (gorkr)Typora

```

`lsof`列出进程所开启的文档， `pidof`找出某个正在执行的进程的pid。



#### Daemon

systemctl 命令用来管理systemd，systemd常驻于内存。