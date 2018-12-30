# PEP8代码规范

## 代码布局

###缩进和换行

缩进使用4个空格

续行应该与其包裹元素对齐，要么使用圆括号、方括号和花括号内的隐式行连接来垂直对齐；要么使用悬挂式缩进对齐

```python
# 与开始的分隔符对齐
foo = long_function_name(var_one, var_two,
                         var_three, var_four)

# 更多的缩进，更加的清晰
# 悬挂式缩进？第一行不应该有参数
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)
```

只使用空格而不是制表符

###行的最大长度

限制所有行的最大长度为 79 个字符。对一大段长文本（文档字符串或注释），推荐限制每行最多72个字符。

较长代码行折行的首选方法是在圆括号、方括号和花括号内使用Python的隐式续行方式。这种方式要优先使用，优先于反斜杠。

```python
class Rectangle(Blob):

    def __init__(self, width, height,
                 color='black', emphasis=None, highlight=0):
        if (width == 0 and height == 0 and
            color == 'red' and emphasis == 'strong' or
            highlight > 100):
            raise ValueError("sorry, you lose")
        if width == 0 and height == 0 and (color == 'red' or
                                           emphasis is None):
            raise ValueError("I don't think so -- values are %s, %s" %
                             (width, height))
        Blob.__init__(self, width, height,
                      color, emphasis, highlight)
```

### 空行

顶层函数和类之间使用两个空行

类的方法之间使用一个空行

（谨慎地）使用额外的空白行来分隔一组相关的函数。一堆相关的单行代码之间的空白行可以省略

在函数中使用空行来（谨慎地）表示不同的逻辑段落。

### 编码

`-*- coding: utf-8 -*-`

 `coding=utf-8`

### import

导入通常应当使用单独的行

```python
Yes: import os
     import sys
     from subprocess import Popen, PIPE

No:  import sys, os
```

导入总是位于文件的顶部，在模块注释和文档字符串之后，在模块的全局变量与常量之前。

导入应该按照以下的顺序分组：

1. 标准库导入
2. 相关第三方库导入
3. 本地应用程序/库的特定导入

每组导入之间使用空行隔开。

**在导入之后放置任何相关的 `__all__` 说明书。** 查阅`__all__`的有关资料

对所有导入来说，总是使用绝对包路径导入。（移植问题）

从一个包含类的模块中导入类时，常常这么写：

```python
from myclass import MyClass
from foo.bar.yourclass import YourClass
```

## 表达式和语句中的空格

### Pet Peeves

在下列情况下避免多余的空格：

- 紧贴着圆括号、方括号和花括号。

  ```python
  Yes: spam(ham[1], {eggs: 2})
  No:  spam( ham[ 1 ], { eggs: 2 } )
  ```

- 紧贴在逗号，分号或冒号之前：

  ```python
  Yes: if x == 4: print x, y; x, y = y, x
  No:  if x == 4 : print x , y ; x , y = y , x
  ```

- 紧贴在函数调用的参数列表的圆括号的开括号前：

  ```python
  Yes: spam(1)
  No:  spam (1)
  ```

- 紧贴在索引或切片的方括号的开括号前：

  ```python
  Yes: dict['key'] = list[index]
  No:  dict ['key'] = list [index]
  ```

- 在赋值（或其他）语句的运算符周围，不要为了对齐而使用多个空格。

  Yes:

  ```python
  x = 1
  y = 2
  long_variable = 3
  ```

  No:

  ```python
  x             = 1
  y             = 2
  long_variable = 3
  ```



### Other Recommendations

- 总是在这些二元运算符前后加一个空格：赋值（`=`），自增赋值（`+=`，`-=` 等等）， 比较（`==`，`<`，`>`，`!=`，`<>`，`<=`，`>=`，`in`，`not in`，`is`，`is not`)，布尔运算（`and`，`or`，`not`）。

- 在算术运算符前后加空格：

  ```python
  i = i + 1
  submitted += 1
  x = x * 2 - 1
  hypot2 = x * x + y * y
  c = (a + b) * (a - b)
  ```

