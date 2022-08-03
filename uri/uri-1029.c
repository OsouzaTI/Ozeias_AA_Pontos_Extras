#include <stdio.h>

struct long_pair
{
    long f, s;
};


long _fib(int n, int* calls) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    (*calls)+=2;
    return _fib(n-1, calls) + _fib(n-2, calls); 
}

struct long_pair fib(int n){
    int calls = 0;
    long r = _fib(n, &calls);
    struct long_pair p = {calls, r};
    return p;
}


int main(void)
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        struct long_pair r = fib(n);
        printf("fib(%d) = %d calls = %d\n", n, r.f, r.s);
    }
    return 0;
}