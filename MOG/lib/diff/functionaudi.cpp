#include "functionaudi.h"
using namespace functionaudi;
Function Function::operator+(Function other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)+other.value(x);};
    answer.der=[this,other](R x){return this->der (x)+other.der(x);};
    return answer;
}
Function Function::operator-(Function other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)-other.value(x);};
    answer.der=[this,other](R x){return this->der (x)-other.der(x);};
    return answer;
}
Function Function::operator*(Function other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)*other.value(x);};
    answer.der=[this,other](R x){return this->value (x) * other.der(x) + other.value(x) * this->der(x);};
    return answer;
}
Function Function::operator/(Function other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x)/other.value(x);};
    answer.der=[this,other](R x){return (this->value (x) * other.der(x) + other.value(x) * this->der(x))/other.value(x)/other.value(x);};
    return answer;
}
Function Function::operator^(Function other){
    Function answer;
    answer.value=[this,other](R x){return std::pow(this->value (x), other.value(x));};
    answer.der= [this,other](R x){return std::pow(this->value (x) , other.value(x))*(other.der(x)*log(this->value(x))+other.value(x)*this->der(x)/this->value(x));};
    return answer;
}

Function Function::operator+(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) + other;};
    answer.der= this->der;
    return answer;
}
Function Function::operator-(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) - other;};
    answer.der= this->der;
    return answer;
}
Function Function::operator*(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) * other;};
    answer.der= [this,other](R x){return this->der (x) * other;};
    return answer;
}
Function Function::operator/(R other){
    Function answer;
    answer.value=[this,other](R x){return this->value (x) / other;};
    answer.der= [this,other](R x){return this->der (x) / other;};
    return answer;
}
Function Function::operator^(R other){
    Function answer;
    answer.value=[this,other](R x){return std::pow(this->value (x) ,other);};
    answer.der= [this,other](R x){return other*std::pow(this->value (x) , other-1) * this->der(x);};
    return answer;
}
Function Function::scalar(R scale,R move){
    this->value = [this,scale,move](R x){ return scale*this->value(x) +move;};
    this->der = [this,scale,move](R x){ return scale*this->der(x); };
}

Function functionaudi::exp(Function y){
    Function answer;
    answer.value=[y](R x){return std::exp(y.value(x));};
    answer.der=[y](R x){return y.der(x)*std::exp(y.value(x));};
    return answer;
}

Function functionaudi::sin(Function y){
    Function answer;
    answer.value=[y](R x){return std::sin(y.value(x));};
    answer.der=[y](R x){return y.der(x)*std::cos(y.value(x));};
    return answer;
}
Function functionaudi::cos(Function y){
    Function answer;
    answer.value=[y](R x){return std::cos(y.value(x));};
    answer.der=[y](R x){return -y.der(x)*std::sin(y.value(x));};
    return answer;
}
Function functionaudi::ln(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::log(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / y.value(x); };
    return answer;
}
Function functionaudi::tan(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::tan(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / std::pow(std::cos(y.value(x)),2); };
    return answer;
}
Function functionaudi::cot(Function y) {
    Function answer;
    answer.value = [y](R x) { return 1 / std::tan(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / std::pow(std::sin(y.value(x)),2); };
    return answer;
}
Function functionaudi::asin(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::asin(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / std::sqrt( 1 - std::pow(y.value(x),2)); };
    return answer;
}
Function functionaudi::acos(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::acos(y.value(x)); };
    answer.der = [y](R x) { return -y.der(x) / std::sqrt( 1 - std::pow(y.value(x),2)); };
    return answer;
}
Function functionaudi::atan(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::atan(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / ( 1 + std::pow(y.value(x),2)); };
    return answer;
}
Function functionaudi::acot(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::atan(1/y.value(x)); };
    answer.der = [y](R x) { return -y.der(x) / ( 1 + std::pow(y.value(x),2)); };
    return answer;
}
Function functionaudi::sinh(Function y) {
    Function answer;
    answer.value = [y](R x) { return std::sinh(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) * std::cosh(y.value(x)); };
    return answer;
}
Function functionaudi::cosh(Function y){
    Function answer;
    answer.value = [y](R x) { return std::cosh(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) * std::sinh(y.value(x)); };
    return answer;
}
Function functionaudi::tanh(Function y){
    Function answer;
    answer.value = [y](R x) { return std::tanh(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) /pow( std::cosh(y.value(x)),2); };
    return answer;
}
Function functionaudi::coth(Function y){
    Function answer;
    answer.value = [y](R x) { return 1/std::tanh(y.value(x)); };
    answer.der = [y](R x) { return -y.der(x) /pow( std::sinh(y.value(x)),2); };
    return answer;
}
Function functionaudi::asinh(Function y){
    Function answer;
    answer.value = [y](R x) { return std::asinh(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / std::sqrt( 1 + std::pow(y.value(x),2)); };
    return answer;
}
Function functionaudi::acosh(Function y){
    Function answer;
    answer.value = [y](R x) { return std::acosh(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / std::sqrt( std::pow(y.value(x),2) -1); };
    return answer;
}
Function functionaudi::atanh(Function y){
    Function answer;
    answer.value = [y](R x) { return std::atanh(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / ( 1 - std::pow(y.value(x),2)); };
    return answer;
}
Function functionaudi::acoth(Function y){
    Function answer;
    answer.value = [y](R x) { return std::atanh(y.value(x)); };
    answer.der = [y](R x) { return y.der(x) / ( 1 - std::pow(y.value(x),2)); };
    return answer;
}