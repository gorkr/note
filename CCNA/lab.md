# 2.2.1.3 Configuring SSH

## Part1 : Secure Passwords

1. telnet to switch.

    在pc1 `command prompt` 上输入：
        telnet 10.10.10.2
    10.10.10.2 是switch的ip.

    输入密码后实现通过telnent连接switch

2. 保存配置 以备恢复

    不会 是 copy running-config startup-config?????

3. 查看现在的配置信息。 加密密码

        sh ru
        config t
        service password-encryption

4. 验证密码已经加密

## Part2: Encrypt Communications

1.
