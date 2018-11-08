# 封面：硬件编程——机器指令编程 实验报告

## 18342040 景致


## 目录：  
### 1. 任务 1
### 2. 任务 2


## 实验目的：
- 理解冯·诺伊曼计算机的结构
- 理解机器指令的构成
- 理解机器指令执行周期
- 用汇编编写简单程序
- 了解并懂得初步使用汇编语言 
- 了解 CPU 中各组件的作用 
- 通过比较,得出高级语言与机器语言的联系与区别

## 实验步骤：
- 用简单 CPU 仿真工具 Pippin CPUSim ！观察 CPU 的运行
- 完成任务 1
- 完成任务 2



#### 任务 1：简单程序
![](http://a1.qpic.cn/psb?/V10TJRfP2sMibY/rno6QKPQ0tvQIjr5xYjuKsiODIJ46x5CSw.9QenLwXM!/b/dFQBAAAAAAAA&ek=1&kp=1&pt=0&bo=cAKQAQAAAAADF9E!&tl=1&vuin=1960226332&tm=1541689200&sce=60-4-3&rf=viewer_4)

（1）打开网页 The PIPPIN User’s Guide ，然后输入 Program 1：Add 2 number

（2）点step after step。观察并回答下面问题：

1. PC，IR 寄存器的作用。  
PC:Program Counter 程序计数器，存放下一条指令在内存中的地址。  
IR:Instruction Register 指令寄存器，用来保存当前正在执行的一条指令。
2. ACC 寄存器的全称与作用。   
ACC: Accumulator 累加寄存器，是一个具有特殊用途的二进制 8 位寄存器，专门用来存放操作数或运算结果。功能是当运算器的算术逻辑单元(ALU)执行全部算术和逻辑运算时，为ALU提供一个工作区，暂时存放ALU运算结果。

3. 用“LOD #3”指令的执行过程，解释Fetch-Execute周期。
PC 按 0 地址从 RAM 中 Fetch the instruction 读到 IR 中，再通过 Decoder 来 Decode the instruction，分别读到 MUX 和 ALU 中，之后 Execute the instruction，将 3 从 IR 通过 MUX 存在 ACC 中，并进行下一次 Fetch-Execute 周期。

4. 用“ADD W” 指令的执行过程，解释Fetch-Execute周期。
PC 按 8 地址 Fetch the instruction 读到 IR 中，再通过 Decoder 来 Decode the instruction，读到 ALU 中，之后 Get data X , Execute the instruction，将 ACC 中 X 的值放在 ALU 中，再次向 RAM 取 W 的值置于 ALU 中，再将 X 和 W 的值相加，将结果存在 ACC 中，并进行下一次 Fetch-Execute 周期。

5. “LOD #3” 与 “ADD W” 指令的执行在Fetch-Execute周期级别，有什么不同。
LOD #3只需访问 RAM 一次,而 ADD W 需要两次访问 RAM 。
 
（3）点击“Binary”,观察回答下面问题

1. 写出指令 “LOD #7” 的二进制形式，按指令结构，解释每部分的含义。  
00010100 00000111 
一个是命令指示 一个是操作数
2. 解释 RAM 的地址。  
只用于暂时存放程序和数据，一旦关闭电源或发生断电，其中的程序和数据就会丢失。
3. 该机器CPU是几位的？（按累加器的位数）  
8 位
4. 写出该程序对应的 C语言表达。  
int x = 7;  
int w = 3;  
int y = w + x;  


#### 任务 2：简单循环
![](http://m.qpic.cn/psb?/V10TJRfP2sMibY/h.HvkR0PNHuu8lVyndaU2XbdZG*NUnFvAHfk6unYGzQ!/b/dDQBAAAAAAAA&bo=qAJ3AQAAAAADF.4!&rf=viewer_4)

（1） 输入程序Program 2，运行并回答问题：

1. 用一句话总结程序的功能
X 从 3 开始递减 1，直到 X 值为 0 


2. 写出对应的 c 语言程序
（2） 修改该程序，用机器语言实现 10+9+8+..1 ，输出结果存放于内存 Y

1. 写出 c 语言的计算过程
```C
#include<stdio.h>

int main(void)
{
    int Y = 0;

    for(int i = 1;i <= 10;i++)
        Y = Y + i;

    return 0;
}
```
2. 写出机器语言的计算过程  
LOD #0  
00010100 00000000  
STO Y  
00000101 10000010  
LOD #11  
00010100 00001011  
STO X  
00000101 10000001  
LOD X  
00000100 10000001  
SUB #1  
00010001 00000001  
STO X  
00000101 10000001  
JMZ 20  
00001101 00010100  
LOD Y  
00000100 10000010  
ADD X  
00000000 10000001  
STO Y  
00000101 10000010  
JMP 8  
00001100 00001000  
HLT  
00001111 00000000  

3. 用自己的语言，简单总结高级语言与机器语言的区别与联系。
联系:高级语言经编译可变为机械语言,都可以实现顺序，选择和循环   
区别：高级语言更接近人类语言,是给人看的 ; 机器语言是纯粹的二进制数据,一般人看不懂(即是给机器看的,不是给人看的)  


## 实验小结:

1. 在对汇编语言的学习过程中,懂得了什么是汇编语言,机器语言,高级语言并知道了他们之间的联系与区别。
2. 知道了什么是指令格式和指令周期。
3. 了解到 CPU 各组件的作用,与 CPU 的运算过程。