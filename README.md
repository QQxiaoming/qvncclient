# QVNCClient

fork 自https://bitbucket.org/amahta/qvncclient.git 我做了一些工作：

- 增加了WebSocket的支持，并且使用状态机优化握手链接，以适应qt for WebAssembly。
- 修复了在macos上渲染的颜色错误

代码在Qt6.5.2上测试通过，如果是Qt5.x的版本，可能需要非常简单修改一下代码，但应该也是没太大问题。

来自原作者的说明该代码库不包含任何许可证，请随意使用。因此我也不会在这里加上任何许可证。保留相同许可权利，使用这个代码甚至不需要注明出处，玩的开心！

以下为原始的README.md

> QVNCClient is a Qt Widget that can be used to view and control remote VNC supported hosts (servers) <br>QVNCClient does not include any OS dependent code and therefore it can be easily used on any platform supported by Qt. <br>Just drop a QWidget on your user interface and promote it to QVNCClientWidget, as simple as that. <br>Make sure you read [this post](http://amin-ahmadi.com/2016/09/23/full-featured-vnc-client-widget-for-qt/) for more info about this repository. <br>For your questions and inquiries you can contact me from my website at [http://www.amin-ahmadi.com](http://www.amin-ahmadi.com). Make sure you use the Contact Me page from the top menu. <br>Cheers. <br>Amin
