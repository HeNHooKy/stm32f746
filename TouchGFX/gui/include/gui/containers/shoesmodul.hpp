#ifndef SHOESMODUL_HPP
#define SHOESMODUL_HPP

#include <gui_generated/containers/shoesmodulBase.hpp>

class shoesmodul : public shoesmodulBase
{
public:
    shoesmodul();
    virtual ~shoesmodul() {}

    virtual void initialize();

    virtual void ChangeTemp(int value);
    virtual void ChangeTime(int value);
    virtual void StopDry();

    void setAction(GenericCallback< shoesmodul& >& callback);

protected:
    GenericCallback< shoesmodul& >* viewCallback;
};

#endif // SHOESMODUL_HPP
