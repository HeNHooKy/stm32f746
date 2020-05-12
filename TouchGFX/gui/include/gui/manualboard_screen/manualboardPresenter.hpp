#ifndef MANUALBOARDPRESENTER_HPP
#define MANUALBOARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class manualboardView;

class manualboardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    manualboardPresenter(manualboardView& v);

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
    virtual void StartDryLeft(int time, int temp);

    virtual ~manualboardPresenter() {};

private:
    manualboardPresenter();

    manualboardView& view;
};

#endif // MANUALBOARDPRESENTER_HPP
