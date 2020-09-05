/*************************************************************************
	> File Name: parameter.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 三  9/ 2 16:20:38 2020
 ************************************************************************/

#ifndef _PARAMETER_H
#define _PARAMETER_H

#include <map>
#include <string>
#include <value.h>

namespace haizei {

class Parameter {
public :
    Parameter(std::shared_ptr<Parameter> next);
    void def_param(std::string, SIValue);
    void set_param(std::string, SIValue);
    std::shared_ptr<IValue> get_param(std::string);
    
private: 
    std::map<std::string, std::shared_ptr<IValue> > memory;
    std::shared_ptr<Parameter> next;
};

} // end of namespace haizei

#endif
