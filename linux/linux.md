

`dpkg-reconfigure keyboard-configuration`

`service keyboard-setup restart`

//////ip a  //显示ip配置+

##### ssh 远程链接服务器：

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

mkdir -p 1/2/3/4 如果123不存在，则创建123

rmdir -p

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

man man cpio -id --no-absolute-filename < /tmp/home-archive.cpio 

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

```shell
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

#### 执行文件路径变量： `$PATH`

```shell
gorkr@gorkr-PC:~$ echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games:/sbin:/usr/sbin
root@gorkr-PC:/home/gorkr# echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

root@gorkr-PC:/home/gorkr# PATH="{PATH}:/root"
root@gorkr-PC:/home/gorkr# echo $PATH 
{PATH}:/root
root@gorkr-PC:~# PATH='/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin'

```

##### 将用户添加进组

```shell
orkr@gorkr-PC:~$ groups ninggou
ninggou : ninggou
gorkr@gorkr-PC:~$ sudo su
root@gorkr-PC:/home/gorkr# gpasswd -a ninggou sudo
正在将用户“ninggou”加入到“sudo”组中
root@gorkr-PC:/home/gorkr# exit
exit
gorkr@gorkr-PC:~$ groups ninggou
ninggou : ninggou sudo
```

# source

```shell
source FileName
```

在当前bash环境下读取并执行FileName中的命令。

*注：该命令通常用命令“.”来替代。*

```shell
source filename 
. filename（中间有空格）
```



# ～～设置开机自启～～

第三种方式  设置程序的.desktop文件
通过将应用程序的.desktop文件放在自启动目录下，那么当用户登陆桌面环境时，就会自动启动这些应用程序。

linux中自启动目录是\$XDG_CONFIG_DIRS/autostart和$？XDG_CONFIG_HOME/autostart这两个，可以打印看一下，有的可能只有其中一个。

把设置好的.desktop放在这两个目录下，那么指定的程序就会在桌面环境启动时启动，当两个自启动目录同时存在相同的文件时，只会运行其中一个（$XDG_CONFIG_HOME）。

program.desktop文件写法：

```


[Desktop Entry]

Name=program

Exec=/usr/bin/program

Type=Application

Comment=my program

```

只需要有这关键的几行就可以了，Exec的路径一定要正确。.desktop文件还有其他定制项，可参考其他文章。



# 远程部署实录

```
# 在 root 用户下运行这条命令创建一个新用户，yangxg 是用户名
# 因为我叫杨学光，所以我取的用户名是 yangxg
# 选择一个你喜欢的用户名，不一定非得和我的相同
root@localhost:~# useradd -m -s /bin/bash yangxg

# 把新创建的用户加入超级权限组
root@localhost:~# usermod -a -G sudo yangxg

# 为新用户设置密码
# 注意在输密码的时候不会有字符显示，不要以为键盘坏了，正常输入即可
root@localhost:~# passwd yangxg

# 切换到创建的新用户
root@localhost:~# su - yangxg

# 切换成功，@符号前面已经是新用户名而不是 root 了
yangxg@localhost:~$
```


# 禁用笔记本键盘

```shell
gorkr@gorkr-PC:~$ xinput --list
⎡ Virtual core pointer                    	id=2	[master pointer  (3)]
⎜   ↳ Virtual core XTEST pointer              	id=4	[slave  pointer  (2)]
⎜   ↳ MOSART Semi. 2.4G INPUT DEVICE          	id=13	[slave  pointer  (2)]
⎜   ↳ HID 04b4:2009                           	id=15	[slave  pointer  (2)]
⎜   ↳ SynPS/2 Synaptics TouchPad              	id=17	[slave  pointer  (2)]
⎣ Virtual core keyboard                   	id=3	[master keyboard (2)]
    ↳ Virtual core XTEST keyboard             	id=5	[slave  keyboard (3)]
    ↳ Power Button                            	id=6	[slave  keyboard (3)]
    ↳ Video Bus                               	id=7	[slave  keyboard (3)]
    ↳ Video Bus                               	id=8	[slave  keyboard (3)]
    ↳ Power Button                            	id=9	[slave  keyboard (3)]
    ↳ Sleep Button                            	id=10	[slave  keyboard (3)]
    ↳ HD Webcam                               	id=11	[slave  keyboard (3)]
    ↳ MOSART Semi. 2.4G INPUT DEVICE          	id=12	[slave  keyboard (3)]
    ↳ HID 04b4:2009                           	id=14	[slave  keyboard (3)]
    ↳ AT Translated Set 2 keyboard            	id=16	[slave  keyboard (3)]
    ↳ MOSART Semi. 2.4G INPUT DEVICE          	id=18	[slave  keyboard (3)]
    ↳ HID 04b4:2009                           	id=19	[slave  keyboard (3)]
