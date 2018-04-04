# Simplex-Method

使用单纯形法解决线性规划问题，并输出中间单纯形表。
单纯性表的格式及处理方法参见《运筹学》[1]。

## 使用方法

请先将线性规划问题转换成标准形式，并确定存在初始基可行解。
程序从运行目录下in.txt读取数据，将结果输出至out.txt。
结果表示请参考《运筹学》[1]。
请用等宽字体浏览输出文件，当单行过长时，请关闭自动换行

### 输入格式

#### 问题输入

第一行为两个正整数n，m。分别表示变量个数及方程个数。
以下m行输入一个m*n的矩阵，矩阵每个元素为分数，每行表示一个方程，每行输入格式为

    a1 a2 ... an b

代表方程

    a1*x1 + a2*x2 + ... + an*xn = b

接下来一行输入一个单词，应为"max"或"min"（不含引号），表示要求目标函数最大值或最小值。
最后一行为n个分数，表示目标函数的系数。

#### 分数输入

本程序系数支持分数输入，格式为

    (-)a(/b)

括号中内容为可选项，-表示负数，/b中b表示分母

#### 示例

若要解以下标准线性规划问题

      x1 + 2*x2 +   x3              = 8
    4*x1              + 4*x4        = 16
           4*x2              + 5*x5 = 12
    max z = 2*x1 +3*x2

请在in.txt中输入：

    5 3
    1 2 1 0 0 8
    4 0 0 1 0 16
    0 4 0 0 1 12
    max
    2 3 0 0 0

并运行程序

### 参考文献

[1] 《运筹学》教材编写组. 运筹学[M]. 北京:清华大学出版社, 2012.
