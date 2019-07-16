#include <stdio.h>
#define stackEntry char
#include "stack.h"

int ischar(char c)
{
    if((c >= '0' && c <= '9') || c == ' ' || c == '.')
        return 1;
    else return 0;
}

int ifper(char c1, char c2)
{
    if(c1 == '$')
        return 1;

    if(c1 == '*' || c1 == '/')
        return (c2 != '$');
    if(c1 == '+' || c1 == '-')
        return (c2 != '$' && c2 != '*' && c2 != '/');
    return 0;
}
float oper(float i1, float i2, char s)
{
    float sum;
    
    switch (s)
    {
    case '*':
        sum = i1 * i2;
        break;
    case '/':
        sum = i1 / i2;
        break;
    case '+':
        sum = i1 + i2;
        break;
    case '-':
        sum = i1 - i2;
        break;
    
    }
    
    return sum;
}
void op(char postfex[])
{
    stack s;
    createstack(&s);
    float i1, i2; int i;
    char c;
    char nn[10];
    float num;
    int num2;
    for ( i = 0; postfex[i] != '\0'; i++)
    {
        
        i1 = i2 = 0;
        if(ischar(postfex[i]))
        {
            push(postfex[i], &s);
        }else
        {
            pop(&c, &s);
            if(c == ' ')
            {
                pop(&c, &s);
                int cont = 1;
                while (c != ' ')
                {
                    if(c == '.')
                    {
                        i2 = (i2/cont);
                        cont = 1;
                    }else
                    {
                        i2 += cont*(c - '0');
                        cont *= 10;
                    }
                    
                    
                    pop(&c, &s);
                }
                
            }else
                i2 = c - '0';

            pop(&c, &s);
            if(c == ' ')
            {
                int cont = 1;
                pop(&c, &s);
                while (c != ' ')
                {
                    if(c == '.')
                    {
                        i1 = (i1/cont);
                        cont = 1;
                    }else
                    {
                        i1 += cont*(c - '0');
                        cont *= 10;
                    }
                    
                    
                    pop(&c, &s);
                }
            }else
                i1 = c - '0';
            num = oper(i1, i2, postfex[i]);
            if((((int)(num*100))%100) > 0 && num > 9)
            {
                push(' ', &s);
                num2 = num;
                
                sprintf(nn, "%d", num2);
                for (int k = 0; nn[k] != '\0'; k++)
                {
                    push(nn[k], &s);
                }
                num2 = ((int)((num)*10))%10;
                push('.', &s);
                push(num2+'0', &s);

                num *= 10;
                num2 = ((int)((num)*10))%10;
                
                push(num2+'0', &s);

                push(' ', &s);
            }else
            {
                num2 = num;
                if(num2 > 9)
                {
                push(' ', &s);
                
                sprintf(nn, "%d", num2);
                for (int k = 0; nn[k] != '\0'; k++)
                {
                    push(nn[k], &s);
                }
                
                push(' ', &s);
                }else
                {
                    c = num2 + '0';
                    push(c, &s);
                }
            }
            
            
        }
        
    }
    if(stacktop(&s) == ' ')
    {
        pop(&c, &s);
        pop(&c, &s);
        int j = 0;
        while (c != ' ')
        {
            nn[j] = c;
            j++;
            pop(&c, &s);
        }
        for (i = j-1; i >= 0; i--)
        {
            printf("%c", nn[i]);
        }
        
        
    }else
        printf("%c\n", stacktop(&s));
    
}

int main(void)
{
    int i, j;
    char m[] = "2* 22 +3";
    
    char postfex[100];
    stack s;
    createstack(&s);
    for (i = 0, j = 0; m[i] != '\0' ; i++)
    {
        if(m[i] == ' ')
        {
            postfex[j] = m[i];
            j++;
            i++;
            while(m[i] != ' ')
            {
                postfex[j] = m[i];
                j++;
                i++;
            }
            postfex[j] = m[i];
            j++;
        }else if(ischar(m[i]))
        {
            postfex[j] = m[i];
            j++;
        }else
        {
            while ( !stackempty(&s) && ifper(stacktop(&s), m[i]) )
            {
                char a;
                postfex[j] = stacktop(&s);
                j++;
                pop(&a, &s);
            }
            
            push(m[i], &s);
        }
        


    }

    while ( !stackempty(&s))
    {
        char a;
        postfex[j] = stacktop(&s);
        j++;
        pop(&a, &s);
    }
    op(postfex);
    
    return 0;
}   