- 不要在一个**关键字参数**或者一个**缺省参数值**的 `=` 符号前后加一个空格。

  Yes:

  ```python
  def complex(real, imag=0.0):
      return magic(r=real, i=imag)
  ```

- 通常不推荐使用复合语句（一行代码中有多条语句）。

  Yes:

  ```python
  if foo == 'blah':
      do_blah_thing()
  do_one()
  do_two()
  do_three()
  ```

  Rather not:

  ```python
  if foo == 'blah': do_blah_thing()
  do_one(); do_two(); do_three()
  ```

- 通常情况下，一行代码包括一个小的if/for/while块，是可以的。但是多子句绝不可以。同样，需要避免折叠类似的长代码行！

  Rather not:

  ```python
  if foo == 'blah': do_blah_thing()
  for x in lst: total += x
  while t < 10: t = delay()
  ```

  Definitely not:

  ```python
  if foo == 'blah': do_blah_thing()
  else: do_non_blah_thing()

  try: something()
  finally: cleanup()

  do_one(); do_two(); do_three(long, argument,
                               list, like, this)

  if foo == 'blah': one(); two(); three()
  ```



## 注释

不好理解的注释不如没有注释。注释要和代码保持与时俱进！

注释应该是一条完整的句子。如果注释是一个短语或句子，它的第一个字应该大写，除非它是一个小写字母开头的标识符。

块注释通常由一个或多个段落组成， 这些段落由完整的句子构成，每个句子都应该使用句号结尾。

句号结尾的句子后面应该有2个空格。

使用英语写注释。

### 块注释


块注释在一些（或全部）代码之前，并和代码缩进一致。每行注释均以 `#` 开头，然后紧跟一个空格（除非在注释内缩进）。

块注释内的段落使用仅含 `#` 的单行分隔。

### 行内注释

谨慎地使用内嵌注释。

内嵌注释是一种和语句在同一行的注释。内嵌注释至少和语句间隔2个空格。他们开始于一个 `#` 和一个空格。

### DocString

**详情查阅 PEP 257**

- 所有的公告模块，函数，类和方法都需要编写文档字符串。对非公共的方法而言，文档字符串则不是必要的，但是可以使用一个注释来描述这个方法。这个注释必须位于 `def` 行之后。

