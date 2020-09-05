/*************************************************************************
	> File Name: value.h
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 四  9/ 3 09:57:04 2020
 ************************************************************************/

#ifndef _VALUE_H
#define _VALUE_H

#include <string>
#include <memory>

namespace haizei {

class IValue;
class IntValue;
class FloatValue;
class StringValue;

typedef std::shared_ptr<IValue> SIValue;
extern SIValue HZNULL;
extern SIValue HZTrue;
extern SIValue HZFalse;



class IValue {
public :
    virtual std::string toString() = 0;
    virtual bool isTrue() const = 0;
    bool isFalse() const;
    virtual bool little_compare(IntValue &);
    virtual bool little_compare(FloatValue &);
    virtual bool little_compare(StringValue &);
    virtual bool re_little_compare(IValue &) = 0;
    bool operator<(IValue &);
    bool operator>(IValue &);
    bool operator==(IValue &);
    bool operator!=(IValue &);
    bool operator<=(IValue &);
    bool operator>=(IValue &);

    virtual SIValue operator+(IValue &);
    virtual SIValue operator-(IValue &);
    virtual SIValue operator*(IValue &);
    virtual SIValue operator/(IValue &);
    virtual SIValue operator%(IValue &);
};



template<typename T>
class BaseValue : public IValue {
public :
    BaseValue(T val) : __val(val) {}
    virtual std::string toString() {
        return std::to_string(__val);
    }
    virtual bool isTrue() {
        if (__val) return true;
        return false;
    }
    T val() const { return __val; }
protected:
    T __val;
};

class IntValue : public BaseValue<int> {
public :
    IntValue(int);
    virtual bool re_little_compare(IValue &);
    virtual bool little_compare(IntValue &);
    virtual bool little_compare(FloatValue &);
    
    virtual SIValue operator+(IValue &);
    virtual SIValue operator-(IValue &);
    virtual SIValue operator*(IValue &);
    virtual SIValue operator/(IValue &);
    virtual SIValue operator%(IValue &);
};

class FloatValue : public BaseValue<double> {
public :
    FloatValue(double);
    virtual bool re_little_compare(IValue &);
    virtual bool little_compare(IntValue &);
    virtual bool little_compare(FloatValue &);
    
    virtual SIValue operator+(IValue &);
    virtual SIValue operator-(IValue &);
    virtual SIValue operator*(IValue &);
    virtual SIValue operator/(IValue &);
    virtual SIValue operator%(IValue &);
};

class StringValue : public BaseValue<std::string> {
public :
    StringValue(std::string);
    virtual bool isTrue() const;
    virtual bool re_little_compare(IValue &);
    virtual bool little_compare(StringValue &);
    
    virtual SIValue operator+(IValue &);
    virtual SIValue operator-(IValue &);
    virtual SIValue operator*(IValue &);
    virtual SIValue operator/(IValue &);
    virtual SIValue operator%(IValue &);
};


} // end of namespace haizei

#endif
