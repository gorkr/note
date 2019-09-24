# electron

> Electron将[Chromium](https://www.chromium.org/Home)和[Node.js](https://nodejs.org/)合并到同一个运行时环境中

> Electron使用了网页页面作为App的GUI，因此你可以将它看做是一个由JavaScript控制的一个小型的Chrome内核浏览器。

## 主进程VS渲染进程

###主进程

在Electron中，跑`package.json`里的主脚本的进程叫作主进程。在主进程里跑的脚本可以通过创建web页面的窗口来扮演GUI角色。

###渲染进程

Electron使用了chrome内核，才使得它**多进程**的结构也可以被我们使用。在Electron里的每个页面都有它自己的进程，叫作渲染进程。

在普通的浏览器里，网页页面跑在一个沙盒环境下，不能接触到native源码。而Electron则允许你在页面中使用Node.js的API，较低程度上的和操作系统进行交互。

渲染进程如同传统的HTML，但它**可以直接使用Node模块。**

### 主进程和渲染进程的不同

主进程通过实例化`BrowserWindow`，每个`BrowserWindow`实例都在它自己的渲染进程内返回一个web页面。当`BrowserWindow`实例销毁时，相应的渲染进程也会终止。

主进程负责掌管所有的web页面和它们相应的渲染进程。每个渲染进程都是相互独立的，它们只关心自己所运行的web页面。

在页面（渲染进程）中不允许调用原生GUI相关的API，那是因为在网页（渲染进程）中中掌管原生GUI很危险，易造成内存泄露。如果你想在网页中进行GUI的操作，渲染进程必须向主进程传达请求，然后在主进程中完成操作。

在Electron中，我们有几种连接主进程和渲染进程的方法，例如用于传送消息的[`ipcRenderer`](https://github.com/heyunjiang/electron/blob/master/docs/api/ipc-renderer.md)和[`ipcMain`](https://github.com/heyunjiang/electron/blob/master/docs/api/ipc-main.md)模块，以及用于RPC的[`remote`](https://github.com/heyunjiang/electron/blob/master/docs/api/remote.md)模块。

### 不同页面间共享数据

非常简单，使用HTML5 API就能完成。

[`Storage API`](https://developer.mozilla.org/en-US/docs/Web/API/Storage)，[`IndexedDB`](https://developer.mozilla.org/en-US/docs/Web/API/IndexedDB_API)都是很好的选择。

你还可以使用Electron中提供的`IPC`系统。它在主进程中将一个对象储存为全局变量，然后可以通过`remote`模块操作它们：

```
// 在主进程里
global.sharedObject = {
  someProperty: 'default value'
};
// In page 1.
require('remote').getGlobal('sharedObject').someProperty = 'new value';

// In page 2.
console.log(require('remote').getGlobal('sharedObject').someProperty);
```