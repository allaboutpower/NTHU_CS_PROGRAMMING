#include<iostream>
#include<map>

using namespace std;


const std::map<std::string, int(*)(const int &, const int &)> integer_operators {
    {"add", [](const int &lhs, const int &rhs){return lhs+rhs;}},
    {"sub", [](const int &lhs, const int &rhs){return lhs-rhs;}},
    {"bitwise_and", [](const int &lhs, const int &rhs){return lhs&rhs;}},
    {"bitwise_or", [](const int &lhs, const int &rhs){return lhs|rhs;}},
    {"bitwise_xor", [](const int &lhs, const int &rhs){return lhs^rhs;}}
};


const std::map<std::string, std::string(*)(const std::string &, const std::string &)> string_operators {
    {"pre_concat", [](const string &lhs, const string &rhs){return lhs+rhs;}},
    {"post_concat", [](const string &lhs, const string &rhs){return rhs+lhs;}}
};

template<class Iterator, class OpFuncPointer>
Iterator::value_type customized_accumulate(Iterator begin, Iterator end, OpFuncPointer first_bin_op, OpFuncPointer second_bin_op) {
	auto res = *(begin++);
    bool isfirst = true;
    while(begin!=end){
        if(isfirst)res = first_bin_op(res, *begin);
        else res = second_bin_op(res,*begin);
        begin++;
        isfirst ^=true;

    }   
    return res;
}