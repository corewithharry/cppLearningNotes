# 使用责任链模式实现LISP表达式建立语法树

现在我们要开始本次实验了——具体内容是让大家亲自来实现责任链模式的四个`ExprHandler`，同时实现针对抽象语法树的`IVisitor`接口类。

大部分需要的代码都已经给出——大家需要完成的内容位于handler.cpp和Visitor.cpp中，大家需要实现所有的`handler`以及`Visitor`。

四种`handler`接受的`token`符合以下语法规则：

- `IdExpr`：只能由字母和数字组成，首字符不能为数字
- `NumberExpr`：只能由数字组成
- `BinaryExpr`：`token`只能为四则运算符号`+` `-` `*` /中的任何一个（`Test`函数只检查`token`）
- `InvokeExpr`：对`token`的检查方式与`Id`等同

此外，第二个`bool`参数`Invoke`表示当前表达式类型为`Invoke`。换句话说，所有`Handler`都要检查`Invoke`的值——如果其他`Handler`的`Invoke`是`true`，或者`InvokeHandler`的`Invoke`是`false`，那都要直接判断为`false`。

本题没有输入，并使用我们已经接触的 `TDD` 方式进行开发——如果你的实现是正确的，那么你的程序编译运行时将可以通过所有的`assert`，正确结束。

## 提示

如果大家对于语法判断还有不明白的地方，可以直接查看`main.cpp`中的测例。而对于`CreateExpr`函数，大家可以复习之前学过的关于`make_shared`函数的相关用法。

`IdExpr`和`NumberExpr`都没有参数，它们的`CreateExpr`函数中可以不理会`arguments`——而对于`BinaryExpr`，形如`(* 8 17 1926)`的表达式，需要被正确处理成`(* (* 8 17) 1926))`。大家可以判断arguments的数量，然后通过递归调用来完成表达式的构建。

对于`IVisitor`，实现方式跟之前一样，这里不再赘述——具体的输出格式，大家可以直接参照测例完成（有语法错误的表达式会判断为"`angry`"，你的`IVisitor`不需要进行处理）。



## 本地判分

在 `/include` 文件夹内包含了头文件（`header file`） ，头文件声明了函数和类；

在 `/src` 文件夹内含有具体的 `.cpp/.cc` 文件，其中包含了对相关函数的实现。

`IVisitor` 类的定义在 `visitor.h` 头文件中，类成员函数的实现位于文件 `visitor.cpp` 中，`ExprHandler`及其派生类定义在`handler.h`中，实现位于`handler.cpp`中，你需要在这两个文件中实现相关函数，如有必要你可以在头文件中自行添加额外的成员函数和成员变量；

主函数保存在 `main.cpp` 中，其中包含了全部单元测试的测例——你对`main.cpp`的任何修改都会被系统自动忽略。

在自测时你可以在终端中输入 `make` 来编译执行本地判分器，输入 `make clean` 可以清空之前编译出的文件。其它的 `make` 指令可以在 `Makefile` 中查看。



## 提交与在线判分

正如前面提到的，这次作业由在线判分器进行自动判分。

在这次任务中，你可以修改绝大部分 `.cpp` 文件和头文件，对其他文件的修改将会被系统忽略。你可以随意向`standard output`输出任何内容——因为主函数将使用`assert`进行单元测试。每当你通过一个测例时，屏幕上就会输出`Test X passed`，X是你通过的测试的编号——而在本地测试中，当测试失败时程序会直接终止，后面的测试将不会被执行。

当你在本地通过所有单元测试时，屏幕将显示`You have passed all tests!`

本次实验有 `2020` 个测例——在线上测试中，每通过一个测例即可得到 `55` 分，满分 `100100` 分。

注 1：你可以反复提交评分，你的最终分数将以最高一次提交得分为准。

注 2：本项目作业需要你独立完成，使用他人提供的代码进行提交（无论是否为最高分提交）都将被视为违背学术纯洁性的行为。更多信息请参考《学术准则》。



---



## 分析

 ![3F6Wn.png](https://wx2.sbimg.cn/2020/08/22/3F6Wn.png)

### `Parser.cpp`

 ![3VKyM.png](https://wx2.sbimg.cn/2020/08/22/3VKyM.png)

以空格分开

把字符串第一个字符串提取出作为`token`

后面的每个部分`push`到`arguments`中



### `handler.cpp`中的`BinaryFactor::CreateExpr`

看主函数`(* 1 2 3)` 会被解析成`(* (* 1 2) 3)`

 ![3VZeR.png](https://wx2.sbimg.cn/2020/08/22/3VZeR.png)