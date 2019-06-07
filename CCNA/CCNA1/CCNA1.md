# 探索网络





| 单词            | 释意   | 术语                | 释意     |
| --------------- | ------ | ------------------- | -------- |
| scenario        | 方案   | scalable            | 可拓展的 |
| dish or antenna | 天线   | modular             | 模块化的 |
| geographic      | 地理的 | MAN(Metro Ethernet) | 城域网   |
|                 |        | intermediary        | 中间设备 |
|                 |        | congestion          | 拥堵     |
|                 |        | transfer            | 网络介质 |

##错题:

A converged network unifies different network services, such as streaming video, voice, and data, on a single platform and within a single infrastructure.

内联网

Intranets connect LANs and WANs that should only be accessible by internal employees, whereas an extranet allows organizations to do business directly with other external organizations by allowing them access to part of the internal network.





思科将其称为以人为本的网络。以人为本的网络重点关注 Internet 和网络对人们和企业的影响

- **对等 (P2P) 文件共享** – 对等文件共享使人们可以彼此共享文件，而不必存储并从中央服务器下载。用户安装 P2P 软件即可加入 P2P 网络。P2P 文件共享尚未得到所有人的认可。很多人担心这会违反版权保护资料的相关法律。



### 1.2.1 网络组件

当一台终端设备发起通信时，会使用目的终端设备的地址来指定应该将消息发送到哪里。

- **电缆内的金属线** - 数据将编码为电脉冲
- **玻璃或塑料光纤（光缆）** - 数据将编码为光脉冲
- **无线传输** - 使用电磁波谱中的波长编码数据

![术语](术语.png)

- **网络接口卡** - 即 PC 或其他终端设备上的网卡或 LAN 适配卡，用于提供与网络之间的物理连接。连接 PC 与网络设备的介质，将直接插入网卡（图 2）
- **物理端口** - 网络设备上的接口或插口，介质通过它连接到终端设备或其他网络设备。
- **接口** - 网络设备上连接到独立网络的专用端口。由于路由器用于互连不同的网络，路由器上的端口称为网络接口。



- **物理拓扑图** - 识别中间设备和电缆安装的物理位置。（图 1）
- **逻辑拓扑图** - 识别设备、端口和编址方案。（图 2）

### 1.2.2 LAN和WAN

- **存储区域网络 (SAN)** - 专门用于支持文件服务器和提供数据存储、检索和复制功能的网络基础设施。

- WAN 通常提供 LAN 之间的较慢链路。

为了维护 Internet 协议和进程的结构和标准化，人们建立了许多组织。这些组织包括互联网工程任务组 (IETF)、互联网名称与数字地址分配机构 (ICANN) 和互联网架构委员会 (IAB)，以及许多其他组织。

**注意**：术语“internet”（使用小写“i”）用于描述多个网络互连。当指互连计算机网络组成的全球系统或万维网时，则使用术语 Internet（使用大写“I”）。



家庭用户、远程工作人员和小型办公室通常需要连接到**Internet 服务提供商 (ISP) **才能访问 Internet。不同 ISP 和地理位置的连接选项各不相同。但是，常见的选择包括宽带电缆、**宽带数字用户线路 (DSL)**、无线 WAN 和移动服务。

- **DSL** - 数字用户线路提供高带宽、始终联网和 Internet 连接。DSL 通过电话线路运行。通常小型办公室和家庭办公室用户会选择使用非对称 DSL (ADSL)，这种方式的特点是下载速度高于上传速度。
- **同轴电缆** - 通常由有线电视服务提供商提供，Internet 数据信号在输送有线电视信号的同一电缆上进行传输。它能提供高带宽、始终联网和 Internet 连接。

企业的常见连接选项：

- **专用租用线路** - 租用线路实际上是服务提供商网络内连接地理位置分散的办公室的保留电路，提供个人语音和/或数据网络。电路通常按月或按年租用。可能会非常昂贵。

- **以太网 WAN** - 以太网 WAN 将 LAN 访问技术扩展到 WAN 中。以太网是一种 LAN 技术，您将在后面的章节中学习。现在以太网的优势将可以扩展到 WAN 中。

