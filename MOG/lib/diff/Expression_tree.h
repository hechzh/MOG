#ifndef FUNCTION_DIFFERENTIAL_LIB_EXPRESSION_TREE_H
#define FUNCTION_DIFFERENTIAL_LIB_EXPRESSION_TREE_H
#include <vector>
#include <map>
#include "functionaudi.h"
std::vector<int> merge(std::vector<int> a,std::vector<int> b);
enum op{addop,minusop,multipleop,divisionop,powop,noneop};
class Basic_Expression_tree {
public:
    func_ express;
    Basic_Expression_tree* lchild;
    Basic_Expression_tree* rchild;
    std::vector<int> related_tags;
    Basic_Expression_tree(Basic_Expression_tree* node1= nullptr,Basic_Expression_tree* node2= nullptr);
    virtual R computevalue()=0 ;
};
class function_expression_tree: public Basic_Expression_tree{
public:
    R value;
    op opt=op::noneop;
    std::map<int,function_expression_tree> findchilds();
    R computevalue();
};
class Function_Expression_tree: public Basic_Expression_tree{
public:
    functionaudi::Function composer;
    R computevalue();
    std::map<int,function_expression_tree> diff();
};

#endif //FUNCTION_DIFFERENTIAL_LIB_EXPRESSION_TREE_H
