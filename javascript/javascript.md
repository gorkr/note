# 先导

##语言特点和历史

JavaScript 的核心语法部分相当精简，只包括两个部分：基本的语法构造（比如操作符、控制结构、语句）和标准库（就是一系列具有各种功能的对象比如`Array`、`Date`、`Math`等）。除此之外，各种宿主环境提供额外的 API（即只能在该环境使用的接口），以便 JavaScript 调用。以浏览器为例，它提供的额外 API 可以分成三大类。

- 浏览器控制类：操作浏览器
- DOM 类：操作网页的各种元素
- Web 类：实现互联网的各种功能



进入 Chrome 浏览器的“控制台”，有两种方法。

- 直接进入：按下`Option + Command + J`（Mac）或者`Ctrl + Shift + J`（Windows / Linux）
- 开发者工具进入：开发者工具的快捷键是 F12，或者`Option + Command + I`（Mac）以及`Ctrl + Shift + I`（Windows / Linux），然后选择 Console 面板

进入控制台以后，就可以在提示符后输入代码，然后按`Enter`键，代码就会执行。如果按`Shift + Enter`键，就是代码换行，不会触发执行。建议阅读本教程时，将代码复制到控制台进行实验



2012年，微软发布 TypeScript 语言。该语言被设计成 JavaScript 的超集



## 基本语法

###语句

语句（statement）是为了完成某种任务而进行的操作。

```js
`var a = 1 + 3;  //一行赋值语句。
```

`1 + 3`叫做表达式（expression），指一个为了得到返回值的计算式。表达式不需要分号结尾。一旦在表达式后面添加分号，则 JavaScript 引擎就将表达式视为语句。



分号前面可以没有任何内容，JavaScript 引擎将其视为空语句。

```js
;;;  //3个空语句。
```



### 变量

使用`var`命令声明变量。只是声明变量而没有赋值，则该变量的值是undefined。

```js
var a; 
a // undefined ， 
```



JavaScript 是一种动态类型语言，也就是说，变量的类型没有限制，变量可以随时更改类型。

```js
var a = 1;
a = 'hello';
```



如果使用`var`重新声明一个已经存在的变量，是无效的。

```js
var x = 1;
var x;
x // 1
```



**JavaScript 引擎的工作方式是，先解析代码，获取所有被声明的变量，然后再一行一行地运行。这造成的结果，就是所有的变量的声明语句，都会被提升到代码的头部，这就叫 做变量提升（hoisting）。**



### 注释

由于历史上 JavaScript 可以兼容 HTML 代码的注释，所以`<!--`和`-->`也被视为合法的单行注释。

```
x = 1; <!-- x = 2;
--> x = 3;
```

上面代码中，只有`x = 1`会执行，其他的部分都被注释掉了。

需要注意的是，`-->`只有在行首，才会被当成单行注释，否则会当作正常的运算。



### 区块

JavaScript 使用大括号，将多个相关的语句组合在一起，称为“区块”（block）。

对于`var`命令来说，JavaScript 的区块不构成单独的作用域（scope）。

```js
{
  var a = 1;
}

a // 1
```

上面代码在区块内部，使用`var`命令声明并赋值了变量`a`，然后在区块外部，变量`a`依然有效，区块对于`var`命令不构成单独的作用域，与不使用区块的情况没有任何区别。



### 条件作用域

```js
if (m === 0) {
  // ...
} else if (m === 1) {
  // ...
} else if (m === 2) {
  // ...
} else {
  // ...
}
```



```js
switch (fruit) {
  case "banana":
    // ...
    break;
  case "apple":
    // ...
    break;
  default:
    // ...  如果所有case都不符合，则执行最后的default部分。
}
```



```js
var even = (n % 2 === 0) ? true : false;  //三元运算符
```


### 标签

JavaScript 语言允许，语句的前面有标签（label），相当于定位符，用于跳转到程序的任意位置，标签的格式如下。

```js
label:
  语句
```

```js
top:
  for (var i = 0; i < 3; i++){
    for (var j = 0; j < 3; j++){
      if (i === 1 && j === 1) break top;
      console.log('i=' + i + ', j=' + j);
    }
  }
// i=0, j=0
// i=0, j=1
// i=0, j=2
// i=1, j=0
// 跳出双层循环
```



# 数据类型

## 概述

- `undefined`：表示“未定义”或不存在，即由于目前没有定义，所以此处暂时没有任何值
- `null`：表示空值，即此处的值为空。
- 对象（object）：各种值组成的集合。



对象是最复杂的数据类型，又可以分成三个子类型。

- 狭义的对象（object）
- 数组（array）
- 函数（function）

函数其实是处理数据的方法，JavaScript 把它当成一种数据类型，可以赋值给变量，这为编程带来了很大的灵活性，也为 JavaScript 的“函数式编程”奠定了基础。



JavaScript 有三种方法，可以确定一个值到底是什么类型。

- `typeof`运算符
- `instanceof`运算符
- `Object.prototype.toString`方法

```js
typeof window // "object"
typeof {} // "object"
typeof [] // "object"
```

```js
typeof null // "object"
```



## null,undefined和布尔值

在`if`语句中，`null`和`undefined`都会被自动转为`false`，相等运算符（`==`）甚至直接报告两者相等。

区别是这样的：`null`是一个表示“空”的对象，转为数值时为`0`；`undefined`是一个表示"此处无定义"的原始值，转为数值时为`NaN`。

```js
Number(undefined) // NaN
Number(null) // 0
```



```js
// 变量声明了，但没有赋值
var i;
i // undefined

// 调用函数时，应该提供的参数没有提供，该参数等于 undefined
function f(x) {
  return x;
}
f() // undefined

// 对象没有赋值的属性
var  o = new Object();
o.p // undefined

// 函数没有返回值时，默认返回 undefined
function f() {}
f() // undefined
```



`null`表示空值，即该处的值现在为空。调用函数时，某个参数未设置任何值，这时就可以传入`null`，表示该参数为空。比如，某个函数接受引擎抛出的错误作为参数，如果运行过程中未出错，那么这个参数就会传入`null`，表示未发生错误。



六个值被转为`false`，其他值都视为`true`。

- `undefined`
- `null`
- `false`
- `0`
- `NaN`
- `""`或`''`（空字符串）

注意，空数组（`[]`）和空对象（`{}`）对应的布尔值，都是`true`。



## 数值

JavaScript 内部，**所有数字都是以64位浮点数形式储存，即使整数也是如此**。所以，`1`与`1.0`是相同的，是同一个数。

某些运算只有整数才能完成，此时 JavaScript 会自动把64位浮点数，转成32位整数，然后再进行运算。

绝对值小于2的53次方的整数，即$-2^{53}$到$2^{53}$，都可以精确表示。