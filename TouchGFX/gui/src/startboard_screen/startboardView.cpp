#include <gui/startboard_screen/startboardView.hpp>

startboardView::startboardView()
{

}

void startboardView::setupScreen()
{
    startboardViewBase::setupScreen();
}

void startboardView::tearDownScreen()
{
    startboardViewBase::tearDownScreen();
}

void startboardView::HoursDown()
{
	setHours(getHours() - 1);
	Update();
}

void startboardView::HoursUp()
{
	setHours(getHours() + 1);
	Update();
}

void startboardView::MinutesDown()
{
	setMinutes(getMinutes() - 1);
	Update();
}

void startboardView::MinutesUp()
{
	setMinutes(getMinutes() + 1);
	Update();
}

void startboardView::Update()
{
	Unicode::snprintf(timerHoursBuffer, 10, "%02d", getHours());
	timerHours.invalidate();

	Unicode::snprintf(timerMinutesBuffer, 10, "%02d", getMinutes());
	timerMinutes.invalidate();
}

void startboardView::SetTimeDate()
{
	int hours = getHours();
	int minutes = getMinutes();
	int weekDay = 0;

	if(pnbt.getSelected())
	{
		weekDay = 1;
	}
	else if(vtbt.getSelected())
	{
		weekDay = 2;
	}
	else if(srbt.getSelected())
	{
		weekDay = 3;
	}
	else if(chtbt.getSelected())
	{
		weekDay = 4;
	}
	else if(ptbt.getSelected())
	{
		weekDay = 5;
	}
	else if(sbbt.getSelected())
	{
		weekDay = 6;
	}
	else
	{
		weekDay = 7;
	}

	presenter->SetClock(hours, minutes, weekDay);
}
