#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int _CREATE(int _RANGE);
int _LINEIT(int qty);

int num1, num2, symb;
//全局变量，方便生成随机数被main取用
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
    int plusqty, minusqty, mathqty, taskrange, taskQTY;
    fpMath = fopen("math.txt", "w");
    //应该加一个检测的，好懒，不想加啊
    plusqty = minusqty = 0;
    taskrange = 80;
    taskQTY = 100;
    srand((unsigned)time(NULL));
    _CREATE(taskrange);
    for (mathqty = 1; mathqty <= taskQTY; mathqty++)
    {

        if (symb == 0)
        {
            if (num1 > num2)
                fprintf(fpMath, "%2d - %2d =", num1, num2);
            else
                fprintf(fpMath, "%2d - %2d =", num2, num1);
            fprintf(fpMath, "%c", _LINEIT(mathqty));
            minusqty++;
            _CREATE(taskrange);
        }
        else
        {
            if (num1 + num2 <= taskrange)
            {
                fprintf(fpMath, "%2d + %2d =", num1, num2);
                fprintf(fpMath, "%c", _LINEIT(mathqty));
                plusqty++;
                _CREATE(taskrange);
            }
            else
            {
                _CREATE(taskrange);
                symb = 1;
                mathqty--;
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

int _LINEIT(int _QTY)
{
    if (_QTY % 4 == 0)
        return 10;
    else
        return 9;
}