- [PEP 257](http://python.org/dev/peps/pep-0257) 描述了一个良好的文档字符串的编写约定。注意最重要的是，`"""` 作为多行的文档字符串的结束，应该单独一行，例如：

  ```
  """Return a foobang

  Optional plotz says to frobnicate the bizbaz first.

  """
  ```

- 对单行的文档字符串来说，结尾的 `"""` 在同一行。



## 版本注记

If you have to have Subversion, CVS, or RCS crud in your source file, do it as follows.

如果在代码源文件中掺杂着Subversion，CVS或RCS注记，按照下面的规则书写。

```
__version__ = "$Revision: dc5a21b8bc47 $"
# $Source$
```

These lines should be included after the module's docstring, before any other code, separated by a blank line above and below.

这些行在块注释之后，其他代码之前。前后各有一个空行。

## 命名约定

Python库的命名约定有点乱，目前有一些推荐的标准。

### 命名风格

- `b` (single lowercase letter) （单个小写字母）

- `B` (single uppercase letter) （单个大写字母）

- `lowercase 小写字母`

- `lower_case_with_underscores 使用下划线分隔的小写字母`

- `UPPERCASE 大写字母`

- `UPPER_CASE_WITH_UNDERSCORES 使用下划线分隔的大写字母`

- `CapitalizedWords` （或 CapWords，或 CamelCase -- 这样命名因为其字母有起伏的外观[[4\]](https://www.cnblogs.com/ajianbeyourself/p/4377933.html#id8)）。这有时也被称为 StudlyCaps。

  注意：当首字大写中用到缩写时，所有字符用大写。因此HTTPSeverError比HttpSeverError好。

- `mixedCase`（不同于首字符大写，开始是小写字母！）

- `Capitalized_Words_With_Underscores` (ugly!)（丑陋之极！）

另外，下面用前导和结尾下划线的特殊格式是被认可的（通常和一些示例规范结合）

- `_single_leading_underscore`：（单下划线开始）弱"内部使用"指示器。例如：`from M import *` 不会导入以下划线开始的对象。

- `single_trailing_underscore_`：（单下划线结束）规定使用其来避免与Python关键字冲突，例如：

  ```
  Tkinter.Toplevel(master, class_='ClassName')
  ```

- `__double_leading_underscore`：（双下划线开始）命名一个类的属性时，调用"名字变化"（类FooBar中，`__boo` 变为了 `_FooBar__boo`; 见下文）。

- `__double_leading_and_trailing_underscore__`：（双下划线开始和结束）"magic"对象或属性存活于用户控制的命名空间。 例如`__init__`, `__import__` 或 `__file__`。永远不要起这样的名字；只在文档中使用。

### 命名规范

#### 避免使用

永远不要使用 'l'（小写的L），'O'（大写的O），或者'I'（大写的I）作为单字变量名。

#### 包和模块名称

模块应该用简短的，全小写的名字。如果能增强可读性的话，可以使用下划线。 

Python的包也要用全小写的，短名称，但是不建议用下划线。

#### 类名

毫无例外，类名要用首字母大写的规则。内部类，要加上前导下划线。

#### 异常名

异常也是类，所以这里也用类名规则。但是，你异常名应该用前缀 "Error"（如果你的异常确实是个错误的话）。

#### 全局变量名

被设计为通过`from M import *`导入的模块。应该用`__all__`机制来防止导出全局。 或者使用过去的全局变量前置下划线的规则（这是为了说明这些变量是"模块私有的"）。

#### 函数名

函数名应该用小写，为了增加可读性可以用下划线分隔。

#### 函数和方法参数

始终用`self`作为实例方法的第一个参数。

始终用`cls`作为类方法的第一个参数。

如果函数的参数名和保留字冲突。用结尾下划线比缩写或是滥用的组词更好。因此 `class_` 比 `clss`好。

#### 方法名和实例变量

使用函数命名规则：使用下划线分隔的小写字母会提高可读性。

使用前导双下划线调用Python的名字变化规则来避免与子类中的名字冲突。

如果类Foo有个属性叫做`__a`,那么它不能用 `Foo.__a`读取。 （执着的用户还是可以用`Foo._Foo__a`.读取。）

#### 常量

常量通常在模块级别中定义，用全大写和下划线分隔的字符来编写。

#### 继承设计

总要考虑一个类的方法或实例变量（总体而言：属性）应该是公用的或者非公用的。如果不能确定的话，设计为私有的。 

公有属性，是你希望与这个类无关的客户使用的，并通过你的委托机制来避免由于属性变更导致的向后不兼容。 私有属性，是你不希望被第三方使用的。你不能保证私有属性不会改变甚至被删除。

**待补充**

## 程序设计建议

1. 代码应该用不损害其他Python实现的方式去编写（PyPy, Jython, IronPython, Cython, Psyco 等）

   例如，不要依赖于CPython的高效内置字符连接语句`a += b` or `a = a + b`.这些语句在Jython中运行较慢。在性能敏感的库中，应该用`''.join()`来取代。这样可以保证在不同的实现中，字符链接花费的时间都呈线性。

1. 与诸如None这样的字符比较时，要使用`is` or `is not`，永远不要用等于操作。

   同样地，在测试一个变量或参数默认值为None被设置为其他值时（比如`if x`表示`if x is not None`时），要注意。 这个值应该有一个能在布尔逻辑的上下文中为false的类型（比如容器）。




**待补充**



# foot

摘录自[PEP8中文翻译](https://www.cnblogs.com/ajianbeyourself/p/4377933.html#_label12) 