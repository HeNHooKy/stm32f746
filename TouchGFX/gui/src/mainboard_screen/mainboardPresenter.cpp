#include <gui/mainboard_screen/mainboardView.hpp>
#include <gui/mainboard_screen/mainboardPresenter.hpp>

mainboardPresenter::mainboardPresenter(mainboardView& v)
    : view(v)
{

}

void mainboardPresenter::activate()
{

}

void mainboardPresenter::deactivate()
{

}

void mainboardPresenter::DisplayCurrentTime(int day, int hour, int minute)
{
	view.DisplayCurrentTime(day, hour, minute);
}
