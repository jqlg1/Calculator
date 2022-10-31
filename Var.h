#include <string>
#include "Funciton.h"
using std::string ;
extern char ch[];
extern string str;
class Length
{
    public:
    int all = 0;
    int num = 0;
    int op = 0;
};

class Polynomial
{
public:
    int num[10];
    char opeartor[10]={'{','}','[',']','(',')','+','-','*','/'};
    char point = '.';

};
extern Length length;
extern Polynomial polynomial;
template <class numtype>
class Stack
{
    public:
        numtype bracket[20] ={0};  
        int num = 1;
        void push(numtype a);
        void pop();
};

template<class numtype>
void Stack<numtype>::push(numtype a)
{
    
    bracket[num] = a;
    num++;
}
template<class numtype>
void Stack<numtype>::pop()
{
    num = num -1 ;
    bracket[num] = 0;
    
}











extern Stack<char> op_stack ;
extern Stack<double> num_stack;