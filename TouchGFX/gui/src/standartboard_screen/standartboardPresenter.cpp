#include <gui/standartboard_screen/standartboardView.hpp>
#include <gui/standartboard_screen/standartboardPresenter.hpp>
#include "configuration.h"

standartboardPresenter::standartboardPresenter(standartboardView& v)
    : view(v)
{

}

void standartboardPresenter::activate()
{

}

void standartboardPresenter::deactivate()
{

}

void standartboardPresenter::DisplayTimeLeft(int minute)
{
	view.DisplayTimeLeft(minute);
}

void standartboardPresenter::DisplayTimeRight(int minute)
{
	view.DisplayTimeRight(minute);
}

void standartboardPresenter::DisplayTempLeft(int value)
{
	view.DisplayTempLeft(value);
}

void standartboardPresenter::DisplayTempRight(int value)
{
	view.DisplayTempRight(value);
}

void standartboardPresenter::DisplayStatusLeft(int status)
{
	view.DisplayStatusLeft(status);
}

void standartboardPresenter::DisplayStatusRight(int status)
{
	view.DisplayStatusRight(status);
}

void standartboardPresenter::StartDryLeft()
{
	model->SendLeftOn(ADDRESS_STANDART_MODE_LEFT);
}

void standartboardPresenter::StopDryLeft()
{
	model->SendLeftOff(ADDRESS_STANDART_MODE_LEFT);
}

void standartboardPresenter::StartDryRight()
{
	model->SendRightOn(ADDRESS_STANDART_MODE_RIGHT);
}

void standartboardPresenter::StopDryRight()
{
	model->SendRightOff(ADDRESS_STANDART_MODE_RIGHT);
}

void standartboardPresenter::ShowMessage(int num)
{
	view.ShowMessage(num);
}

//экстренный возврат на главный экран
void standartboardPresenter::GoToMain()
{
	view.GoToMain();
}
