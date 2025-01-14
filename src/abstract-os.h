#ifndef ABSTRACTOS_H
#define ABSTRACTOS_H


#include "iwork-os.h"

class AbstractOS : public IWorkOS
{
public:
    virtual ~AbstractOS() = default; 
};

#endif