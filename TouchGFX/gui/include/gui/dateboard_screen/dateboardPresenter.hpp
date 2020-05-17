#ifndef DATEBOARDPRESENTER_HPP
#define DATEBOARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class dateboardView;

class dateboardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    dateboardPresenter(dateboardView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~dateboardPresenter() {};

private:
    dateboardPresenter();

    dateboardView& view;
};

#endif // DATEBOARDPRESENTER_HPP
