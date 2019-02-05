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
var a = 1 + 3;  //一行赋值语句。
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

绝对值小于2的53次方的整数，即$-2^{53}$到$2^{53}$，都可以精确表示。简单来说就是，JavaScript 对15位的十进制数都可以精确处理。

一个数大于等于2的1024次方，那么就会发生“正向溢出”，即 JavaScript 无法表示这么大的数，这时就会返回`Infinity`。如果一个数小于等于2的-1075次方（指数部分最小值-1023，再加上小数部分的52位），那么就会发生为“负向溢出”，即 JavaScript 无法表示这么小的数，这时会直接返回0。



`+0`或`-0`当作分母，返回的值是不相等的。

```js
(1 / +0) === (1 / -0) // false
```

上面的代码之所以出现这样结果，是因为除以正零得到`+Infinity`，除以负零得到`-Infinity`。

除了Infinity、-Infinity、NaN和undefined这几个值会返回false，isFinite对于其他的数值都会返回true。

`NaN`是 JavaScript 的特殊值，表示“非数字”（Not a Number），主要出现在将字符串解析成数字出错的场合。

```js
0 / 0 // NaN
1 / 0 // Infinity
```

`Infinity`的四则运算，符合无穷的数学计算规则

除了Infinity、-Infinity、NaN和undefined这几个值会返回false，isFinite对于其他的数值都会返回true。

`praseInt()`字符串转为整数的时候，是一个个字符依次转换，如果遇到不能转为数字的字符，就不再进行下去，返回已经转好的部分。

`isFinite`方法返回一个布尔值，表示某个值是否为正常的数值。除了`Infinity`、`-Infinity`、`NaN`和`undefined`这几个值会返回`false`，`isFinite`对于其他的数值都会返回`true`。

 

## 字符串

由于 HTML 语言的属性值使用双引号，所以很多项目约定 JavaScript 语言的字符串只使用单引号，本教程遵守这个约定。当然，只使用双引号也完全可以。

如果长字符串必须分成多行，可以在每一行的尾部使用反斜杠。

```js
var longString = 'Long \
long \
long \
string';

longString
// "Long long long string"
```



如果想输出多行字符串，有一种利用多行注释的变通方法。

```js
(function () { /*
line 1
line 2
line 3
*/}).toString().split('\n').slice(1, -1).join('\n')
// "line 1
// line 2
// line 3"
```



JavaScript 使用 Unicode 字符集。JavaScript 引擎内部，所有字符都用 Unicode 表示。

JavaScript 不仅以 Unicode 储存字符，还允许直接在程序中使用 Unicode 码点表示字符，即将字符写成`\uxxxx`的形式，其中`xxxx`代表该字符的 Unicode 码点。



 Base64 就是一种编码方法，可以将任意值转成 0～9、A～Z、a-z、`+`和`/`这64个字符组成的可打印字符。使用它的主要目的，不是为了加密，而是为了不出现特殊字符，简化程序的处理。

- `btoa()`：任意值转为 Base64 编码
- `atob()`：Base64 编码转为原来的值



## 对象

### 概述

javascript中对象就是一组“键值对”（key-value）的集合，是一种无序的复合数据集合。

```js
var obj = {
  foo: 'Hello',
  bar: 'World'
};
```

如果键名是数值，会被自动转为字符串。如果键名不符合标识名的条件），且也不是数字，则必须加上引号。

如果一个属性的值为函数，通常把这个属性称为“方法”，它可以像函数那样调用。

```js
var obj = {
  p: function (x) {
    return 2 * x;
  }
};

obj.p(1) // 2
```

对象的属性之间用逗号分隔，最后一个属性后面可以加逗号（trailing comma），也可以不加。

属性可以动态创建，不必在对象声明时就指定。

```js
var obj = {};
obj.foo = 123;
obj.foo // 123
```



#### 对象的引用

如果不同的变量名指向同一个对象，那么它们都是这个对象的引用，也就是说指向同一个内存地址。修改其中一个变量，会影响到其他所有变量。如果取消某一个变量对于原对象的引用，不会影响到另一个变量。

这种引用只局限于对象，如果两个变量指向同一个原始类型的值。那么，变量这时都是值的拷贝。



