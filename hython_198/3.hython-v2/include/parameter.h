/*************************************************************************
	> File Name: parameter.h
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年09月02日 星期三 16时21分15秒
 ************************************************************************/

#ifndef _PARAMETER_H
#define _PARAMETER_H

#include <map>
#include <string>
#include <memory>

namespace haizei {

class Parameter {
public:
    Parameter();
    Parameter(std::shared_ptr<haizei::Parameter> next);
    void def_param(std::string, int);
    void set_param(std::string, int);
    int get_param(std::string);

private:
    std::map<std::string, int> memory;
    std::shared_ptr<haizei::Parameter> next;
};

} //end of namespace haizei

#endif
