#include <gui/manualboard_screen/manualboardView.hpp>
#include <gui/manualboard_screen/manualboardPresenter.hpp>

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

void manualboardPresenter::StartDryLeft(int time, int temp)
{
	model->SendLeftTemp(temp);
	//TODO: добавить отправку времени и булеан ВКЛ
}
