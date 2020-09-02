/*************************************************************************
	> File Name: single.h
	> Author: lizhipan
	> Mail: 
	> Created Time: 2020年09月02日 星期三 09时52分55秒
 ************************************************************************/

#ifndef _SINGLE_H
#define _SINGLE_H

#include <mutex>
#include <memory>
#include <handle.h>
#include <AST.h>

namespace haizei {
class Singleton {
public:
protected:
    Singleton() = default;
    static std::mutex m_mutex;
};

//这个类来管理责任链：
//将责任链中各个节点连在一起
//并负责创建单例的责任链
//并负责给任务找到能够处理它的结点(handle)，然后再把它抛给对应的master去处理
class MasterChainSingle : public Singleton {
public:
    static int run(ASTNode, std::shared_ptr<Parameter> &);
private:
    static const haizei::IHandle *get();
    MasterChainSingle() = delete;
    static const haizei::IHandle *SingleInit();
    static const haizei::IHandle *object;
};

}

#endif
