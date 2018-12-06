    
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SNAKE_MAX_LENGTH 50
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'


char map[12][13] ={
"************",
"*XXXXH     *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"************" };
//全局变量：初始状态表
int food = 0;//定义开始时食物数量为0
int x = 0, y = 0;//定义食物的坐标（x，y）
int snake_x[SNAKE_MAX_LENGTH] = { 5, 4, 3, 2, 1 };//蛇身的横坐标
int snake_y[SNAKE_MAX_LENGTH] = { 1, 1, 1, 1, 1 };//蛇身的纵坐标
int last_X = 1, last_Y = 1;//表示蛇尾部的坐标
int length = 5;//定义初始长度，在该变量完成蛇长的变化
void move(int x, int y);//蛇移动函数
void output(void);//蛇移动效果打印函数
void clear(void);//蛇移动前的蛇图像清空
void printmap(void);//打印
int gameover(void);//判定游戏结束（碰到身子或边界）
void snakefood(void);//用来生成食物
void eatfood(void);//蛇吃食物后身体增长

int main() {
    int i;
    printmap();//打印初始状态图
    char c;
    int a = 0, b = 0;
    while ((scanf("%c", &c)) != EOF)//输入字母W,A,S,D
    {
        switch (c){//进行移动
        case 'a'://左移时
            a = 1;
            b = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 'd'://右移
            b = 1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 's'://上移
            a = -1;
            b = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        case 'w'://下移
            b = -1;
            a = 0;
            snakefood();
            move(a, b);
            if (gameover())//判定游戏是否结束
            {
                printf("\nGAME OVER!!!\n");
                break;
            }
            else
                printmap();
            break;
        }
    }//判定贪吃蛇的移动（通过move函数实现）并通过output函数实现map上的变化
    return 0;
}

void move(int a, int b){
    int i;
    if (a == 1 && b == 0)
    {
        clear();//清空map
        last_X = snake_x[length - 1];
        last_Y = snake_y[length - 1];//记录当前蛇尾坐标
        for (i = length - 1; i >= 1; i--)
        {
            snake_x[i] = snake_x[i - 1];
            snake_y[i] = snake_y[i - 1];//移动
        }
        snake_x[0]--;//蛇头移动
        eatfood();//判断是否吃了食物
        output();//移动完成
    }
    if (a == 0 && b == 1)
    {
        clear();
        last_X = snake_x[length - 1];
        last_Y = snake_y[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snake_x[i] = snake_x[i - 1];
            snake_y[i] = snake_y[i - 1];
        }
        snake_x[0]++;
        eatfood();
        output();
    }
    if (a == -1 && b == 0)
    {
        clear();
        last_X = snake_x[length - 1];
        last_Y = snake_y[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snake_x[i] = snake_x[i - 1];
            snake_y[i] = snake_y[i - 1];
        }
        snake_y[0]++;
        eatfood();
        output();
    }
    if (a == 0 && b == -1)
    {
        clear();
        last_X = snake_x[length - 1];
        last_Y = snake_y[length - 1];
        for (i = length - 1; i >= 1; i--)
        {
            snake_x[i] = snake_x[i - 1];
            snake_y[i] = snake_y[i - 1];
        }
        snake_y[0]--;
        eatfood();
        output();
    }

}

void clear(void){
    int i;
    for (i = 0; i < length; i++)
        map[snake_y[i]][snake_x[i]] = BLANK_CELL;//将蛇原来位置清空
}

void output(void){
    int i;
    map[snake_y[0]][snake_x[0]] = SNAKE_HEAD;
    for (i = 1; i < length; i++)
        map[snake_y[i]][snake_x[i]] = SNAKE_BODY;//蛇移动后的位置

}

void printmap(void){
    int i;
    for (i = 0; i < 12; i++)
    {
        printf("%s\n", map[i]);
    }
    //蛇可以完成移动，并打印
}

int gameover(void){
    int i;
    int fail = 0;
    for (i = 1; i<length; i++)//用来判断是否头碰身子
    {
        if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
            fail = 1;
    }
    if (snake_x[0]>10 || snake_y[0] > 10 || snake_x[0] < 1 || snake_y[0] < 1 || fail == 1)//前四个条件为是否触碰边界，后一个条件判断是否头碰身子
        return 1;
    else
        return 0;
}
