#ifndef HEATINGBOARDVIEW_HPP
#define HEATINGBOARDVIEW_HPP

#include <gui_generated/heatingboard_screen/heatingboardViewBase.hpp>
#include <gui/heatingboard_screen/heatingboardPresenter.hpp>

class heatingboardView : public heatingboardViewBase
{
public:
    heatingboardView();
    virtual ~heatingboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // HEATINGBOARDVIEW_HPP
