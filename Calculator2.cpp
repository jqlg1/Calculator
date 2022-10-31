/**
 * @file Calculator2.cpp
 * @author QianLiJia 
 * StudentNumber : 210320728 
 * E-mail : 741492060@qq.com
 * @brief 实验2：简易计算器二
 * 实验输入：带有大中小括号的四则混合运算表达式
 * 实验输出：计算结果
 * @version 0.1 
 * 整体思路混乱，疯狂debug得到最终结果，本人对自己的思路也不是 特别清晰，之后抽时间理清思路
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Funciton.h"
int main(void)
{   
    HERE:input ();
    Read();
    if( judge() )
    {
        output();
    }
    else
        goto HERE ;
}
