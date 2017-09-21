#ifndef FUNCTION_DIFFERENTIAL_LIB_FUNCTIONAUDI_H
#define FUNCTION_DIFFERENTIAL_LIB_FUNCTIONAUDI_H
#include <functional>
#include <cmath>
#define defineid(A) functionaudi::Function A;A.value=[](R x){return x;};A.der=[](R x){return 1;}
typedef double R;
typedef std::function<R(R)> func_;
namespace functionaudi{
    class Function {
    public:
        func_ value;
        func_ der;
        Function(){};
        Function operator+(Function other);
        Function operator-(Function other);
        Function operator*(Function other);
        Function operator/(Function other);
        Function operator^(Function other);
        Function operator+(R other);
        Function operator-(R other);
        Function operator*(R other);
        Function operator/(R other);
        Function operator^(R other);
        Function scalar(R scale,R move);
    };
    Function exp(Function x);
    Function sin(Function x);
    Function cos(Function x);
    Function ln(Function x);
    Function tan(Function x);
    Function cot(Function x);
    Function asin(Function x);
    Function acos(Function x);
    Function atan(Function x);
    Function acot(Function x);

    Function sinh(Function x);
    Function cosh(Function x);
    Function tanh(Function x);
    Function coth(Function x);
    Function asinh(Function x);
    Function acosh(Function x);
    Function atanh(Function x);
    Function acoth(Function x);

}


#endif //FUNCTION_DIFFERENTIAL_LIB_FUNCTIONAUDI_H
