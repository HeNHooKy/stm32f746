#ifndef STARTBOARDPRESENTER_HPP
#define STARTBOARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class startboardView;

class startboardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    startboardPresenter(startboardView& v);

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

    virtual ~startboardPresenter() {};


    //методы задания и проверки пользовательского времени
	int ClockChecker();
	void SetClock(int hours, int minutes, int weekDay);

private:
    startboardPresenter();

    startboardView& view;
};

#endif // STARTBOARDPRESENTER_HPP
