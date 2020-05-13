#ifndef MAINBOARDVIEW_HPP
#define MAINBOARDVIEW_HPP

#include <gui_generated/mainboard_screen/mainboardViewBase.hpp>
#include <gui/mainboard_screen/mainboardPresenter.hpp>

class mainboardView : public mainboardViewBase
{
public:
    mainboardView();
    virtual ~mainboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINBOARDVIEW_HPP