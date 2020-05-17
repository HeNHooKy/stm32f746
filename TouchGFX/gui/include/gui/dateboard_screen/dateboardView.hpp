#ifndef DATEBOARDVIEW_HPP
#define DATEBOARDVIEW_HPP

#include <gui_generated/dateboard_screen/dateboardViewBase.hpp>
#include <gui/dateboard_screen/dateboardPresenter.hpp>

class dateboardView : public dateboardViewBase
{
public:
    dateboardView();
    virtual ~dateboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DATEBOARDVIEW_HPP
