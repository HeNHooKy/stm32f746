#include <gui/heatingboard_screen/heatingboardView.hpp>
#include <gui/heatingboard_screen/heatingboardPresenter.hpp>
#include "configuration.h"

heatingboardPresenter::heatingboardPresenter(heatingboardView& v)
    : view(v)
{

}

void heatingboardPresenter::activate()
{

}

void heatingboardPresenter::deactivate()
{

}

void heatingboardPresenter::DisplayTimeLeft(int minute)
{
	view.DisplayTimeLeft(minute);
}

void heatingboardPresenter::DisplayTimeRight(int minute)
{
	view.DisplayTempRight(minute);
}

void heatingboardPresenter::DisplayTempLeft(int value)
{
	view.DisplayTempLeft(value);
}

void heatingboardPresenter::DisplayTempRight(int value)
{
	view.DisplayTempRight(value);
}

void heatingboardPresenter::DisplayStatusLeft(int status)
{
	view.DisplayStatusLeft(status);
}

void heatingboardPresenter::DisplayStatusRight(int status)
{
	view.DisplayStatusRight(status);
}

void heatingboardPresenter::StartDryLeft()
{
	model->SendLeftOn(ADDRESS_FAST_MODE_LEFT);
}

void heatingboardPresenter::StopDryLeft()
{
	model->SendLeftOff(ADDRESS_FAST_MODE_LEFT);
}

void heatingboardPresenter::StartDryRight()
{
	model->SendRightOn(ADDRESS_FAST_MODE_RIGHT);
}

void heatingboardPresenter::StopDryRight()
{
	model->SendRightOff(ADDRESS_FAST_MODE_RIGHT);
}

void heatingboardPresenter::ShowMessage(char* message)
{
	view.ShowMessage(message);
}
