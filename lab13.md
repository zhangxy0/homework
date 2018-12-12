# 贪吃蛇实验报告
## 游戏概述
贪吃蛇是一个经久不衰的小游戏，这与它的简单易上手有着很大的联系。虽然这是一个十分简单的小游戏，但对于一个C语言的初学者来说，想要实现还是存在一定的困难的。不过跟随着TA的讲解，采用自顶向下的方法，这个小游戏勉强还是可以实现的。  

## 程序结构
程序主体结构大致如下
		
		
	输出字符矩阵
	WHILE not 游戏结束 DO
		ch＝等待输入
		CASE ch DO
		‘A’:左前进一步，break 
		‘D’:右前进一步，break    
		‘W’:上前进一步，break    
		‘S’:下前进一步，break    
		END CASE
		输出字符矩阵
	END WHILE
	输出 Game Over!!! 
  
 因此，我们需要完成的就是对这一段伪代码的填充，包括函数头部的定义，具体函数的实现等等。  
 具体程序见snake_eat.c(https://github.com/zhangxy0/zxy-homework/blob/gh-pages/snake_eat.c)  
 以及snake_move.c(https://github.com/zhangxy0/zxy-homework/blob/gh-pages/snake_move.c)
