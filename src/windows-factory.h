#ifndef WINDOWSFACTORY_H
#define WINDOWSFACTORY_H


#include "os-factory.h"
#include "work-windows.h"
#include <memory>

class WindowsFactory : public OSFactory
{
public:
    std::unique_ptr<AbstractOS> CreateInstance() override;

    virtual ~WindowsFactory() = default;
};

#endif