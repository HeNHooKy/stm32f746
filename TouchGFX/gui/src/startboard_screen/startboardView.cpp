#include <gui/startboard_screen/startboardView.hpp>

startboardView::startboardView()
{

}


void startboardView::setupScreen()
{
    startboardViewBase::setupScreen();
    //установка акутального времени при запуске
    int day, hour, minute;
    presenter->GetCurTimeDay(&day, &hour, &minute);
    SetDay(day);
    setHours(hour);
    setMinutes(minute);
    Update();
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

	pnbt.invalidate();
	vtbt.invalidate();
	srbt.invalidate();
	chtbt.invalidate();
	ptbt.invalidate();
	sbbt.invalidate();
	vsbt.invalidate();
}

void startboardView::SetTimeDate()
{
	int hours = getHours();
	int minutes = getMinutes();
	int weekDay = 0;

	if(vsbt.getSelected())
	{
		weekDay = 0;
	}
	else if(pnbt.getSelected())
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


	presenter->SetClock(hours, minutes, weekDay);
}


//отображает на экране выбранный день
void startboardView::SetDay(int day)
{
	switch(day)
	{
	case 0:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(true);
		break;
	case 1:
		pnbt.setSelected(true);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case 2:
		pnbt.setSelected(false);
		vtbt.setSelected(true);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case 3:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(true);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case 4:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(true);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case 5:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(true);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case 6:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(true);
		vsbt.setSelected(false);
		break;

	}
}
