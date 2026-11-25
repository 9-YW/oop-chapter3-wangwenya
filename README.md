# OOP Chapter 3

面向对象程序设计第 3 章实验源代码，包含四个独立的 C++11 多文件工程：

- `Date`：日期合法性校验、星期计算、闰年判断和下一日推算
- `Triangle`：三角形校验、周长、面积与类型判断
- `MyArray`：动态整型数组、深拷贝、合并与四则运算
- `Point`：空间点距离与中点，包含成员函数和友元函数实现

## 编译方式

在仓库根目录执行：

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic Date/Date.cpp Date/main.cpp -o date_app
g++ -std=c++11 -Wall -Wextra -pedantic Triangle/Triangle.cpp Triangle/main.cpp -o triangle_app
g++ -std=c++11 -Wall -Wextra -pedantic MyArray/MyArray.cpp MyArray/main.cpp -o myarray_app
g++ -std=c++11 -Wall -Wextra -pedantic Point/Point.cpp Point/main.cpp -o point_app
```

## 运行示例

```text
date_app      输入：2026 11 24
triangle_app  输入：3 4 5
myarray_app   直接运行
point_app     输入：0 0 0 和 3 4 12
```