- **DSL** - 企业 DSL 提供各种格式。一种常见的选择是对称数字用户线路 (SDSL)，它类似于 DSL 的普通用户版本，但是提供相同的上传和下载速度。

## 1.3 作为融合的网络

现在，独立的数据、电话和视频网络不断融合。与专用网络不同，融合网络能够通过相同的网络基础设施，在许多不同类型的设备之间传输数据、语音和视频。

术语**“网络架构”**是指支持基础设施的技术以及通过该网络传输数据的编程服务及规则或协议底层架构必须解决以下四个基本特性才能满足用户的期望

- 容错能力(fault tolerance)

  网络依赖于消息的源地址与目的地址之间的多条路径。如果一条路径失败，消息可以立即通过不同的链路发送。有多条路径到达目的地被称为冗余。

  可靠网络提供冗余的一种方法就是实施分组交换网络。分组交换将流量分割成通过共享网络发送的数据包。单个消息，例如一份电子邮件或一段视频流，会分割成多个消息块，称为数据包。每个数据包拥有所需的消息源和目的地的编址信息。网络内的路由器基于当时的网络状况交换数据包。这意味着，单个消息中的所有数据包，可能会采用完全不同的路径到达目的地。

  对于通常用于语音通信的电路交换网络而言，情况并非如此。电路交换网络是指在用户通信之前在源和目的地之间建立专用电路的网络。如果呼叫意外终止，则用户必须发起新连接。

- 可扩展性

  可以增加的用户和整个网络连接到internet而不降低现有用户的性能。模块化是实现方法。

- 服务质量 (QoS)

  指一个网络能够利用各种基础技术，为指定的网络通信提供更好的服务能力, 是网络的一种安全机制， 是用来解决网络延迟和阻塞等问题的一种技术

  ![Qos](Qos.png)

- 安全

  - **机密性** - 数据机密性意味着只有预定和授权收件人可以访问并读取数据。

  - **完整性** - 数据完整性表示保证信息在从源地址到目的地址的传输过程中不会被更改。

  - **可用性** - 数据可用性表示保证授权用户及时可靠地访问数据服

## 1.4网络趋势

BYOD 是指最终用户可以使用个人工具通过企业或园区网络访问信息和相互通信。

Wireless Internet Service Providers (WISPs) are typically found in rural areas where DSL or cable access is not available. A dish or antenna on the property of the subscriber connects wirelessly to a WISP transmitter, eliminating the need for physical cabling outside the building. 

**云计算**是改变我们访问和存储数据的方法的另一个全球趋势。云计算使我们可以在 Internet 上存储个人文件，甚至可以在服务器上备份整个硬盘驱动器。使用云可以访问文字处理和图片编辑等应用程序。

对企业而言，云计算扩大了 IT 部门的功能，无需投资新基础设施、培训新员工或获取新软件许可。这些服务按需提供，并以经济的方式提供给世界任何地方的所有设备，而且不会影响安全。

没有数据中心，就无法实现云计算。数据中心是用于容纳计算机系统和相关组件的设施。数据中心可能会占用大楼的一个房间、一个或多个楼层，甚至整个大楼。数据中心的构建和维护成本通常很高。正因如此，只有大型企业会使用专门构建的数据中心来容纳数据并为用户提供服务。对于没有能力维护自己的专用数据中心的小型企业，可以利用云中其他大型数据中心企业的服务器和存储服务来降低总拥有成本。

**- 电力线网**

电力线网络是家庭网络的一种新兴趋势，它使用现有的电线连接设备，如图所示。“无需新电线”的概念是指只要有电源插座就能连接网络。这样可以节省安装数据线的成本，而且不会增加电费成本。通过使用供电的同一配线，电力线网络通过按一定频率发送数据来发送信息。

使用标准电源适配器，只要有电源插座，设备就可以连接到 LAN。当无线接入点无法使用或无法到达家里的所有设备时，电力线网络特别有用。电力线网络不会取代数据网络中的专用布线。但是，当数据网络电缆或无线通信不可行时，电力线网络可以备用。

- **零日攻击（也称零小时攻击）** - 在出现漏洞的第一天发起的攻击
- **拒绝服务攻击** - 意图使网络设备上的应用和进程减缓或崩溃的攻击

