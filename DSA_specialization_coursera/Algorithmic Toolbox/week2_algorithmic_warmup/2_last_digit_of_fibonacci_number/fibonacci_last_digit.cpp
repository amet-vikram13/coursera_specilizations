#include <iostream>
#define llu unsigned long long int

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    llu prev = 0ull;
    llu curr = 1ull;
    llu tmp;
    for(int i=2;i<=n;i++)
    {
        tmp = prev;
        prev = curr;
        curr = tmp + prev;
        curr = curr%10;
    }
    return curr;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
