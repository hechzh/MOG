#include "Expression_tree.h"
std::vector<int> merge(std::vector<int> a,std::vector<int> b){
    std::vector<int> answer;
    std::vector<int>::iterator i=a.begin(),j=b.begin();
    while(i!=a.end()&&j!=b.end()){
        if((*i)==(*j)) {
            answer.push_back(*i);
            i++;j++;
        }
        else if((*i)>(*j)) answer.push_back(*j++);
        else answer.push_back(*i++);
    }
    while(i!=a.end()) answer.push_back(*i++);
    while(j!=b.end()) answer.push_back(*j++);
    return answer;
}
Basic_Expression_tree::Basic_Expression_tree(Basic_Expression_tree* node1,Basic_Expression_tree* node2):
lchild(node1),rchild(node2){
    related_tags=merge((*node1).related_tags,(*node2).related_tags);
}
std::map<int,function_expression_tree> function_expression_tree::findchilds(){

}
R function_expression_tree::computevalue() {
if(lchild!= nullptr || rchild!= nullptr){
    if (lchild== nullptr) return  rchild->computevalue();
    else if (rchild== nullptr) return  lchild->computevalue();
    else {
        if (opt==addop) return lchild->computevalue()+rchild->computevalue();
        if (opt==minusop) return lchild->computevalue()-rchild->computevalue();
        if (opt==multipleop) return lchild->computevalue()*rchild->computevalue();
        if (opt==divisionop) return lchild->computevalue()/rchild->computevalue();
    }
}else return this->value;
}

std::map<int,function_expression_tree> Function_Expression_tree::diff(){

}