gorkr@gorkr-PC:~$ xinput set-prop 16 "Device Enabled" 0

```



Linux dmesg命令用于显示开机信息。



```sh
supinfo@debian-master:~$ cat /etc/apt/sources.list
# 

# deb cdrom:[Debian GNU/Linux 9.1.0 _Stretch_ - Official amd64 NETINST 20170722-11:28]/ stretch main

#deb cdrom:[Debian GNU/Linux 9.1.0 _Stretch_ - Official amd64 NETINST 20170722-11:28]/ stretch main

deb http://ftp.cn.debian.org/debian/ stretch(代表debian的可用版本) main
deb-src http://ftp.cn.debian.org/debian/ stretch main

deb http://security.debian.org/debian-security stretch/updates main
deb-src http://security.debian.org/debian-security stretch/updates main

# stretch-updates, previously known as 'volatile'
deb http://ftp.cn.debian.org/debian/ stretch-updates main
deb-src http://ftp.cn.debian.org/debian/ stretch-updates main
```

wget 是一个从网络上自动下载文件的自由工具

```sh
supinfo@debian-master:~$ cd ncftp-3.2.6/
supinfo@debian-master:~/ncftp-3.2.6$ ls
autoconf_local	config.h.in  configure	configure.in  doc
supinfo@debian-master:~/ncftp-3.2.6$ ./configure --h
--help   --host=  
```



更新linux版本

```
supinfo@debian-master:~/ncftp-3.2.6$ sudo apt-get dist-upgrade
```



显示所用apt安装的包

```
apt list --installed 
```



```
supinfo@debian-master:~/ncftp-3.2.6$ dpkg -S /bin/ls  #搜索包含这个文件的包
coreutils: /bin/ls
supinfo@debian-master:~/ncftp-3.2.6$ dpkg -s coreutils  #查看这个包的详细信息
Package: coreutils
Essential: yes
Status: install ok installed
Priority: required

```



# 磁盘操作 

```sh
supinfo@debian-master:~$ cat /proc/partitions 
major minor  #blocks  name

   8       32    5242880 sdc
   8       16    5242880 sdb  # a,b,c 说明一共有三个物理磁盘
   8        0   20971520 sda
   8        1   19921920 sda1
   8        2          1 sda2
   8        5    1046528 sda5
  11        0    1048575 sr0

# major, minor 都是什么意思??
```



```sh
supinfo@debian-master:~$ sudo fdisk -l

Disk /dev/sdc: 5 GiB, 5368709120 bytes, 10485760 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/sdb: 5 GiB, 5368709120 bytes, 10485760 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/sda: 20 GiB, 21474836480 bytes, 41943040 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0x9f73a5d3

Device     Boot    Start      End  Sectors  Size Id Type
/dev/sda1  *        2048 39845887 39843840   19G 83 Linux  # store linux sys
/dev/sda2       39847934 41940991  2093058 1022M  5 Extended  # 什么意思.
/dev/sda5       39847936 41940991  2093056 1022M 82 Linux swap / Solaris  # virtual cache
# 每一个硬盘下面会有一张表
# 主分区 和 拓展分区 有什么不同
```





```sh
supinfo@debian-master:~$ sudo fdisk /dev/sdb