#### 表达式和语句

对象采用大括号表示，这导致了一个问题：如果行首是一个大括号，它到底是表达式还是语句？

```js
{ foo: 123 }
```

- 它是表达式，包含`foo`属性的变量。
- 是一个代码区块，里面有一个`foo`标签，指向`123`。

为了避免这种歧义，JavaScript 引擎的做法是，如果遇到这种情况，无法确定是对象还是代码块，一律解释为代码块。

 如果要解释为对象，最好在大括号前加上圆括号。因为圆括号的里面，只能是表达式。



### 属性

读取对象的属性，有两种方法，一种是使用点运算符，还有一种是使用方括号运算符。如果使用方括号运算符，键名必须放在引号里面，否则会被当作变量处理。

JavaScript 允许属性的“后绑定”，也就是说，你可以在任意时刻新增属性，没必要在定义对象的时候，就定义好属性。



查看一个对象本身的所有属性，可以使用`Object.keys`方法。

```js
var obj = {
  key1: 1,
  key2: 2
};

Object.keys(obj);
// ['key1', 'key2']
```



`delete`命令用于删除对象的属性，删除成功后返回`true`。注意，删除一个不存在的属性，`delete`不报错，而且返回`true`。

```js
var obj = { p: 1 };
Object.keys(obj) // ["p"]

delete obj.p // true
obj.p // undefined
Object.keys(obj) // []
```

只有一种情况，`delete`命令会返回`false`，那就是该属性存在，且不得删除。

```js
var obj = Object.defineProperty({}, 'p', {
  value: 123,
  configurable: false
});

obj.p // 123
delete obj.p // false
```



`in`运算符用于检查对象是否包含某个属性,`hasOwnProperty`方法判断是否为对象自身的属性。

```js
var obj = { p: 1 };
'p' in obj // true
'toString' in obj // true
console.log(obj.hasOwnProperty('toString')) // false
```



`for...in`循环用来遍历一个对象的全部属性。

- 它遍历的是对象所有可遍历（enumerable）的属性，会跳过不可遍历的属性。
- 它不仅遍历对象自身的属性，还遍历继承的属性。

使用`for...in`的时候，应该结合使用`hasOwnProperty`方法，在循环内部判断一下，某个属性是否为对象自身的属性。

```js
var person = { name: '老张' };

for (var key in person) {
  if (person.hasOwnProperty(key)) {
    console.log(key);
    console.log(person.key);
  }
}
```



`with`语句的格式如下：

```js
with (对象) {
  语句;
}

var obj = {
  p1: 1,
  p2: 2,
};
with (obj) {
  p1 = 4;
  p2 = 5;
}
// 等同于
obj.p1 = 4;
obj.p2 = 5;

```

如果`with`区块内部有变量的赋值操作，必须是当前对象已经存在的属性，否则会创造一个当前作用域的全局变量。

```js
var obj = {};
with (obj) {
  p1 = 4;
  p2 = 5;
}

obj.p1 // undefined
p1 // 4
```

这是因为`with`区块没有改变作用域，它的内部依然是当前作用域。因此，建议不要使用`with`语句，可以考虑用一个临时变量代替`with`。

```js
with(obj1.obj2.obj3) {
  console.log(p1 + p2);
}

// 可以写成
var temp = obj1.obj2.obj3;
console.log(temp.p1 + temp.p2);
```


## 函数

### 概述

- function 命令

  ```js
  function print(s) {
    console.log(s);
  }
  ```

- 函数表达式， 将一个匿名函数赋值给变量。

  ```js
  var print = function(s) {
    console.log(s);
  };
  var f = function f() {};
  ```

- Function构造函数， 用于创建对象。

  ```js
  var add = new Function(
    'x',
    'y',
    'return x + y'
  );
  
  // 等同于
  function add(x, y) {
    return x + y;
  }
  ```

  `Function`构造函数接受三个参数，除了最后一个参数是`add`函数的“函数体”，其他参数都是`add`函数的参数。



如果同一个函数被多次声明，后面的声明就会覆盖前面的声明。



####函数是第一等公民

