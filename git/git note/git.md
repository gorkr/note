# git



~~`git add file` 是指， 开始追踪这个文件。也就是说已经用过这个命令的文件，不必再用。~~

`git add` ， 开始追踪这个文件 和  把修改后的文件 添加到 暂存中！

`git tag` 在本地打了标签，但并没有上传到远程仓库。

转载： <http://blog.csdn.net/hustpzb/article/details/8056518>

用git tag来给工程打上标签，但是这个命令只是在本地仓库打标签而已，

为了能把标签同步到远程服务器，我们可以这样做：

默认情况下，git push并不会把tag标签传送到远端服务器上，只有通过显式命令才能分享标签到远端仓库。
1.push单个tag，命令格式为：git push origin [tagname]
例如：
git push origin v1.0 #将本地v1.0的tag推送到远端服务器
2.push所有tag，命令格式为：git push [origin] --tags
例如：
git push --tags
或
git push origin --tags

以上命令经检验通过，如果不起作用，请在Git控制台上确认你的账号是否有权限推送Tag。



## git 分支

```
gorkr@gorkr-PC:~/Documents/learn-code$ git branch
* master
gorkr@gorkr-PC:~/Documents/learn-code$ git status
位于分支 master
您的分支与上游分支 'origin/master' 一致。

无文件要提交，干净的工作区

gorkr@gorkr-PC:~/Documents/learn-code$ git remote show origin 
* 远程 origin
  获取地址：https://github.com/gorkr/learn-code.git
  推送地址：https://github.com/gorkr/learn-code.git
  HEAD 分支：master
  远程分支：
    master 已跟踪
  为 'git pull' 配置的本地分支：
    master 与远程 master 合并
  为 'git push' 配置的本地引用：
    master 推送至 master (最新)

gorkr@gorkr-PC:~/Documents/learn-code$ git branch deveploment
gorkr@gorkr-PC:~/Documents/learn-code$ git status
位于分支 master
您的分支与上游分支 'origin/master' 一致。

无文件要提交，干净的工作区
gorkr@gorkr-PC:~/Documents/learn-code$ git checkout deveploment 
切换到分支 'deveploment'
gorkr@gorkr-PC:~/Documents/learn-code$ git status
位于分支 deveploment
无文件要提交，干净的工作区
gorkr@gorkr-PC:~/Documents/learn-code$ echo "a new branch" branch.md
a new branch branch.md
gorkr@gorkr-PC:~/Documents/learn-code$ cat .git/HEAD 
ref: refs/heads/deveploment

gorkr@gorkr-PC:~/Documents/learn-code$ ls
board.html        cocos      flupy    py-base-code           python练习册
c++               C++vsProj  java     py-spider              reaction.py
c-data-structure  django     node_js  python-data-structure  离散数学
gorkr@gorkr-PC:~/Documents/learn-code$ git status
位于分支 deveploment
无文件要提交，干净的工作区
gorkr@gorkr-PC:~/Documents/learn-code$ fit diff
bash: fit: 未找到命令
gorkr@gorkr-PC:~/Documents/learn-code$ git diff
gorkr@gorkr-PC:~/Documents/learn-code$ echo "a new branch" >> branch.md
gorkr@gorkr-PC:~/Documents/learn-code$ git status
位于分支 deveploment
未跟踪的文件:
  （使用 "git add <文件>..." 以包含要提交的内容）

	branch.md

提交为空，但是存在尚未跟踪的文件（使用 "git add" 建立跟踪）
gorkr@gorkr-PC:~/Documents/learn-code$ git commit -a -m "learn new branch"
位于分支 deveploment
未跟踪的文件:
	branch.md

提交为空，但是存在尚未跟踪的文件
gorkr@gorkr-PC:~/Documents/learn-code$ vim branch.md 
gorkr@gorkr-PC:~/Documents/learn-code$ git status
位于分支 deveploment
未跟踪的文件:
  （使用 "git add <文件>..." 以包含要提交的内容）

	branch.md

提交为空，但是存在尚未跟踪的文件（使用 "git add" 建立跟踪）
gorkr@gorkr-PC:~/Documents/learn-code$ git checkout master
切换到分支 'master'
您的分支与上游分支 'origin/master' 一致。
gorkr@gorkr-PC:~/Documents/learn-code$ status
bash: status: 未找到命令
gorkr@gorkr-PC:~/Documents/learn-code$ sit status
bash: sit: 未找到命令
gorkr@gorkr-PC:~/Documents/learn-code$ git status
位于分支 master
您的分支与上游分支 'origin/master' 一致。

未跟踪的文件:
  （使用 "git add <文件>..." 以包含要提交的内容）

	branch.md

提交为空，但是存在尚未跟踪的文件（使用 "git add" 建立跟踪）
gorkr@gorkr-PC:~/Documents/learn-code$ git diff
gorkr@gorkr-PC:~/Documents/learn-code$ ls
board.html  c-data-structure  django  node_js       python-data-structure  离散数学
branch.md   cocos             flupy   py-base-code  python练习册
c++         C++vsProj         java    py-spider     reaction.py

```

