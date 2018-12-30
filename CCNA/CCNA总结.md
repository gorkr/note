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