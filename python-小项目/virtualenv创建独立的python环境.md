```python
pip install virtualenv # 安装
virtualenv my_env  #在指定目录下创建独立环境
source my_env/bin/activate  #激活独立环境
```
如果，电脑中同时存在python2和python3,则：
```python
$which python3
/dir
$virtualenv my_env -p /dir
```
在命令行输入`deactivate`就可以停止是使用虚拟环境
