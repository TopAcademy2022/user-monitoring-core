#ifndef OSFACTORY_H
#define OSFACTORY_H

#include "abstract-os.h"
#include <memory>

class OSFactory
{
public:
    virtual std::unique_ptr<AbstractOS> CreateInstance();
};

#endif