#include <gui/mainboard_screen/mainboardView.hpp>

mainboardView::mainboardView()
{

}

void mainboardView::setupScreen()
{
    mainboardViewBase::setupScreen();
}

void mainboardView::tearDownScreen()
{
    mainboardViewBase::tearDownScreen();
}

void mainboardView::DisplayCurrentTime(int d, int hour, int minute)
{
	RealClock.setTime24Hour(hour, minute, 0);
	SetDay(d);
	RealClock.invalidate();
}

void mainboardView::SetDay(int d)
{
	switch(d)
	{
	case 0:
		Unicode::strncpy(dayBuffer, "вс", 4);
		break;
	case 1:
		Unicode::strncpy(dayBuffer, "пн", 4);
		break;
	case 2:
		Unicode::strncpy(dayBuffer, "вт", 4);
		break;
	case 3:
		Unicode::strncpy(dayBuffer, "ср", 4);
		break;
	case 4:
		Unicode::strncpy(dayBuffer, "чт", 4);
		break;
	case 5:
		Unicode::strncpy(dayBuffer, "пт", 4);
		break;
	case 6:
		Unicode::strncpy(dayBuffer, "сб", 4);
		break;
	default:
		Unicode::strncpy(dayBuffer, "нн", 4);
	}
	day.invalidate();
}
