#include "abstract-os.h"

class WorkLinux : public AbstractOS
{
public:
    bool TerminateProc() override;
};
