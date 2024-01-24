#import <iostream>
int N, K, i, j;
main()
{
    for (std::cin >> N >> K; i < N && j < K; j += N % ++i ? 0 : 1)
        ;
    printf("%d", K > j ? 0 : i);
}