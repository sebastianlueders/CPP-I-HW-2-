/*
Citations:

https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution.html?utm_source=chatgpt.com
https://www.geeksforgeeks.org/cpp/accumulate-and-partial_sum-in-c-stl-numeric-header/


*/



#include <iostream>
#include <random>
#include <limits>
#include <vector>
#include <format>
#include <algorithm>
#include <cmath>
#include <numeric>

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

double sQAndAcc(double acc, double x)
{
    return acc + x * x;
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
    // std::vector<double> squares = std::vector<double>(n);

    // std::transform(src.cbegin(), src.cend(), squares.begin(), sQr);

    
    double eucDist = std::sqrt(std::accumulate(src.begin(), src.end(), 0.0, sQAndAcc));

    std::cout << std::format("Euclidean Length of this {}-Dimensional Vector: {}\n", n, eucDist);

    return 0;
}