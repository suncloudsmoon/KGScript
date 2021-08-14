#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "operators/lang_operators.h"
#include "../functions.h"

int lang_operator(char *s)
{
    int i = 0, j = 0;
    for (i = 0; i < strlen(operators); i++)
    {
        for (j = 0; j < strlen(s); j++)
        {
            if (operators[i] == s[j])
            {
                int k;
                int output = 0;
                switch (operators[i])
                {
                    case '+':
                        for (k = 0; k < strgnl(s, '+') + 1; k++)
                        {
                            output += atoi(strgn(s, '+', k));
                        }
                        return output;
                    case '-':
                        output = atoi(strgn(s, '-', 0));
                        for (k = 0; k < strgnl(s, '-'); k++)
                        {
                            output -= atoi(strgn(s, '-', k + 1));
                        }
                        return output;
                    case '*':
                        output = atoi(strgn(s, '*', 0));
                        for (k = 0; k < strgnl(s, '*'); k++)
                        {
                            output *= atoi(strgn(s, '*', k + 1));
                        }
                        return output;
                    case '/':
                        output = atoi(strgn(s, '/', 0));
                        for (k = 0; k < strgnl(s, '/'); k++)
                        {
                            output /= atoi(strgn(s, '/', k + 1));
                        }
                        return output;
                    case '^':
                        output = atoi(strgn(s, '^', 0));
                        for (k = 0; k < strgnl(s, '^'); k++)
                        {
                            output = pow(output, atoi(strgn(s, '^', k + 1)));
                        }
                        return output;
                }
            }
        }
    }
}