Welcome to fdisk (util-linux 2.29.2).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.

Device does not contain a recognized partition table.
Created a new DOS disklabel with disk identifier 0x666ac1c9.

Command (m for help): c

DOS Compatibility flag is set (DEPRECATED!)

Command (m for help): n
Partition type
   p   primary (0 primary, 0 extended, 4 free)
   e   extended (container for logical partitions)
Select (default p): p
Partition number (1-4, default 1): 1
First sector (63-10485759, default 63): 
Last sector, +sectors or +size{K,M,G,T,P} (63-10485759, default 10485759): 

Created a new partition 1 of type 'Linux' and of size 5 GiB.

Command (m for help): w
The partition table has been altered.
Calling ioctl() to re-read partition table.
Syncing disks.

```

```sh
supinfo@debian-master:~$ sudo fdisk /dev/sdc

Welcome to fdisk (util-linux 2.29.2).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.

Device does not contain a recognized partition table.
Created a new DOS disklabel with disk identifier 0xd5e96a1f.

Command (m for help): n
Partition type
   p   primary (0 primary, 0 extended, 4 free)
   e   extended (container for logical partitions)
Select (default p): p
Partition number (1-4, default 1): 
First sector (2048-10485759, default 2048): 
Last sector, +sectors or +size{K,M,G,T,P} (2048-10485759, default 10485759): +1G
# 设置一个1G的partition.

Created a new partition 1 of type 'Linux' and of size 1 GiB.

Command (m for help): n
Partition type
   p   primary (1 primary, 0 extended, 3 free)
   e   extended (container for logical partitions)
Select (default p): p
Partition number (2-4, default 2): 2
First sector (2099200-10485759, default 2099200): 
Last sector, +sectors or +size{K,M,G,T,P} (2099200-10485759, default 10485759): +700M

Created a new partition 2 of type 'Linux' and of size 700 MiB.

Command (m for help): n
Partition type
   p   primary (2 primary, 0 extended, 2 free)
   e   extended (container for logical partitions)
Select (default p): e
Partition number (3,4, default 3): 
First sector (3532800-10485759, default 3532800): 
Last sector, +sectors or +size{K,M,G,T,P} (3532800-10485759, default 10485759): +1g

Created a new partition 3 of type 'Extended' and of size 1 GiB.

Command (m for help): p
Disk /dev/sdc: 5 GiB, 5368709120 bytes, 10485760 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0xd5e96a1f

Device     Boot   Start     End Sectors  Size Id Type
/dev/sdc1          2048 2099199 2097152    1G 83 Linux
/dev/sdc2       2099200 3532799 1433600  700M 83 Linux
/dev/sdc3       3532800 5629951 2097152    1G  5 Extended

Command (m for help): w
The partition table has been altered.
Calling ioctl() to re-read partition table.
Syncing disks.

```



```sh
  supinfo@debian-master:~$ sudo fdisk /dev/sdc

Welcome to fdisk (util-linux 2.29.2).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.


Command (m for help): d  # 删除一个partition
Partition number (1-3, default 3): 3

Partition 3 has been deleted.

Command (m for help): F
Unpartitioned space /dev/sdc: 3.3 GiB, 3559915520 bytes, 6952960 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes

  Start      End Sectors  Size
3532800 10485759 6952960  3.3G

