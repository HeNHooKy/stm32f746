#ifndef CLEARBOX_HPP
#define CLEARBOX_HPP

#include <gui_generated/containers/clearboxBase.hpp>

class clearbox : public clearboxBase
{
public:
    clearbox();
    virtual ~clearbox() {}

    virtual void initialize();
    virtual void Close();
protected:
};

#endif // CLEARBOX_HPP
