# 智能蛇实验报告
## 概述
显然，智能蛇比贪吃蛇的难度提升了不止一个级别，不过好在介绍中给出了大部分的提示。关于智能蛇的算法，我们不难发现如果蛇沿着障碍物（蛇的身子，墙壁）走，是最不容易死亡的一种方式。因此，我们的任务就是实现这一功能。
## 程序结构
与简易版贪吃蛇相同，我们先来看一下程序框架 
    
    输出字符矩阵 
    WHILE not 游戏结束 DO 
        wait(time) 
        ch＝whereGoNext(Hx,Hy,Fx,Fy) 
        CASE ch DO 
        ‘A’:左前进一步，break  
        ‘D’:右前进一步，break 
        ‘W’:上前进一步，break 
        ‘S’:下前进一步，break 
        END CASE 
        输出字符矩阵 
    END WHILE 
    输出 Game Over!!! 

其次是决定蛇行走的方向函数的伪代码： 
    
    Hx,Hy: 头的位置 
    Fx,Fy：食物的位置 
    function whereGoNext(Hx,Hy,Fx,Fy) { 
      用数组movable[3]={“a”,”d”,”w”,”s”} 记录可走的方向 
      用数组distance[3]={0,0,0,0} 记录离食物的距离 
      分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置 
           例如：假设输入”a” 则distance[0] = |Fx – (Hx-1)| + |Fy – Hy| 
                 如果 Hx-1，Hy 位置不是Blank，则 distance[0] = 9999 
       选择distance中存最小距离的下标p，注意最小距离不能是9999 
       返回 movable[p] 
    }

接着，我们需要完成的工作就是依据“自顶向下，逐步求精”的方法完善这一框架以及伪代码，然而由于我实在是初学C语言，独立完成这一任务有些困难（bug太多了）。不过我希望通过学习，我可以早日独立完成这一任务。
![images](http://m.qpic.cn/psb?/V10JZWde3GxqHO/RQ.qObrSXO9rJiSajB01vkyvLk3pT4Q1i9dX0wi3qUs!/b/dLgAAAAAAAAA&bo=KwErAQAAAAACR2M!&rf=viewer_4)