`git commit -m -a` 



```
8cf36b6 (HEAD -> master, tag: v0.1, origin/master, origin/HEAD) user `git commit` with vim
d176fe1 first lab
7208313 finish joseph
56e49cb still have a bug
......

gorkr@gorkr-PC:~/Documents/learn-code$ git merge deveploment 
更新 8cf36b6..da82a12
Fast-forward
 branch.md | 6 ++++++
 1 file changed, 6 insertions(+)
 create mode 100644 branch.md


```



merge冲突

```
gorkr@gorkr-PC:~/Documents/learn-code$ git branch
* deveploment
  master
gorkr@gorkr-PC:~/Documents/learn-code$ vim branch.md 
gorkr@gorkr-PC:~/Documents/learn-code$ git add.
git：'add.' 不是一个 git 命令。参见 'git --help'。

最相似的命令是
	add
gorkr@gorkr-PC:~/Documents/learn-code$ git add .
gorkr@gorkr-PC:~/Documents/learn-code$ git commit -m "one thing for confix"
[deveploment 9f2eb63] one thing for confix
 1 file changed, 1 insertion(+), 1 deletion(-)
gorkr@gorkr-PC:~/Documents/learn-code$ git checkout master 
切换到分支 'master'
您的分支与上游分支 'origin/master' 一致。
gorkr@gorkr-PC:~/Documents/learn-code$ vim branch.md 
gorkr@gorkr-PC:~/Documents/learn-code$ git add .
gorkr@gorkr-PC:~/Documents/learn-code$ git commit -m" anther thing for confix"
[master 1002dd1]  anther thing for confix
 1 file changed, 1 insertion(+), 1 deletion(-)
gorkr@gorkr-PC:~/Documents/learn-code$ git merge deveploment 
自动合并 branch.md
冲突（内容）：合并冲突于 branch.md
自动合并失败，修正冲突然后提交修正的结果。
gorkr@gorkr-PC:~/Documents/learn-code$ cat branch.md 
a new branch

a
b
c
<<<<<<< HEAD
another thing
=======
one thing
>>>>>>> deveploment
gorkr@gorkr-PC:~/Documents/learn-code$ vim branch.md 
gorkr@gorkr-PC:~/Documents/learn-code$ cat branch.md 
a new branch

a
b
c
<<<<<<< HEAD
another thing
gorkr@gorkr-PC:~/Documents/learn-code$ git merge deveploment 
error: 无法合并，因为您有未合并的文件。
提示：请在工作区改正文件，然后酌情使用 'git add/rm <文件>' 命令标记
提示：解决方案并提交。
fatal: 因为存在未解决的冲突而退出。
gorkr@gorkr-PC:~/Documents/learn-code$ vim branch.md 
gorkr@gorkr-PC:~/Documents/learn-code$ cat branch.md 
a new branch

a
b
c
another thing
gorkr@gorkr-PC:~/Documents/learn-code$ git merge deveploment 
error: 无法合并，因为您有未合并的文件。
提示：请在工作区改正文件，然后酌情使用 'git add/rm <文件>' 命令标记
提示：解决方案并提交。
fatal: 因为存在未解决的冲突而退出。
gorkr@gorkr-PC:~/Documents/learn-code$ git add .
gorkr@gorkr-PC:~/Documents/learn-code$ git commit -m "keep the text in master"
[master 48a41de] keep the text in master
gorkr@gorkr-PC:~/Documents/learn-code$ git merge deveploment 
已经是最新的。
gorkr@gorkr-PC:~/Documents/learn-code$ cat branch.md 
a new branch

a
b
c
another thing
gorkr@gorkr-PC:~/Documents/learn-code$ git checkout deveploment 
切换到分支 'deveploment'
gorkr@gorkr-PC:~/Documents/learn-code$ cat branch.md 
a new branch

a
b
c
one thing

```



