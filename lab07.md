# 硬件编程–机器指令编程


任务 1：简单程序

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