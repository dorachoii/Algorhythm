#import <ios>
int a, b, c;
main()
{
    scanf("%d%d%d", &a, &b, &c);
    puts(a + b + c - 180 ? "Error" : a == b && b == c         ? "Equilateral"
                                 : a == b || b == c || a == c ? "Isosceles"
                                                              : "Scalene");
}