#include <iostream>
#include <vector>


/*
Did that make it better and why?

Although this implementation probably required less lines of codes, it actually took a lot more thought than I had anticipated. In the first homework, it was much more intuitive to me to develop the
pascal triangle without thinking about how to architect the class. However, using a class-based implementation method is definetly more scalable and would save me a significant amount of time if I were
to need to create an adaptation of this in the future.


*/

using ll = long long;


class PascalTriangle 
{
int rows;
std::vector<std::vector<ll>> triangle;


public:
    PascalTriangle(int r) : rows(r < 0 ? 0 : r) {};

    void build()
    {
        triangle.clear();
        triangle.reserve(rows);

        for (int i = 0; i < rows; ++i)
        {
            std::vector<ll> row(i + 1, 1.0);

            for (int j = 1; j < i; ++j)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
    }

    void print(std::ostream& out) const  
    {
        for (const auto& row : triangle)
        {
            for (auto val : row)
            {
                std::cout << val << ' ';
            }
            std::cout << std::endl;
        }
    }

};


int main() 
{
    int n{};
    std::cout << "Please enter the number of rows: ";
    
    if (!(std::cin >> n))
    {
        std::cout << "Invalid Output.";
        return 1;
    }

    PascalTriangle pt(n);

    pt.build();
    pt.print(std::cout);

    return 0;
}