# CCNA

原理是核心

## OSI七层模型

物理层，数据链路层，网络层，传输层，会话层，表示层，应用层。

目的是标准化网络。

##TCP/IP模型

链路层，网络层，运输层，应用层

## 物理层

网卡(NIC)，网线，光纤，无线传输（光电信号）

网线： 网线线序 T568A\T6568B 自适应

光纤：利用了光的全反射 单播（10km） 多播（300m）

无线：802.11a/b/g/n/ac/ax 传输速率不同  WIFI-6 = ax

## 数据链路层

交换机，MAC地址表——MAC地址与接口的对应关系

- `Vlan` 
- `trunk` 
- `vtp` 自学习vlan
- `dtp` 动态生成trunk
- `stp`  生成树，无环拓扑

## 网络层

IP IP地址计算，子网划分VLSM(可变长子网掩码)，CIDR(无类间路由)

### 路由协议：

动态路由协议

  - 距离矢量： RIP EIGRP
  - 链路状态： OSPF IS-IS  (BGP)

静态路由协议

## 传输层

TCP UDP

端口 : telnet-23 dns-53 http-80 https-443

## 应用层

telnet http smtp

## 特性

ACL NAT DHCP







### 1.2.1 网络组件

当一台终端设备发起通信时，会使用目的终端设备的地址来指定应该将消息发送到哪里。

- **电缆内的金属线** - 数据将编码为电脉冲

- **玻璃或塑料光纤（光缆）** - 数据将编码为光脉冲

- **无线传输** - 使用电磁波谱中的波长编码数据

![术语](H:\note had gited\CCNA\术语.png)

- **网络接口卡** - 即 PC 或其他终端设备上的网卡或 LAN 适配卡，用于提供与网络之间的物理连接。连接 PC 与网络设备的介质，将直接插入网卡（图 2）

- **物理端口** - 网络设备上的接口或插口，介质通过它连接到终端设备或其他网络设备。

- **接口** - 网络设备上连接到独立网络的专用端口。由于路由器用于互连不同的网络，路由器上的端口称为网络接口。



- **物理拓扑图** - 识别中间设备和电缆安装的物理位置。（图 1）

- **逻辑拓扑图** - 识别设备、端口和编址方案。（图 2）