Command (m for help): t   # 更改partition类型
Partition number (1,2, default 2): 2
Partition type (type L to list all types): L

 0  Empty           24  NEC DOS         81  Minix / old Lin bf  Solaris        
 1  FAT12           27  Hidden NTFS Win 82  Linux swap / So c1  DRDOS/sec (FAT-
 2  XENIX root      39  Plan 9          83  Linux           c4  DRDOS/sec (FAT-
 3  XENIX usr       3c  PartitionMagic  84  OS/2 hidden or  c6  DRDOS/sec (FAT-
 4  FAT16 <32M      40  Venix 80286     85  Linux extended  c7  Syrinx         
 5  Extended        41  PPC PReP Boot   86  NTFS volume set da  Non-FS data    
 6  FAT16           42  SFS             87  NTFS volume set db  CP/M / CTOS / .
 7  HPFS/NTFS/exFAT 4d  QNX4.x          88  Linux plaintext de  Dell Utility   
 8  AIX             4e  QNX4.x 2nd part 8e  Linux LVM       df  BootIt         
 9  AIX bootable    4f  QNX4.x 3rd part 93  Amoeba          e1  DOS access     
 a  OS/2 Boot Manag 50  OnTrack DM      94  Amoeba BBT      e3  DOS R/O        
 b  W95 FAT32       51  OnTrack DM6 Aux 9f  BSD/OS          e4  SpeedStor      
 c  W95 FAT32 (LBA) 52  CP/M            a0  IBM Thinkpad hi ea  Rufus alignment
 e  W95 FAT16 (LBA) 53  OnTrack DM6 Aux a5  FreeBSD         eb  BeOS fs        
 f  W95 Ext'd (LBA) 54  OnTrackDM6      a6  OpenBSD         ee  GPT            
10  OPUS            55  EZ-Drive        a7  NeXTSTEP        ef  EFI (FAT-12/16/
11  Hidden FAT12    56  Golden Bow      a8  Darwin UFS      f0  Linux/PA-RISC b
12  Compaq diagnost 5c  Priam Edisk     a9  NetBSD          f1  SpeedStor      
14  Hidden FAT16 <3 61  SpeedStor       ab  Darwin boot     f4  SpeedStor      
16  Hidden FAT16    63  GNU HURD or Sys af  HFS / HFS+      f2  DOS secondary  
17  Hidden HPFS/NTF 64  Novell Netware  b7  BSDI fs         fb  VMware VMFS    
18  AST SmartSleep  65  Novell Netware  b8  BSDI swap       fc  VMware VMKCORE 
1b  Hidden W95 FAT3 70  DiskSecure Mult bb  Boot Wizard hid fd  Linux raid auto
1c  Hidden W95 FAT3 75  PC/IX           bc  Acronis FAT32 L fe  LANstep        
1e  Hidden W95 FAT1 80  Old Minix       be  Solaris boot    ff  BBT            
Partition type (type L to list all types): 82  # 如果这片分区以前有文件, 将被完全删除. 

Changed type of partition 'Linux' to 'Linux swap / Solaris'.

Command (m for help): w

The partition table has been altered.
Calling ioctl() to re-read partition table.
Syncing disks.

```





VFS（virtual File System）的作用就是采用标准的Unix系统调用读写位于不同物理介质上的不同文件系统,即为各类文件系统提供了一个统一的操作界面和应用编程接口。VFS是一个可以让open()、read()、write()等系统调用不用关心底层的存储介质和文件系统类型就可以工作的粘合层。



用户空间文件系统（Filesystem in Userspace），是Linux 中用于挂载某些[网络空间](https://baike.baidu.com/item/%E7%BD%91%E7%BB%9C%E7%A9%BA%E9%97%B4/7650101)，如SSH，到本地文件系统的模块，在SourceForge上可以找到相关内容。



##新建filesystem

`mkfs`
```sh
supinfo@debian-master:~$ sudo mkfs.ext4 /dev/sdb1
[sudo] password for supinfo: 
mke2fs 1.43.4 (31-Jan-2017)
Creating filesystem with 1310712 4k blocks and 327680 inodes
Filesystem UUID: 9df4949d-4966-434a-81b5-0d1315e482ab
Superblock backups stored on blocks: 
	32768, 98304, 163840, 229376, 294912, 819200, 884736

Allocating group tables: done                            
Writing inode tables: done                            
Creating journal (16384 blocks): done
Writing superblocks and filesystem accounting information: done 
```



`tune2fs` 调整文件系统参数

```sh
supinfo@debian-master:~$ sudo tune2fs -L STORAGE /dev/sdb1  # 更改partition的lable. 
tune2fs 1.43.4 (31-Jan-2017)
supinfo@debian-master:~$ ls -l /dev/disk/by-label/
total 0
lrwxrwxrwx 1 root root 10 Mar 11 16:48 STORAGE -> ../../sdb1
```



`dumpe2fs` 列出文件系统的信息

```sh
supinfo@debian-master:~$ sudo dumpe2fs -h /dev/sdb1 
```



disk -> apritition -> fs -> mount

## wangluo

**WPA**全名为**Wi-Fi Protected Access**，有**WPA**和**WPA2**两个标准，是一种保护无线[电脑](https://baike.baidu.com/item/%E7%94%B5%E8%84%91)网络（[Wi-Fi](https://baike.baidu.com/item/Wi-Fi)）安全的系统，它是应研究者在前一代的系统[有线等效加密](https://baike.baidu.com/item/%E6%9C%89%E7%BA%BF%E7%AD%89%E6%95%88%E5%8A%A0%E5%AF%86/3975214)（WEP）中找到的几个严重的弱点而产生的。



```
gorkr@gorkr-PC:~$ dig @8.8.8.8 baidu.com +short
220.181.57.216
123.125.115.110
```



## network

更改主机名:

```sh
supinfo@debian-master:~$ hostname
debian-master
supinfo@debian-master:~$ sudo hostname 1LIN-VM
[sudo] password for supinfo: 
supinfo@debian-master:~$ hostname
1LIN-VM
# 没有修改配置文件, reboot后hostname有变回原名.

root@debian-master:/home/supinfo# cat /etc/hostname
debian-master
root@debian-master:/home/supinfo# sudo echo "LIN-VM" > /etc/hostname
root@debian-master:/home/supinfo# cat /etc/hostname
LIN-VM
# reboot以后, 提示符中的主机名也变为LIN-VM.
# 但是域名还没有被其他服务接受

supinfo@LIN-VM:~$ sudo vim /etc/hosts
sudo: unable to resolve host LIN-VM   # 每条命令都会出现这个提示
[sudo] password for supinfo: 
You have new mail in /var/mail/supinfo
supinfo@LIN-VM:~$ 



```



`ifconfig` 和 `ip a` 都能用来查看ip. 推荐使用`ip a` .

```shell
supinfo@LIN-VM:~$ sudo apt-cache search ifconfig  # 查找包含ifconfig文件的包
supinfo@LIN-VM:~$ sudo apt-get install net-tools  # 安装了ifconfig

supinfo@LIN-VM:~$ sudo ifconfig
ens33: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.39.132  netmask 255.255.255.0  broadcast 192.168.39.255
        inet6 fe80::20c:29ff:fed1:48a4  prefixlen 64  scopeid 0x20<link>
        ether 00:0c:29:d1:48:a4  txqueuelen 1000  (Ethernet)
        RX packets 1907  bytes 167076 (163.1 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 1465  bytes 206702 (201.8 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
# inet : ipv4,  inet6 : ipv6. 

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1  (Local Loopback)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```



更改ip

```shell
supinfo@LIN-VM:~$ sudo ifconfig ens33 192.168.7.14
# 改了之后就没网了....
# 因为你虚拟机上, 给虚拟机分配的实际ip并不是这个.
# 所以更改eidt->virtual network editer 下的ip为..7.14
# 同样的, 因为并没有修改配置文件, 所以重启好ip失效果.
```



在服务器开着的情况下  , 增加了三个网卡

```sh
sudo vim /etc/network/interfaces
sudo /etc/init.d/netwoeking restart

1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: ens33: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP group default qlen 1000
    link/ether 00:0c:29:d1:48:a4 brd ff:ff:ff:ff:ff:ff
    inet 192.168.7.14/24 brd 192.168.7.255 scope global ens33
       valid_lft forever preferred_lft forever
    inet6 fe80::20c:29ff:fed1:48a4/64 scope link 
       valid_lft forever preferred_lft forever
3: ens37: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN group default qlen 1000
    link/ether 00:0c:29:d1:48:b8 brd ff:ff:ff:ff:ff:ff
4: ens38: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN group default qlen 1000
    link/ether 00:0c:29:d1:48:c2 brd ff:ff:ff:ff:ff:ff
5: ens39: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN group default qlen 1000
    link/ether 00:0c:29:d1:48:ae brd ff:ff:ff:ff:ff:ff


# 更改配置文件
supinfo@LIN-VM:~$ sudo vim /etc/network/interfaces
# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).
source /etc/network/interfaces.d/*
# The loopback network interface
auto lo
iface lo inet loopback
# The primary network interface
allow-hotplug ens33
iface ens33 inet dhcp

+allow-hotplug ens37
+iface ens37 inet dhcp


# 再开关interface
sudo ifdown ens33 && ifup ens33
```



设置静态ip

```shell
supinfo@LIN-VM:~$ sudo vim /etc/network/interfaces
# This file describes the network interfaces available on your system
# and how to activate them. For more information, see interfaces(5).

source /etc/network/interfaces.d/*

# The loopback network interface
auto lo
iface lo inet loopback

# The primary network interface
+auto ens33
allow-hotplug ens33
iface ens33 inet dhcp

#allow-gotplug ens37
#iface ens37 inet dhcp
+auto ens37
+allow-hotplug ens37
+iface ens37 inet static
+       address 192.168.4.2
+       netmask 255.255.255.0

supinfo@LIN-VM:~$ sudo /etc/init.d/networking restart 
# sudo service networking restart
```



关闭某个interface: `ifdown`, `ifup`

```sh
supinfo@LIN-VM:~$ sudo ifconfig
ens33: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.7.14  netmask 255.255.255.0  broadcast 192.168.7.255
        inet6 fe80::20c:29ff:fed1:48a4  prefixlen 64  scopeid 0x20<link>
        ether 00:0c:29:d1:48:a4  txqueuelen 1000  (Ethernet)
        RX packets 3233  bytes 267064 (260.8 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 2095  bytes 307543 (300.3 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

ens37: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.4.2  netmask 255.255.255.0  broadcast 192.168.4.255
        inet6 fe80::20c:29ff:fed1:48b8  prefixlen 64  scopeid 0x20<link>
        ether 00:0c:29:d1:48:b8  txqueuelen 1000  (Ethernet)
        RX packets 2  bytes 512 (512.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 8  bytes 648 (648.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1  (Local Loopback)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

supinfo@LIN-VM:~$ sudo ifdown ens37
supinfo@LIN-VM:~$ sudo ifconfig
ens33: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.7.14  netmask 255.255.255.0  broadcast 192.168.7.255
        inet6 fe80::20c:29ff:fed1:48a4  prefixlen 64  scopeid 0x20<link>
        ether 00:0c:29:d1:48:a4  txqueuelen 1000  (Ethernet)
        RX packets 3388  bytes 279130 (272.5 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 2199  bytes 319607 (312.1 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1  (Local Loopback)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

```



域名解析配置

```sh
supinfo@LIN-VM:~$ sudo ping baidu.com
ping: baidu.com: Temporary failure in name resolution
supinfo@LIN-VM:~$ sudo vim /etc/resolv.conf 

```



使用`dig`

```sh
supinfo@LIN-VM:~$ sudo apt-get install dnsutils
dig goole.comn 
```



## ssh

ssh 

- https://www.jianshu.com/p/33461b619d53

- https://www.jianshu.com/p/702752294136

SSH(**Secure Shell**)仅仅是一**协议标准**，其具体的实现有很多，既有开源实现的OpenSSH，也有商业实现方案。使用范围最广泛的当然是开源实现OpenSSH。



md 5

- https://www.jianshu.com/p/81c30781d4f7md5 

md5将整个文件当做一个大文本信息，通过不可逆的字符串变换算法，产生一个唯一的MD5信息摘要。文件的md5类似于人的指纹，在世界上是独立无二的.