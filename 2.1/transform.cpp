/*
Citations:

https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution.html?utm_source=chatgpt.com


*/



#include <iostream>
#include <random>
#include <limits>
#include <vector>
#include <format>

void populateVector(std::vector<double>& v, const int len)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Picks random double values between -1000.0 and 1000
    std::uniform_real_distribution<double> dist(-1000.0, 1000.0);

    for (int i = 0; i < len; ++i)
    {  
        v[i] = dist(gen);
    }
}

double sQr(double val)
{
    return val * val;
}

int main() 
{

    // Generate random vector size between 0 and 100
    std::random_device rd;
    std::mt19937 gen(rd());


    std::uniform_int_distribution<int> dist(0, 100);

    int n = dist(gen);

    std::vector<double> src = std::vector<double>(n);


    populateVector(src, n);


    // Run transform operation
    std::vector<double> squares = std::vector<double>(n);

    std::transform(src.cbegin(), src.cend(), squares.begin(), sQr);

    bool allPassed = true;
    // Verify correctness
    for (int i = 0; i < n; ++i)
    {
        std::cout << std::format("SRC value: {} | SQUARES value: {} | ACTUAL SRC^2: {}\n", src[i], squares[i], src[i] * src[i]);
        if (std::fabs(squares[i] - src[i] * src[i]) < 1e-9) { std::cout << std::format("Element {} in the squares vector matches the expected value!\n", i); }
        else bool allPassed = false;
    }

    if (allPassed) std::cout << std::endl << "Transform Operation Successful!\n";
    else std::cout << std::endl << "Transform Operation Failed!\n";

    return 0;
}