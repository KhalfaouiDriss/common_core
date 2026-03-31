#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <iomanip>
# include <cmath>

class ScalarConverter {
private:
    ScalarConverter();
public:
    static void convert(const std::string &literal);
};
#endif