- **访问控制列表 (ACL)** – 用于进一步过滤访问和流量转发。

- **入侵防御系统 (IPS)** – 用于识别快速扩散的威胁，例如零日攻击或零小时攻击。

- **虚拟专用网络 (VPN)** – 用于为远程员工提供安全访问。

**- 网络架构**

> 网络架构是指为了支持必要技术和应用而互相集成的设备、连接和产品。精心设计的网络技术架构有助于确保跨任意网络组合连接任意设备。在确保连接的同时，它还通过集成网络安全和管理来增加成本效益，并改进业务流程。所有网络架构的基础以及 Internet 自身的基础，就是路由器和交换机。路由器和交换机能够传输数据、语音和视频通信，而且提供无线访问和保证安全性。



#配置网络操作系统


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

```shell
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

### IOS命令

![IOS命令约定](IOS命令约定.png)

上下文帮助 -- **在任何时候输入`?`**

命令和关键字可缩写为可唯一确定该命令或关键字的最短字符数。例如，**configure** 命令可缩写为 **conf**，因为 **configure** 是唯一一个以 **conf** 开头的命令。不能缩写为 **con**，因为以 **con** 开头的命令不止一个。关键字也可缩写。
![热键](H:\note had gited\CCNA\CCNA1\热键.png)



## 2.2基础配置

**- 主机名**

在配置网络设备时，第一步是配置唯一的设备名称或主机名。主机名显示在 CLI 提示符中，可用于设备之间的各种身份验证过程，并且会用于拓扑图。IOS 设备中所用的主机名会保留字母的大小写状态。

```bash
Router#configure terminal 
Enter configuration commands, one per line.  End with CNTL/Z.
Router(config)#hostname SW-Floor-1
SW-Floor-1(config)#no hos
SW-Floor-1(config)#no hostname   // 删除全局配置
Router(config)#
```

**- 密码设置**

Cisco IOS 可配置为使用分层模式密码允许对网络设备拥有不同的访问权限。也可对telnet设置密码。

要保护特权 EXEC 访问，请使用 **enable secret** *password* 全局配置命令。

入线路控制台配置模式。0 用于代表第一个（而且在大多数情况下是唯一的一个）控制台接口。接下来，使用 **password** *password* 命令指定用户 EXEC 模式密码。

请使用 **line vty 0 15** 全局配置命令进入线路 VTY 模式，如图 3 所示。许多思科交换机支持第 0 到 15 的 16 条 VTY 线路。接下来，使用 **password** *password* 命令指定 VTY 密码。最后，使用 **login** 命令启用 VTY 访问。

```bash
Switch>enable
Switch#config termi
Enter configuration commands, one per line.  End with CNTL/Z.
Switch(config)#enable secret class  // 这里用enable secret
Switch(config)#exit

Switch(config)#line console 0
Switch(config-line)#password cisco
Switch(config-line)#login   // 使用login启用密码访问

Switch(config)#line vty 0 15
Switch(config-line)#password cisco
Switch(config-line)#login
```



要加密密码，请使用 `**service password-encryption**` 全局配置命令。该命令对所有未加密的密码进行弱加密。这种加密仅适用于配置文件中的密码，而不适用于通过网络发送的密码。此命令的用途在于防止未经授权的人员查看配置文件中的密码。

```bash
输入命令以加密明文密码。
Switch(config)# service password-encryption
退出全局配置模式并查看运行的配置。
Switch(config)# exit
Switch# show running-config
!
<省略部分输出>
!
line con 0
 password 7 094F471A1A0A 
 login
!
line vty 0 4
 password 7 03095A0F034F38435B49150A1819
 login
!
!
end

Switch#
您已成功加密明文密码。
```



**- 标语信息**（MOTD)标语 

要在网络设备上创建当日消息标语，请使用`banner motd #the message of the day#` 全局配置命令。命令语法中的“#”称为定界符。它会在消息前后输入。定界符可以是未出现在消息中的任意字符。因此，经常使用“#”之类的字符。命令执行完毕后，系统将向之后访问设备的所有用户显示该标语，直到该标语被删除为止。

```bash
Router(config)#banner motd #test#
Router(config)#exit
```



