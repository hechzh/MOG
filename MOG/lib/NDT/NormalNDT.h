//
// Created by shanghaitech on 17-9-25.
//

#ifndef MOG_NORMALNDT_H
#define MOG_NORMALNDT_H

#include "../point2d/point2d.h"
#include <queue>
#include <tuple>
#include <unordered_map>
typedef R double;
typedef vecp std::vector<point2d<double> >
class cell{
public:
};
class NormalNDT // the robot is suposed to be in the center
{
public:
    NormalNDT():cellsize(0.05),cellnumber(4096),xysearch(0.05),xyiter(0.01),thetasearch(0.15),theta(0.01),slidingwindow(20){}
    NormalNDT(R cs,int cn):cellsize(cs),cellnumber(cn),xysearch(0.05),xyiter(0.01),thetasearch(0.15),theta(0.01),slidingwindow(20){}
    void init(vecp observed_point,rotation<R> guess=this->pos){
        if( points.size()>slidingwindow) points.pop();
        rotation<R> change=this->optimize(rotate(observed_point,guess/pos));
        for(int i=0;i<slidingwindow;i++) points.push(rotate(points.pop(),change));
        pos*=change;
        points.push(observed_point);
        this->cellinitial();
    }
    void cellinitial();
    rotation<R> optimize(vecp ob_point);

private:
    rotation<R> pos;
    std::queue<vecp> points;
    std::unordered_map<std::tuple<R,R>,cell> cells;
    int slidingwindow;
    R cellsize;
    int cellnumber;
    R xysearch;
    R xyiter;
    R thetasearch;
    R theta;
};


#endif //MOG_NORMALNDT_H
