# C语言第一次期中考试复习
---
*主要是之前的代码梳理啦，顺带复习一些知识点*

作者：Zhu_Ying

---
### 第一节 基本概念
其实就是打印hello world。。。

1.主函数与基本框架
```
#include <stdio.h>
#define N 50

int main()
{
    printf("hello world!");

    return 0;
}
```
    其中的点有这么几个
        ①#include 是一个预处理指令，用于在编译前将一个源代码文件的内容包含到另一个源代码文件中。这个指令通常用于包含标准库的头文件，或者项目中的其他头文件。
        ②stdio.h为标准输入输出库，在之后我们会接触到的库文件有：
            math.h  数学库，存有一些高级的数学运算函数
            string.h 字符串操作库，用于创建、复制、连接、比较、搜索、修改以及其它对字符串进行操作的功能。
            ……
        ③#define 为宏定义，在以上程序中无作用，可删去，仅作为程序结构中其位置参考示意
        ④int main 主函数，是程序执行的入口，return后的数字必须与int类型保持一致，为程序的出口（在函数里面我们会详细讲到）
        {}用来囊括主函数的执行范围

---
### 第二节 变量与常量
###### 程序一：change.c （*超市找零情景*）
```
#include <stdio.h>

int main ()
{
    const int MONEY = 100; //定义常量
    int price = 0;

//输入价格
    printf("you have 100 yuan to get what you want,please choose the price of your item:\n");
    scanf("%d",&price);

//计算找零并输出
    int result = MONEY - price;
    printf("your change is %d\n",result);

    return 0;//退出程序
}
```
    知识点：常量的定义
        方式一：宏定义
            #define MONEY 100;
        方式二：const 数据类型 标识符 = 值
            const int MONEY = 100;

###### 程序二 tax.c (*税收情景*)
```
#include <stdio.h>
#define INCOME 4000 //宏定义常量

int main()
{
    int actual = INCOME - 3500;
    float tax_factor = 0.03;

    //计算并打印税收
    float tax =actual*tax_factor;
    printf("your tax is %.2f\n",tax);
    return 0;
}
```
    知识点：
    浮点数的表示
        1.浮点数默认显示小数点后6位
        2.控制浮点精度：
            %.nf  保留n位小数
            但是注意可能会有精度丢失
    一些符号：
        \n 换行
        \t 水平制表符（tab）
        \v 垂直制表符
        \\ 反斜杠
        \a 响铃
        \b 退格
        \f 换页
        \r 回车
        \0 空字符（在字符数组中会用到，作为字符串的结尾）

###### 程序三 进制转换
```
#include <stdio.h>

int main()
{
    float num = 0;
    printf("please input a number:");
    scanf("%f",&num);
//转换为十六进制打印
    printf("the number you input in hexadecimal is %x\n",num);
    printf("the number you input in hexadecimal(uppercase) is %X\n",num);

    return 0;
}
```

    知识点：进制转换
        对于整数：
        1.%d 或 %i：以十进制形式打印整数。
        2.%u：以十进制形式打印无符号整数。
        3.%x 或 %X：以十六进制形式打印整数。%x 使用小写字母（a-f），而 %X 使用大写字母（A-F）。
        4.%o：以八进制形式打印整数。
        5.%p：以十六进制形式打印指针的值，通常用于打印内存地址。
        
        对于浮点数，可以使用以下格式说明符：
        1.%f：以十进制形式打印浮点数。
        2.%e 或 %E：以科学记数法的形式打印浮点数。%e 使用小写字母（e），而 %E 使用大写字母（E）。
        3.%g 或 %G：自动选择 %f 或 %e 中较短的表示方式来打印浮点数。%g 不会打印无意义的零。

        对于字符和字符串，可以使用：
        1.%c：打印单个字符。
        2.%s：打印字符串。

        还有一些其他格式说明符用于特定的打印需求：
        1.%%：打印百分号（%）字符。
        2.%n：不打印任何内容，但会更新一个变量，该变量表示到目前为止已经打印了多少字符。
        
        这些格式说明符可以与长度修饰符一起使用，例如 %ld 用于打印 long 类型的整数，%lf 用于打印 double 类型的浮点数。


### 第五节 数组
###### 程序一：矩阵运算：读入一个正整数n(1<=n<=6),再读入n阶方阵a，计算该矩阵除副对角线，最后一列和最后一行以外的所有元素之和。副对角线为从矩阵的右上角至左下角的连线。
```
#include <stdio.h>

int main()
{
//定义区
    int a[100][100]; //可以这么定义：int a[100][100] = {0};
    int len = 0 , sum = 0;

//输入数组长度
    scanf("%d",&len);

//输入数组：重点结构！
    for(int i = 0; i < len ; i++)
    {
        for(int j = 0 ; j < len ; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

//重点结构：遍历数组，来进行计算求和判断
    for(int i = 0 ; i < len - 1 ; i++)//题目有要求不包括最后一行和最后一列的元素，直接len-1
    {
        for (int j = 0 ; j < len - 1; j++)
        {
            if (j == len - i - 1)
            {
                continue;//跳过副对角线的元素
            }
            else
            {
                sum += a[i][j];//直接+=，省心省力awa
            }
        }
    }

//打印输出最终结果
    printf("%d",sum);

    return 0;
}
```

    复习：
    1.数组的定义与初始化：
        ·数据类型 数组名[len] = {0}/{值1，值2，……}
        ·(#include <string.h>) memset(数组名,0,sizeof(数组名))

        ·二维数组：a[2][3]={{1,2,5}{3,4,6}}/{1,2,5,3,4,6}
        注意列的部分一定要写，要不然数组对应不唯一
    2.跳出（本次）循环的三种方式：
        (1)break;
            单独使用，直接跳出，但是一次只能跳出一层循环；
        (2)continue;
            跳过本次循环，直接开始下次迭代
        (3)goto 标签名;
            跳出到标签，但是会降低程序的可读性和可维护性，不建议使用

###### 程序二 删除字符：输入一个字符串s,再输入一个字符c,将字符串s中出现的所有字符c删除。试编写程序，不允许直接调用库函数。字符串长度不超过50