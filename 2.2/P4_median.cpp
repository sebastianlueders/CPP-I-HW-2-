
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <format>

/*
Citations:

https://www.geeksforgeeks.org/cpp/stdpartial_sort-in-cpp/
https://medium.com/@sagar.necindia/c-20-abbreviated-function-templates-a-modern-approach-to-generic-programming-ff98e4f5316c

*/


double median(std::vector<auto> v)
{
    if (v.empty()) return 0.0;

    std::sort(v.begin(), v.end());

    auto mid1 = v[v.size() / 2];

    if (v.size() % 2 == 0)
    {
        auto mid2 = v[(v.size() - 1) / 2];

        return (mid1 + mid2) / 2.0;
    }

    return mid1;


}