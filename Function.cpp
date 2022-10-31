#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <math.h>
#include "Funciton.h"
#include "Var.h"

using namespace std;
/**
 * @brief 输入多项式,并计算其长度
 * 
 */
void  input ()
{
    cin>>str;
    length.all = str.length();
}


/**
 * @brief 将多项式转化为字符数组
 * 
 */
void Read()
{
    for(int i = 0;i<length.all;i++)
    {
        ch[i] = str[i];
    }
}
/**
 * @brief 判读输入是否合法，即输入字符是否限于 {[(/*-+)]}0123456789.
 * 
 * @return true 合法 
 * @return false 不合法
 */
bool judge()
{
    bool flag = 0;
    for(int i = 0;i<length.all;i++)
    {
        for (int j = 0; j < 10; j++)
        {
           if (ch[i] == polynomial.opeartor[j])
           {
                flag = 1 ;
           }
        }

        if(ch[i]>= '0' && ch[i] <= '9')
        {
            flag = 1 ;
        }

        if( flag == 0 )
        {            
            cout<<"Input error!Please input again.\n";
            str.clear();
            return 0;
        }       
    }
    return 1 ;
}

/**
 * @brief 将小数点后的数字转化为 0.xxxx
 * 
 * @param i 小数点后数字的位次
 * @return double 转化后的数字  0.xxxx
 */
double num_f(int *i)
{
    int flag = *i ;
    double num = 0;
    *i = *i + 1 ;
    while (*i <= length.all &&ch[*i]>='0'&& ch[*i]<='9')
    {
        
        num += (ch[*i] - 48) * pow(10.0,  flag - (*i) );
        (*i)++;
    }
    return num ;
    
}
/**
 * @brief 判断符号为{[(/*-+)]}中的哪一个
 * 
 * @param i 
 */
int op_judge(int i,int *p)
{
    for (int j = 0; j < 10; j++)
    {
        if (ch[i] == polynomial.opeartor[j])
        {
            switch (j)
            {
            case 0:                
                *p = 2;
                return 1;
            case 1:
                *p = 1;
                return 1;
            case 2:
                *p = 2;
                return 2;
            case 3:
                *p = 1;
                return 2;
            case 4:                
                *p = 2;
                return 3;
            case 5:
                *p = 1;
                return 3;
            case 6:
                *p = 1;
                return 4;
            case 7:
                *p = 1;
                return 4;
            case 8:
                *p = 1;
                return 5;
            case 9:
                *p = 1;
                return 5 ;
            default:
                break;
            }
        }
    }
    *p = 3;
    return 0;
}
void output()
{
    int lv = 0 ;
    int toplv[20] = {0} , j = 1;
    int flag = 0;
    for (int i = 0; i < length.all; i++)
    {
        lv = op_judge(i,&flag);//  {}:1 []:2 ():3 +-:4 /*:5
        if(flag == 1 ) //   / * - +  }  ]  )
        {
            if (lv > toplv[op_stack.num-1])
            {
                op_stack.push(ch[i]);
                toplv[op_stack.num-1] = lv ;
            }
            else if(lv <= toplv[op_stack.num-1] && toplv[op_stack.num-1] != 0)
            {
                suan();
                if(toplv[op_stack.num-1] == lv)
                {
                    suan();
                }
                if(ch[i]=='-'||ch[i]=='+'||ch[i]=='*'||ch[i]=='/')
                {
                    op_stack.push(ch[i]);
                    toplv[op_stack.num - 1] = lv;
                }
            }    
        }
        else if (flag ==  2) //{[(
        {
            op_stack.push(ch[i]);
            toplv[op_stack.num-1] = lv ;
        }
        else if (flag == 3)// 0 1 2 3 4 5 6 7 8 9 .
        {
            double num_push = 0;
            bool sign = 0;
            while (ch[i] >= '0' && ch[i] <= '9')
            {
                num_push = ch[i] - 48 + num_push * 10.0;
                i++;
                sign = 1;
            }
            if (ch[i] == '.')
            {
                num_push += num_f(&i);
            }
            if (sign == 1)
            {
                num_stack.push(num_push);    
                i = i - 1 ;    
            }
        }
        
    }
    while (op_stack.bracket[1] != 0)
    {
        suan();
        //op_stack.pop();
    }
    cout << num_stack.bracket[1];
}

void suan()
{
    if (op_stack.bracket[op_stack.num-1] == '+')
    {
        num_stack.bracket[num_stack.num - 2] = num_stack.bracket[num_stack.num - 2] + num_stack.bracket[num_stack.num - 1];
        num_stack.pop();
        op_stack.pop();
    }
    else if (op_stack.bracket[op_stack.num-1] == '-')
    {
        num_stack.bracket[num_stack.num - 2] = num_stack.bracket[num_stack.num - 2] - num_stack.bracket[num_stack.num - 1];
        num_stack.pop();
        op_stack.pop();
    }
    else if (op_stack.bracket[op_stack.num-1] == '*')
    {
        num_stack.bracket[num_stack.num - 2] = num_stack.bracket[num_stack.num - 2] * num_stack.bracket[num_stack.num - 1];
        num_stack.pop();
        op_stack.pop();
    }
    else if (op_stack.bracket[op_stack.num-1] == '/')
    {
        num_stack.bracket[num_stack.num - 2] = num_stack.bracket[num_stack.num - 2] / num_stack.bracket[num_stack.num - 1];
        num_stack.pop();
        op_stack.pop();
    }
    else if (op_stack.bracket[op_stack.num-1] == '(' || op_stack.bracket[op_stack.num-1] == '[' || op_stack.bracket[op_stack.num-1] == '{')
    {
        op_stack.pop();
    }
}