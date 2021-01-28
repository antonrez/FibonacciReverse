#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>

int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void FibonacciLineReverse(const std::string& file_in_name, const std::string& file_out_name)
{
    std::ifstream fileIn(file_in_name);

    if (fileIn.is_open())
    {
        char line[6];
        std::vector<int> fibonache_sequence;
        int number_of_lines = 0;

        std::ofstream fileOut(file_out_name);

        if (!fileOut.is_open())
        {
            std::cout << "File not created " << file_out_name << std::endl;
        }

        for (int i = 0; i < 10; i++)
        {
            fibonache_sequence.push_back(Fibonacci(i));
        }

        while (fileIn.getline(line, 6))
        {
            ++number_of_lines;
            auto itr = std::find(fibonache_sequence.begin(), fibonache_sequence.end(), number_of_lines);

            if (itr != fibonache_sequence.end())
            {
                for (int i = 0, j = strlen(line) - 1; j >= strlen(line) / 2; ++i, --j)
                {
                    char temp = line[i];
                    line[i] = line[j];
                    line[j] = temp;
                }

                fileOut << line << '\n';
            }
        }
        fileIn.close();
        fileOut.close();
    }
    else
    {
        std::cout << "File not found " << file_in_name << std::endl;
    }
}

int main()
{
    std::string file_in_name = "source.txt";
    std::string file_out_name = "output.txt";

    FibonacciLineReverse(file_in_name, file_out_name);
}