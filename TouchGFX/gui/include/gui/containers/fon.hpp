#ifndef FON_HPP
#define FON_HPP

#include <gui_generated/containers/fonBase.hpp>

class fon : public fonBase
{
public:
    fon();
    virtual ~fon() {}

    virtual void initialize();

    void SetVisibleClosebt(bool visible);
protected:
};

#endif // FON_HPP
