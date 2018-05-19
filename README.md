# Drive-scheduling
```
using vs2017 for project
```
# 实验报告
## 实验内容
模拟电梯调度算法，实现对磁盘的驱动调度。
## 实验目的
磁盘是一种高速、大容量、旋转型、可直接存取的存储设备。它作为计算机系统的辅
助存储器，担负着繁重的输入输出任务、在多道程序设计系统中，往往同时会有若干个要求
访问磁盘的输入输出请求等待处理。系统可采用一种策略，尽可能按最佳次序执行要求访问
磁盘的诸输入输出请求。这就叫驱动调度，使用的算法称为驱动调度算法。驱动调度能降低
为若干个输入输出请求服务所需的总时间，从而提高系统效率。本实验要求学生模拟设计一
个驱动调度程序，观察驱动调度程序的动态运行过程。通过实验使学生理解和掌握驱动调度
的职能。
## 实验题目
模拟电梯调度算法，对磁盘进行移臂和旋转调度。
**[提示]**
（1）磁盘是可供多个进程共享的存储设备，但一个磁盘每时刻只能为一个进程服务。
当有进程在访问某个磁盘时，其他想访问该磁盘的进程必须等待，直到磁盘一次工作结束。
当有多个进程提出输入输出要求而处于等待状态时，可用电梯调度算法从若干个等待访问者
中选择一个进程，让它访问磁盘。选择访问者的工作由“驱动调度”进程来完成。
由于磁盘与处理器是可以并行工作的、所以当磁盘在作为一个进程服务时，占有处理
器的另一进程可以提出使用磁盘的要求，也就是说，系统能动态地接收新的输入输出请求。
为了模拟这种情况，在本实验中设置了一个“接收请求”进程。
“驱动调度”进程和“接收请求”进程能否占有处理器运行，取决于磁盘的结束中断信
号和处理器调度策略。在实验中可用随机数来模拟确定这两个进程的运行顺序，以代替中断
处理和处理器调度选择的过程。
（2）“接收请求”进程建立一张“请求 I/O”表，指出访问磁盘的进程要求访问的物理
地址，表的格式为：
进程名 柱面号 磁道号 物理记录号

假定某个磁盘组共有 200 个柱面，由外向里顺序编号（0—199），每个柱面上有 20 个
磁道，编号为 0—19，每个磁道分成 8 个物理记录，编号 0—7。进程访问磁盘的物理地址
可以用键盘输入的方法模拟得到。
在实际的系统中必须把等待访问磁盘的进程排入等待列队，由于本实验模拟驱动调
度，为简单起见，在实验中可免去队列管理部分，故设计程序时可不考虑“进程排入等待队
列”的工作。
（3）“驱动调度”进程的功能是查“请求 I/O”表，当有等待访问磁盘的进程时，按
电梯调度算法从中选择一个等待访问者，按该进程指定的磁盘物理地址启动磁盘为其服务。
对移动臂磁盘来说，驱动调度分移臂调度和旋转调度。电梯调度算法的调度策略是与
移动臂的移动方向和移动臂的当前位子有关的，所以每次启动磁盘时都应登记移动臂方向和
当前位子。电梯调度算法是一种简单而实用的驱动调度方法，这种调度策略总是优先选择与
当前柱面号相同的访问请求，从这些请求中再选择一个能使旋转距离最短的等待访问者。如
果没有与当前柱面号相同的访问请求，则根据移臂方向来选择，每次总是沿臂移动方向选择
一个与当前柱面号最近的访问请求，若沿这个方向没有访问请求时，就改变臂的移动方向。
这种调度策略能使移动臂的移动频率极小，从而提高系统效率。
（4）图 3－1 中的初始化工作包括，初始化“请求 I/O”表，置当前移臂方向为里移；
置当前位置为 0 号柱面，0 号物理记录。程序运行前可假定“请求 I/O”表中已经有如干个
进程等待访问磁盘。
在模拟实验中，当选中一个进程可以访问磁盘时，并不实际地启动磁盘，而用显示：“请
求 I/O”表；当前移臂方向；当前柱面号，物理记录号来代替图 3－3 中的“启动磁盘”这
项工作。
## 实验报告
（1）实验题目。
（2）程序中使用的数据结构及其说明。
（3）打印一份源程序并附上注释。
（4）打印驱动调度进程每次选择访问请求前的“请求 I/O”表以及每次选中的进程名、
访问的柱面号、物理记录号和当前移臂方向（用 up 代表里移，down 代表外移。打印格式为：
“请求 I/O”表
进程名 柱面号 物理记录号 方向

# 添加内容（历史数据）
- Add main.cpp and IO_Table Class
- Realize random float number generator in main.cpp
- Construct the IO_Table private part
-basic procedure construction complete
-Realize Accept_Order & Select_By_Cylinder function
-complete function Judge_For_MaxMin 

-Waiting for complete:
* Adding new function Select_By_Track()
* procedure:Run_Driven
* Data:for testing