JavaScript 语言将函数看作一种值，与其它值（数值、字符串、布尔值等等）地位相同。凡是可以使用值的地方，就能使用函数。由于函数与其他数据类型地位平等，所以在 JavaScript 语言中又称函数为第一等公民。

```js
function add(x, y) {
  return x + y;
}

// 将函数赋值给一个变量
var operator = add;

// 将函数作为参数和返回值
function a(op){
  return op;
}
a(add)(1, 1)
// 2
```



#### 函数名的提升

JavaScript 引擎将函数名视同变量名，所以采用`function`命令**声明**函数时，整个函数会像变量声明一样，被提升到代码头部。所以，下面的代码不会报错。

```js
f();

function f() {}
```



### 函数的属性和方法

- 函数的`name`属性返回函数的名字。

-　函数的`length`属性返回函数预期传入的参数个数。

-　函数的`toString`方法返回一个字符串，内容是函数的源码。

  利用这一点，可以变相实现多行字符串。

  ```js
  var multiline = function (fn) {
    var arr = fn.toString().split('\n');
    return arr.slice(1, arr.length - 1).join('\n');
  };
  
  function f() {/*
    这是一个
    多行注释
  */}
  
  multiline(f);
  // " 这是一个
  //   多行注释"
  ```



### 函数作用域

作用域（scope）指的是变量存在的范围。

对于`var`命令来说，局部变量只能在函数内部声明，在其他区块中声明，一律都是全局变量。

```
if (true) {
  var x = 5;
}
console.log(x);  // 5
```

上面代码中，变量`x`在条件判断区块之中声明，结果就是一个全局变量。



与全局作用域一样，函数作用域内部也会产生“变量提升”现象。`var`命令声明的变量，不管在什么位置，变量声明都会被提升到函数体的头部。

```js
function foo(x) {
  if (x > 100) {
    var tmp = x - 100;
  }
}

// 等同于
function foo(x) {
  var tmp;
  if (x > 100) {
    tmp = x - 100;
  };
}
```



函数本身也是一个值，也有自己的作用域。它的作用域与变量一样，就是**其声明时所在的作用域**，与其运行时所在的作用域无关。

```js
var a = 1;
var x = function () {
  console.log(a);
};

function f() {
  var a = 2;
  x();
}

f() // 1
```



### 参数

运行时无论提供多少个参数（或者不提供参数），JavaScript 都不会报错。

```js
function f(a, b) {
  return a;
}

f(1, 2, 3) // 1
f(1) // 1
f() // undefined

f.length // 2
```



函数参数如果是原始类型的值（数值、字符串、布尔值），传递方式是传值传递（passes by value）。但是，如果函数参数是复合类型的值（数组、对象、其他函数），传递方式是传址传递（pass by reference）。

```js
var obj = { p: 1 };

function f(o) {
  o.p = 2;
}
f(obj);

obj.p // 2
```

如果函数内部修改的，不是参数对象的某个属性，而是替换掉整个参数，这时不会影响到原始值。

 

如果有同名的参数，则取最后出现的那个值。

```js
function f(a, a) {
  console.log(a);
}

f(1, 2) // 2
```



```js
function f(a, a) {
  console.log(a);
}

f(1) // undefined
```

调用函数`f`的时候，没有提供第二个参数，`a`的取值就变成了`undefined`。这时，如果要获得第一个`a`的值，可以使用`arguments`对象。

```js
function f(a, a) {
  console.log(arguments[0]);
}

f(1) // 1
```



`arguments`对象包含了函数运行时的所有参数。正常模式下，`arguments`对象可以在运行时修改。严格模式下，`arguments`对象与函数参数不具有联动关系。也就是说，修改`arguments`对象不会影响到实际的函数参数。通过`arguments`对象的`length`属性，可以判断函数调用时到底带几个参数。

`arguments`对象使用数组方法，真正的解决方法是将`arguments`转为真正的数组。下面是两种常用的转换方法：`slice`方法和逐一填入新数组。

```js
var args = Array.prototype.slice.call(arguments);

// 或者
var args = [];
for (var i = 0; i < arguments.length; i++) {
  args.push(arguments[i]);
}
```



