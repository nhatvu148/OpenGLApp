#include <cassert>
#include <functional>
#include <iostream>
#include <string>

int square(int x)
{
    return x * x;
}

// decorate_with_logging : (String, (Int -> Int)) -> (Int -> Int)
template <typename F>
std::function<int(int)> decorate_with_logging(const std::string& str, F f)
{
    return [str, f](int x) -> int
    {
        int result = f(x);
        std::cout << str << ": " << x << " => " << result << std::endl;
        return result;
    };
}

int main()
{
    const auto logging_square =
        decorate_with_logging("Square", square);

    int a = logging_square(4);
    int b = logging_square(5);

    assert(a == 16);
    assert(b == 25);
}
