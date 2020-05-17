#ifndef DRESSMODUL_HPP
#define DRESSMODUL_HPP

#include <gui_generated/containers/dressmodulBase.hpp>

class dressmodul : public dressmodulBase
{
public:
    dressmodul();
    virtual ~dressmodul() {}

    virtual void initialize();

    virtual void ChangeTemp(int value);
    virtual void ChangeTime(int value);
    virtual void StopDry();

    void setAction(GenericCallback< dressmodul& >& callback);
protected:
    GenericCallback< dressmodul& >* viewCallback;
};

#endif // DRESSMODUL_HPP
