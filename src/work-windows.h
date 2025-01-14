#ifndef WORKWINDOWS_H
#define WORKWINDOWS_H


#include "abstract-os.h"

class WorkWindows : public AbstractOS
{
public:
    bool TerminateProc() override;
};

#endif