将本地分支推送到远程

```
gorkr@gorkr-PC:~/Documents/learn-code$ git push origin deveploment 
Username for 'https://github.com': gorkr
Password for 'https://gorkr@github.com': 
对象计数中: 3, 完成.
Delta compression using up to 8 threads.
压缩对象中: 100% (2/2), 完成.
写入对象中: 100% (3/3), 288 bytes | 288.00 KiB/s, 完成.
Total 3 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'deveploment' on GitHub by visiting:
remote:      https://github.com/gorkr/learn-code/pull/new/deveploment
remote: 
To https://github.com/gorkr/learn-code.git
 * [new branch]      deveploment -> deveploment

```

删除本地分支

```
gorkr@gorkr-PC:~/Documents/learn-code$ git branch -d deveploment 
已删除分支 deveploment（曾为 9f2eb63）。
gorkr@gorkr-PC:~/Documents/learn-code$ git push
Username for 'https://github.com': gorkr
Password for 'https://gorkr@github.com': 
对象计数中: 4, 完成.
Delta compression using up to 8 threads.
压缩对象中: 100% (3/3), 完成.
写入对象中: 100% (4/4), 474 bytes | 474.00 KiB/s, 完成.
Total 4 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/gorkr/learn-code.git
   da82a12..48a41de  master -> master
gorkr@gorkr-PC:~/Documents/learn-code$ git branch

```



删除远程分支

```
gorkr@gorkr-PC:~/Documents/learn-code$ git branch -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/deveploment
  remotes/origin/master

gorkr@gorkr-PC:~/Documents/learn-code$ git log --oneline --decorate --graph --all
*   48a41de (HEAD -> master, origin/master, origin/HEAD) keep the text in master
|\  
| * 9f2eb63 (origin/deveploment, deveploment) one thing for confix
* | 1002dd1  anther thing for confix
|/  
* da82a12 add a,b,c
* 8cf36b6 (tag: v0.1) user `git commit` with vim
* d176fe1 first lab
* 7208313 finish joseph
* 56e49cb still have a bug

gorkr@gorkr-PC:~/Documents/learn-code$ git push origin --delete deveploment 
Username for 'https://github.com': gorkr
Password for 'https://gorkr@github.com': 
To https://github.com/gorkr/learn-code.git
 - [deleted]         deveploment
gorkr@gorkr-PC:~/Documents/learn-code$ git branch -a
  deveploment
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/master
gorkr@gorkr-PC:~/Documents/learn-code$ git branch -d deveploment 
已删除分支 deveploment（曾为 9f2eb63）。

```



# github

https://lab.github.com

:fu:

:joy:



# gitlab

<https://www.jianshu.com/p/a9bb06a48b25>



`git ls-files`



已经追踪的文件写入gitignore 将不生效



```
gorkr@gorkr-PC:~/Documents/learn-code$ git push
fatal: 当前分支 master 没有对应的上游分支。
为推送当前分支并建立与远程上游的跟踪，使用

    git push --set-upstream origin master

gorkr@gorkr-PC:~/Documents/learn-code$ git push --set-upstream origin master

```



