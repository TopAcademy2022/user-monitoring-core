#ifndef IWORKOS_H
#define IWORKOS_H

class IWorkOS
{
public:
    virtual bool TerminateProc() = 0;

    virtual ~IWorkOS() = default;
};

#endif