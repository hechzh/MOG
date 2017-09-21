//
// Created by shanghaitech on 17-9-21.
//
#include <iostream>
#include <cmath>
#ifndef MOG_POINT2D_H
#define MOG_POINT2D_H
template <typename T>
class rotation;
template <typename T>
class point2d;
template <typename T>
class rotation{
public:
    T theta;//ni shi zhen
    T mvx;
    T mvy;
    rotation():theta(0),mvx(0),mvy(0){}
    rotation(T a,T b,T c):theta(c),mvx(std::cos(c)*a-std::sin(c)*b-a),mvy(std::sin(c)*a+std::cos(c)*b-b){}
    rotation(T a,T b,T c,T d,T e):theta(c),mvx(std::cos(c)*a-std::sin(c)*b-a+d),mvy(std::sin(c)*a+std::cos(c)*b-b+e){}
    inline rotation<T> operator*(rotation<T> other){
        rotation<T> temp(other.mvx,other.mvy,this->theta,other.mvx+this->mvx,other.mvy+this->mvy);
        temp.theta+=other.theta;
        return temp;
    }
    inline rotation<T> operator/(rotation<T> other){
        rotation<T> temp(-this->mvx,-this->mvy,this->theta - other.theta,other.mvx,other.mvy);
        return temp;
    }
    inline void operator*=(rotation<T> other){
        this->mvx+=other.x *std::cos(this->theta)- other.y *std::sin(this->theta);
        this->mvy+=other.x *std::sin(this->theta)+ other.y *std::cos(this->theta);
        this->theta+=other.theta;
    }
    inline void operator/=(rotation<T> other){
        this->theta-=other.theta;
        this->mvx-=this->x *std::cos(this->theta)- this->y *std::sin(this->theta);
        this->mvy-=this->x *std::sin(this->theta)+ this->y *std::cos(this->theta);
    }
    //bool operator==(rotation<T> other) return (theta==other.theta && mvx ==other.mvx && mvy == other.mvy);
};
template <typename T>
class point2d {
public:
    T x;
    T y;
    point2d():x(0),y(0){}
    point2d(T a,T b):x(a),y(b){}
    inline point2d<T> rotate(rotation<T> M){
        point2d<T> temp(this->x *std::cos(M.theta)- this->y *std::sin(M.theta)-M.mvx,
                        this->x *std::sin(M.theta)+ this->y *std::cos(M.theta)-M.mvy);
        return temp;
    }
};


#endif //MOG_POINT2D_H
