# 探索网络

思科将其称为以人为本的网络。以人为本的网络重点关注 Internet 和网络对人们和企业的影响

- **对等 (P2P) 文件共享** – 对等文件共享使人们可以彼此共享文件，而不必存储并从中央服务器下载。用户安装 P2P 软件即可加入 P2P 网络。P2P 文件共享尚未得到所有人的认可。很多人担心这会违反版权保护资料的相关法律。

 

计算机的交换机、路由器、接入点和防火墙等网络设备。这些网络设备使用的操作系统称为网络操作系统。

**Cisco Internetwork Operating System (IOS) **是思科网络设备使用的网络操作系统集合的通用术语。

操作系统中直接与计算机硬件交互的部分称为*内核*。与应用程序和用户连接的部分则称为*外壳*。



####访问方法

- **控制台** – 这是一种物理管理端口，可通过该端口对思科设备进行带外访问。带外访问是指通过仅用于设备维护的专用管理通道进行访问。

某些设备，比如路由器，还可以支持传统辅助端口，这种辅助端口可用于通过调制解调器远程建立 CLI 会话。类似于控制台连接，**AUX 端口也是带外连接**，且不需要配置或提供网络服务。

传输层协议使用带外数据(out-of-band,OOB)来发送一些重要的数据,如果通信一方有重要的数据需要通知对方时,协议能够将这些数据快速地发送到对方.为了发送这些数据,协议一般不使用与普通数据相同的通道,而是使用另外的通道.



用pc的`RS232`端口了解交换机的`console`口打开交换机cli。



####IOS命令行简介

![命令模式](/home/gorkr/Documents/note/CCNA/CCNA1/命令模式.png)

要配置设备，用户必须进入**全局配置模式**。

在全局配置模式下，对 CLI 配置所做的更改将影响整个设备的运行。全局配置模式由在设备名称之后加 (config)# 结尾的提示符标识，比如 **Switch(config)#**。

- **线路配置模式 -** 用于配置控制台、SSH、Telnet 或 AUX 访问。

- **接口配置模式 -** 用于配置交换机端口或路由器网络接口。

默认情况下，每个提示符都以设备名称开头。命令提示符中设备名称后的部分用于表明状态。例如，线路配置模式的默认提示符为 **Switch(config-line)#**，而接口配置模式的默认提示符为 **Switch(config-if)#**。

```bash
Switch>enable                                   //普通的用户执行模式
Switch#configure terminal                       //进入特权模式

Switch(config)#interface vlan 1                 //全局配置模式
Switch(config-if)#                              //子配置模式：接口配置模式
```

#### IOS模式之间的切换

要从用户 EXEC 模式切换到特权 EXEC 模式，请使用 **`enable`** 命令。使用 **`disable`** 特权 EXEC 模式命令返回用户 EXEC 模式。**注意**：特权 EXEC 模式有时称为*使能模式*

要进出全局配置模式，请使用 **`configure terminal`** 特权 EXEC 模式命令。要返回特权 EXEC 模式，请输入 **`exit`**全局配置模式命令。

```bash
//入线路子配置模式
Switch(config)# line console 0
Switch(config-line)#

Switch(config-line)# exit
Switch(config)#

Switch(config-line)# end         或 Ctrl+z
Switch#

//还可以直接从一个子配置模式切换到另一个子配置模式。
Switch(config-line)# interface FastEthernet 0/1
Switch(config-if)#
```