###闭包和立即调用的函数表达式

闭包就是函数`f2`，即能够读取其他函数内部变量的函数。闭包最大的特点，就是它可以“记住”诞生的环境，比如`f2`记住了它诞生的环境`f1`，所以从`f2`可以得到`f1`的内部变量。在本质上，闭包就是将函数内部和函数外部连接起来的一座桥梁。

```js
function f1() {
  var n = 999;
  function f2() {
    console.log(n);
  }
  return f2;
}

var result = f1();
result(); // 999
```

- 一个是可以读取函数内部的变量。

- 就是让这些变量始终保持在内存中，即闭包可以使得它诞生环境一直存在。

  ```js
  function createIncrementor(start) {
    return function () {
      return start++;
    };
  }
  
  var inc = createIncrementor(5);
  
  inc() // 5
  inc() // 6
  inc() // 7
  ```

  原因就在于`inc`始终在内存中，而`inc`的存在依赖于`createIncrementor`，因此也始终在内存中，不会在调用结束后，被垃圾回收机制回收。

- 闭包的另一个用处，是封装对象的私有属性和私有方法。

  ```js
  function Person(name) {
    var _age;
    function setAge(n) {
      _age = n;
    }
    function getAge() {
      return _age;
    }
  
    return {
      name: name,
      getAge: getAge,
      setAge: setAge
    };
  }
  
  var p1 = Person('张三');
  p1.setAge(25);
  p1.getAge() // 25
  ```

  上面代码中，函数`Person`的内部变量`_age`，通过闭包`getAge`和`setAge`，变成了返回对象`p1`的私有变量。



`function`关键字出现在行首，一律解释成语句。

```
(function(){ /* code */ }());
// 或者
(function(){ /* code */ })();
```

推而广之，任何让解释器以表达式来处理函数定义的方法，都能产生同样的效果。

- 一是不必为函数命名，避免了污染全局变量；
- 二是 IIFE 内部形成了一个单独的作用域，可以封装一些外部无法读取的私有变量。



###eval命令

`eval`命令接受一个字符串作为参数，并将这个字符串当作语句执行。

`eval`没有自己的作用域，都在当前作用域内执行，因此可能会修改当前作用域的变量的值，造成安全问题。

```js
var a = 1;
eval('a = 2');

a // 2
```



## 数组

任何类型的数据，都可以放入数组。

```js
var arr = [
  {a: 1},
  [1, 2, 3],
  function() {return true;}
];

arr[0] // Object {a: 1}
arr[1] // [1, 2, 3]
arr[2] // function (){return true;}
```

本质上，数组属于一种特殊的对象。`typeof`运算符会返回数组的类型是`object`。

JavaScript 语言规定，对象的**键名一律为字符串**，所以，数组的键名其实也是字符串。之所以可以用数值读取，是因为非字符串的键名会被转为字符串。

数组的`length`属性，返回数组的成员数量。该属性是一个动态的值。

清空数组的一个有效方法，就是将`length`属性设为0。



**由于数组本质上是一种对象，所以可以为数组添加属性，但是这不影响`length`属性的值。**



检查某个**键名**是否存在的运算符`in`，适用于对象，也适用于数组。



`for...in`循环不仅可以遍历对象，也可以遍历数组，毕竟数组只是一种特殊对象。但是，`for...in`不仅会遍历数组所有的数字键，还会遍历非数字键，即为数组添加的属性。

不推荐使用`for...in`遍历数组。

数组的遍历可以考虑使用`for`循环或`while`循环。



使用`delete`命令删除一个数组成员，会形成**空位**，并且不会影响`length`属性。

```js
var a = [1, 2, 3];
delete a[1];

a[1] // undefined
a.length // 3
```



典型的“类似数组的对象”是函数的`arguments`对象，以及大多数 DOM 元素集，还有字符串。

数组的`slice`方法可以将“类似数组的对象”变成真正的数组。

```js
// arguments对象
function args() { return arguments }
var arrayLike = args('a', 'b');

arrayLike[0] // 'a'
arrayLike.length // 2
arrayLike instanceof Array // false
var arr = Array.prototype.slice.call(arrayLike);
```

