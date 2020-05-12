#ifndef STANDARTBOARDVIEW_HPP
#define STANDARTBOARDVIEW_HPP

#include <gui_generated/standartboard_screen/standartboardViewBase.hpp>
#include <gui/standartboard_screen/standartboardPresenter.hpp>

class standartboardView : public standartboardViewBase
{
public:
    standartboardView();
    virtual ~standartboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STANDARTBOARDVIEW_HPP
