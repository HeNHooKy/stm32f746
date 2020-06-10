#include <gui/dateboard_screen/dateboardView.hpp>
#include <gui/dateboard_screen/dateboardPresenter.hpp>
#include "configuration.h"

dateboardPresenter::dateboardPresenter(dateboardView& v)
    : view(v)
{

}

void dateboardPresenter::activate()
{

}

void dateboardPresenter::deactivate()
{

}

//передача флага
void dateboardPresenter::SetDryEventsFlag(bool flag)
{
	model->SetDryEventsFlag(flag);
}

void dateboardPresenter::StopDryRight()
{
	model->SendRightOff(ADDRESS_MANUAL_MODE_RIGHT);
}

void dateboardPresenter::StopDryLeft()
{
	model->SendLeftOff(ADDRESS_MANUAL_MODE_LEFT);
}

void dateboardPresenter::DisplayTimeLeft(int minute)
{
	view.DisplayTimeLeft(minute);
}

void dateboardPresenter::DisplayTimeRight(int minute)
{
	view.DisplayTimeRight(minute);
}

void dateboardPresenter::DisplayTempLeft(int value)
{
	view.DisplayTempLeft(value);
}

void dateboardPresenter::DisplayTempRight(int value)
{
	view.DisplayTempRight(value);
}

void dateboardPresenter::DisplayStatusLeft(int status)
{
	view.DisplayStatusLeft(status);
}

void dateboardPresenter::DisplayStatusRight(int status)
{
	view.DisplayStatusRight(status);
}

void dateboardPresenter::ShowMessage(int num)
{
	view.ShowMessage(num);
}

//экстренный возврат на главный экран
void dateboardPresenter::GoToMain()
{
	view.GoToMain();
}

