#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int _CREATE(int _RANGE);
//int MAX(int x, int y);

int num1, num2, symb;
int _CREATE(int _RANGE)
{
    symb = rand() % 2;
    num1 = rand() % (_RANGE + 1);
    num2 = rand() % (_RANGE + 2);
    //printf("symb=%d, num1=%d, num2=%d\n", symb, num1, num2);
    return 1;
}

int main()
{
    FILE *fpMath;
    int plusqty, minusqty, _qty, range, taskQTY;
    fpMath = fopen("math.txt", "w");
    plusqty = minusqty = 0;
    range = 80;
    taskQTY = 100;
    srand((unsigned)time(NULL));
    _CREATE(range);
    for (_qty = 1; _qty <= taskQTY; _qty++)
    {

        if (symb == 0)
        {
            if (num1 > num2)
                fprintf(fpMath, "%d - %d =\n", num1, num2);
            else
                fprintf(fpMath, "%d - %d =\n", num2, num1);
            minusqty++;
            _CREATE(range);
        }
        else
        {
            if (num1 + num2 <= 100)
            {
                fprintf(fpMath, "%d + %d =\n", num1, num2);
                plusqty++;
                _CREATE(range);
            }
            else
            {
                _CREATE(range);
                symb = 1;
                _qty--;
                //在两随机数相加的结果大于范围range的时候
                //再生成一组随机数，使symb=1强制设置为加法
                //并减少一次循环量
            }
        }
    }
    printf("+=%d -=%d\n", plusqty, minusqty);
    fclose(fpMath);
    getchar();
}
