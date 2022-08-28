#include <iostream>
#include <cmath>
#include <valarray>
const int c_num_arguments = 2;

const double PI = 3.14159265;
int main(int argc, char *argv[])
{
    int arg[c_num_arguments];
    if (argc < 3)
    {
        std::cout << "Not enough arguments must be first User inputs:  Number of samples, 2st  Number of bits" << std::endl;
        return -1;
    }

    for (size_t i = 0; i < c_num_arguments; i++)
    {

        try
        {

            arg[i] = std::stoi(argv[i + 1]);
        }
        catch (std::invalid_argument const &ex)
        {
            std::cout << "invalid_argument" << std::endl;
            return -1;
        }
    }


    if (arg[0] < 0 || (arg[0] % 4 != 0) || arg[0] < 4)
    {
        std::cout << "invalid table size" << std::endl;
        return -1;
    }

    if (arg[1] < 2 || arg[1] > 32)
    {
        std::cout << "invalid bitsize" << std::endl;
        return -1;
    }

    double step = (2 * PI) / arg[0];
    int scale = pow(2, arg[1] - 1);

    std::valarray<double> points(arg[0]);
    for (size_t i = 0; i < arg[0]; i++)
    {
        points[i] = step * i;
    }

    std::valarray<double> sinouts = sin(points);
    for (size_t i = 0; i < arg[0]; i++)
    {
        std::cout << (int)(sinouts[i] * (scale - 1)) << std::endl;
    }

    return 0;
}