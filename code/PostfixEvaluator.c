#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*This code is primitive and works only on the basic operators
and is only tested on one example
*/
int main() {
    int stop =-1;
    int ptop = -1;
    char postfix[] = "53+62/*35*+";
    
    int postfix_size = strlen(postfix);
    int output;
    int stack[postfix_size];
    
    //SCANNING EACH CHARACTER
    for (int i = 0;i<postfix_size;i++){
        char c = postfix[i];
        if (isdigit(c)){
            //C is a number attempt to convert into integer
            int num = c-'0';
            //Explanation:
            /*
            We are just basically subtracting the ascii value of the 
            number say, 1(ASCII: 49) minus 0(ASCII:48) which results in
            1 which is effectively the number we want(i.e. 49-48=1)
            
            */
            //Once converted put into stack
            stop+=1;
            stack[stop] = num;
        }
        else if (c=='^'){
            //Exponent Operator(USE WITH CAUTION)
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            int result = pow(op1,op2);
            stack[stop] = result;
            
        }
        else if (c=='+'){
            //Addition Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1+op2;
            
        }
        else if (c=='-'){
            //Subtraction Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1-op2;
            
        }
        else if (c=='*'){
            //Multiplication Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1*op2;
            
        }
        else if (c=='/'){
            //Division Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1/op2;
            
        }
    }
    printf("OUTPUT: %d",stack[stop]);
    return 0;
}
