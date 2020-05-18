#include <gui/startboard_screen/startboardView.hpp>
#include <gui/startboard_screen/startboardPresenter.hpp>

startboardPresenter::startboardPresenter(startboardView& v)
    : view(v)
{

}

void startboardPresenter::activate()
{

}

void startboardPresenter::deactivate()
{

}

//методы задания и проверки пользовательского времени
int startboardPresenter::ClockChecker()
{
	return model-> ClockChecker();
}
void startboardPresenter::SetClock(int hours, int minutes, int weekDay)
{
	model->SetClock(hours, minutes, weekDay);
}

void startboardPresenter::GetCurTimeDay(int *day, int *hour, int *minute)
{
	model->GetCurTimeDay(day, hour, minute);
}
