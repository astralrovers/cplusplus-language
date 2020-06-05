# 简单说明googletest的用法

**记录一些常用的知识点，更多的参考非常全面的官方文档。本文不介绍`googlemock`**

- `git`路径:https://github.com/google/googletest

- 常用例子:`googletest/simple`
- 全面的例子:`googletest/test`
- 文档:`googletest/docs`
  - `samples.md`对于`simple`目录例子的说明
  - `primer.md`简单介绍
  - `faq.md`有一些你可能感到疑惑或者想深入了解`googletest`的文档
  - `advanced.md`非常详细的使用说明文档

## 安装

这里介绍使用`cmake`来编译安装。

- 下载好之后:`mkdir mybuild`;
- `cd mybuild`;
- `cmake ${下载的googletest路径}`;
- `make`;
- `make install`.

**编译的时候加上`-lgtest`选项**

## 文件说明

- `test_assert.cpp`常用断言
- `test_setup_tears.cpp`测试用例前后执行的事件
- `test_with_param.cpp`关于测试数据参数化

