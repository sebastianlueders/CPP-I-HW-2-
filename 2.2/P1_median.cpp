#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <format>

/*
Citations:


*/

int main()
{

    int n{};
    std::cout << "Enter the number of elements (integer): ";

    if (!(std::cin >> n)) {
        std::cerr << "Invalid input: expected an integer.\n";
        return 1;
    }

    if (n < 0) 
    {
        n = 0;
        std::cout << "Input invalid, number of elements set to zero.\n";
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    // Picks random double values between -1000.0 and 1000
    std::uniform_real_distribution<double> dist(-1000.0, 1000.0);

    std::vector<double> v = std::vector<double>(n);

    std::cout << "Vector Generated (See Below):\n";
    if (n > 0) std::cout << "[";
    else std::cout << "[]";
    // Generate n random double values in given range
    for (int i = 0; i < n; ++i)
    {  
        v[i] = dist(gen);
        if (i < n - 1) std::cout << std::format("{}, ", v[i]);
        else std::cout << std::format("{}]\n", v[i]);
    }

    if (n == 0) 
    {
        std::cout << "No median for an empty set.\n";
        return 0;
    }

    std::sort(v.begin(), v.end());

    if (n % 2 == 0) std::cout << std::format("Median: {}\n", (v[n/2] + v[n/2 - 1]) / 2.0);

    else std::cout << std::format("Median: {}\n", v[n/2]);


    return 0;
}