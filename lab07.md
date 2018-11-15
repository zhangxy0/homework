# 硬件编程–机器指令编程实验
    姓名：张心悦
    学号：18342128
## 实验目标
1.理解冯·诺伊曼计算机的结构  
2.理解机器指令   
3.用汇编编写简单程序   

## 实验步骤与结果 
### 一.任务1  
#### 点step after step。观察并回答下面问题：  
##### PC，IR 寄存器的作用。  
PC: PC是专门用于在CPU取指令期间寻址程序存储器。PC总是保存着下一条要执行的指令的16位地址。   
IR:  
1)用来存放后续指令地址   
2)保存当前正在执行的一条指令   
3)保存将被存储的下一个数据字节的地址   
4)保存当前CPU所访问的主存单元的地址  

##### ACC 寄存器的全称与作用。  
全称:Accumulator(累加器)     
作用:主要用于完成数据的算术和逻辑运算，可以存放数据或中间结果。    

##### 用“LOD #3”指令的执行过程，解释Fetch-Execute周期。  
PC 根据地址从RAM取出指令LOD #3 
指令传入IR，指令传入Decoder，无需取址，数字3传入MUX 
数字3传入ALU之后传入ACC

##### 用“ADD W” 指令的执行过程，解释Fetch-Execute周期。  
##### “LOD #3” 与 “ADD W” 指令的执行在Fetch-Execute周期级别，有什么不同。  
  
2.点击“Binary”,观察回答下面问题  
1）写出指令 “LOD #7” 的二进制形式，按指令结构，解释每部分的含义。
2）解释 RAM 的地址。
3）该机器CPU是几位的？（按累加器的位数）
4）写出该程序对应的 C语言表达。
![images](http://a1.qpic.cn/psb?/V10JZWde3GxqHO/tnpOsfnNDsBFTx2nRl.f065D4or88POxkIml1zlUr4I!/m/dFQBAAAAAAAAnull&bo=IgP4AQAAAAADB*o!&rf=photolist&t=5)
## 实验小结
通过亲手进行的实验操作，我深刻的理解了冯·诺伊曼计算机的结构 
![images](http://a2.qpic.cn/psb?/V10JZWde3GxqHO/aRhGtAQrg5SJF*EdV07fqUtmqT4N2XiTWkoR.B.ftLA!/m/dDUBAAAAAAAAnull&bo=MgP3AQAAAAADB.U!&rf=photolist&t=5)  
![images](http://a4.qpic.cn/psb?/V10JZWde3GxqHO/VOvtx3nI0rrroo03ASxwyUImsNvfwRgMWlpWP6gu0tk!/m/dDcBAAAAAAAAnull&bo=CwPyAQAAAAADB9k!&rf=photolist&t=5)  
![images](http://a2.qpic.cn/psb?/V10JZWde3GxqHO/xp7*vp1qcfD8p4vVI2n75.pkglDjzGU6W*wOC2Qp7j4!/m/dDUBAAAAAAAAnull&bo=FQPyAQAAAAADB8c!&rf=photolist&t=5)
