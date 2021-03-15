#include <cassert>
#include <functional>
#include <iostream>
#include <string>

int square(int x)
{
    return x * x;
}

// decorate_with_logging : (String, (Int -> Int)) -> (Int -> Int)

int main()
{
    const auto logging_square =
        decorate_with_logging("Square", square);

    int a = logging_square(4);
    int b = logging_square(5);

    assert(a == 16);
    assert(b == 25);

    // The console should show something like
    // Square: 4 => 16
    // Square: 5 => 25
}

// Exercise:
//     Implement decorate_with_logging so that
//     it works like shown above.
