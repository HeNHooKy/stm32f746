#include <gui/manualboard_screen/manualboardView.hpp>
#include <gui/manualboard_screen/manualboardPresenter.hpp>
#include "configuration.h"
#include "UartController.h"

manualboardPresenter::manualboardPresenter(manualboardView& v)
    : view(v)
{

}

void manualboardPresenter::activate()
{

}

void manualboardPresenter::deactivate()
{

}

void manualboardPresenter::DisplayTimeLeft(int minute)
{
	view.DisplayTimeLeft(minute);
}

void manualboardPresenter::DisplayTimeRight(int minute)
{
	view.DisplayTimeRight(minute);
}

void manualboardPresenter::DisplayTempLeft(int value)
{
	view.DisplayTempLeft(value);
}

void manualboardPresenter::DisplayTempRight(int value)
{
	view.DisplayTempRight(value);
}

void manualboardPresenter::DisplayStatusLeft(int status)
{
	view.DisplayStatusLeft(status);
}

void manualboardPresenter::DisplayStatusRight(int status)
{
	view.DisplayStatusRight(status);
}

void manualboardPresenter::StartDryLeft(int time, int temp)
{
	model->SendLeftTemp(temp);
	model->SendLeftTime(time);
	model->SendLeftOn(ADDRESS_MANUAL_MODE_LEFT);
}

void manualboardPresenter::StopDryLeft()
{
	model->SendLeftOff(ADDRESS_MANUAL_MODE_LEFT);
}

void manualboardPresenter::StartDryRight(int time, int temp)
{
	model->SendRightTemp(temp);
	model->SendRightTime(time);
	model->SendRightOn(ADDRESS_MANUAL_MODE_RIGHT);
}

void manualboardPresenter::StopDryRight()
{
	model->SendRightOff(ADDRESS_MANUAL_MODE_RIGHT);
}


void manualboardPresenter::ShowMessage(char* message)
{
	view.ShowMessage(message);
}