**- 保存配置文件**

有两种系统文件用于存储设备配置：

- **启动配置** - 该文件存储在非易失性随机访问存储器 (NVRAM) 中，包含设备在启动或重启时将会使用的所有命令。设备断电后，NVRAM 中的内容不会丢失。

- **运行配置** - 该文件存储在随机访问存储器 (RAM) 中，反映当前配置。修改运行配置会立即影响思科设备的运行。RAM 是易失性存储器。如果设备断电或重新启动，则它会丢失所有内容。

如图所示，使用 **show running-config** 特权 EXEC 模式命令查看运行配置文件。要查看启动配置文件，请使用 **show startup-config** 特权 EXEC 命令。

如果设备断电或重新启动，所有未保存的配置更改都会丢失。要将对运行配置所作的更改保存到启动配置文件中，请使用 **copy running-config startup-config** 特权 EXEC 模式命令。

**- 更改运行配置**

以将设备恢复到之前的配置，或者使用 **reload** 特权 EXEC 模式命令重新加载设备，以恢复启动配置。使用 **reload 命令删除**（其实就是强制关机）未保存的运行配置的缺点是，在一段很短的时间内设备将会离线，导致网络中断。

使用 **erase startup-config** 特权 EXEC 模式命令可删除启动配置。在发出此命令后，交换机将提示您确认。按 **Enter** 键接受。重新加载时，交换机将会加载设备出厂默认的启动配置。

`copy startup-config running-config`

```bash
dir nvrom:
```



**- 将配置存到文本文件**

![putty](putty.png)

- 在终端软件（比如 PuTTY 或 Tera Term）中启用日志记录，并指定名称和文件位置以保存日志文件。图中显示**所有会话输出**都将捕获到指定文件中（即 MySwitchLogs）

- 在特权 EXEC 提示符下执行 **show running-config** 或 **show startup-config** 命令。终端窗口中显示的文本将保存到所选的文件中。

## 2.3地址方案

对于 IPv4 地址，子网掩码也是必要设置。IPv4 子网掩码是将地址的网络部分与主机部分区分开来的 32 位值。子网掩码，与 IPv4 地址相结合，可用于确定设备属于哪个特定子网。

IIP 地址可以分配给设备的物理端口和虚拟接口。虚拟接口表示设备没有关联任何物理硬件。

**- 接口和端口**

internet 上的每条链路不仅需要采用特定的网络介质，而且需要采用特定的网络技术。例如，以太网是当今最常用的局域网 (LAN) 技术。在使用电缆物理连接到网络的最终用户设备、交换设备和其他网络设备上，均可找到以太网端口。

Cisco IOS 第 2 层交换机有物理端口，可用于连接设备。这些端口不支持第 3 层 IP 地址。因此，交换机有一个或多个交换机虚拟接口 (SVI)。这些是虚拟接口，是因为设备上没有任何物理硬件与之关联。软件中会创建 SVI。

借助虚拟接口，即可使用 IPv4 通过网络远程管理交换机。每台交换机的默认配置中都“现成”带有一个 SVI。默认 SVI 是接口 VLAN1。

**注意**：2 层交换机不需要 IP 地址。分配给 SVI 的 IP 地址用于远程访问交换机。2层交换机无需使用 IP 地址来执行其操作。

**- 交换机虚拟接口配置**

要远程访问交换机，SVI 上必须配置 IP 地址和子网掩码。要在交换机上配置 SVI，请使用 **interface vlan 1** 全局配置命令。Vlan 1 并不是一个实际物理接口，而是一个虚拟接口。然后使用 **ip address** *ip-address subnet-mask* 接口配置命令分配 IPv4 地址。最后，使用 **no shutdown** 接口配置命令启用虚拟接口。

```bash
enable
configure terminal
interface vlan 1
ip address 192.168.1.10 255.255.255.0
no shutdown  // 默认情况下端口关闭
exit 
show run
show ip interface bried
```

默认情况下，交换机上的所有交换机端口都分配给 VLAN 1。因此 Interface VLAN 1（一个虚拟接口）可由所有开启的交换机端口访问。

**`show ip interface brief`** 命令的视频演示。此命令适用于检验交换机接口的状况。