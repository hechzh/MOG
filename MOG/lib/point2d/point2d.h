#include <iostream>
#include <cmath>
#include <vector>
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
        rotation<T> temp(-other.mvx,-other.mvy,this->theta - other.theta,-other.mvx+this->mvx,-other.mvy+this->mvy);
        return temp;
    }
    inline void operator*=(rotation<T> other){
        this->mvx+=other.mvx *std::cos(this->theta)- other.mvy *std::sin(this->theta);
        this->mvy+=other.mvx *std::sin(this->theta)+ other.mvy *std::cos(this->theta);
        this->theta+=other.theta;
    }
    inline void operator/=(rotation<T> other){
        this->theta-=other.theta;
        this->mvx-=other.mvx *std::cos(this->theta)- other.mvy *std::sin(this->theta);
        this->mvy-=other.mvx *std::sin(this->theta)+ other.mvy *std::cos(this->theta);
    }
    inline bool operator==(rotation<T> other) {
        return this->theta==other.theta && this->mvx ==other.mvx && this->mvy == other.mvy;
    }
    inline T l1norm(){
        return std::abs(this->theta)+std::abs(this->mvx)+std::abs(this->mvy);
    }
    void print(){
        std::cout<<"theta:"<<this->theta<<std::endl;
        std::cout<<"mvx:"<<this->mvx<<std::endl;
        std::cout<<"mvy:"<<this->mvy<<std::endl;
    }
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

template <typename T>
std::vector<point2d<T> > rotate(std::vector<point2d<T> > origin,rotation<T> move){
    int size=origin.size();
    std::vector<point2d<T> > answer(size);
    for(int i=0;i<size;i++) answer[i]=origin[i].rotate(move);
    return answer;
}

template <typename T>
std::vector<point2d<T> > transform(std::vector<T> distance, T range_min, T range_max){
    int size=distance.size()-1;
    std::vector<point2d<T> > answer(size+1);
    for(int i=0;i<size+1;i++){
        T range=((size-i)*range_min+i*range_max)/size;
        answer[i]=point2d<T>(std::sin(range)*distance[i],std::cos(range)*distance[i]);
    }
    return answer;
}

#endif //MOG_POINT2D_H
