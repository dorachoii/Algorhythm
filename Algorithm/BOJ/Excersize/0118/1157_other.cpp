#include <stdio.h>

char s[1000001];
int c[26], m, t;

int main()
{
    scanf("%s", s);

    for (int i = 0; s[i]; i++)
        c[(s[i] - 65) % 32]++;      //%32 나머지 연산으로도 대 소문자 같은지 비교 가능

    for (int i = 1; i < 26; i++)    //정렬 알고리즘
    {
        if (c[i] > c[m])
            m = i, t = 0;           //m은 크면 정렬되는 식
        else if (c[i] == c[m])
            t = 1;
    }

    if (t)
        printf("?");
    else
        printf("%c", m + 65);       //대문자 A: 65
}