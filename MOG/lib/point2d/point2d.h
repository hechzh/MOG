//
// Created by shanghaitech on 17-9-21.
//
#include <iostream>
#include <cmath>
#ifndef MOG_POINT2D_H
#define MOG_POINT2D_H
template <typename T>
class rotation{
public:
    T x;
    T y;
    T theta;//ni shi zhen
    T mvx;
    T mvy;
    rotation():x(0),y(0),theta(0),mvx(0),mvy(0){}
    rotation(T a,T b,T c):x(a),y(b),theta(c),mvx(0),mvy(0){}
    rotation(T a,T b,T c,T d,T e):x(a),y(b),theta(c),mvx(d),mvy(e){}
};
template <typename T>
class point2d {
public:
    T x;
    T y;
    point2d():x(0),y(0){}
    point2d(T a,T b):x(a),y(b){}
    inline point2d<T> rotate(rotation<T> M){
        point2d<T> temp((this->x-M.x)*std::cos(M.theta)-(this->y-M.y)*std::sin(M.theta)+M.x-M.mvx,
                        (this->x-M.x)*std::sin(M.theta)+(this->y-M.y)*std::cos(M.theta)+M.y-M.mvy);
        return temp;
    }
};


#endif //MOG_POINT2D_H
