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

void mainboardView::DisplayCurrentTime(int day, int hour, int minute)
{
	//TODO: отображение актуального времени
	char * displayDay = GetDay(day);
	Unicode::strncpy(dayBuffer, displayDay, 4);
	RealClock.setTime24Hour(hour, minute, 0);
	RealClock.invalidate();
	day.invalidate();
}

char * mainboardView::GetDay(int day)
{
	switch(day)
	{
	case 0:
		return {'в', 'с'};
	case 1:
		return {'п', 'н'};
	case 2:
		return {'в', 'т'};
	case 3:
		return {'c', 'р'};
	case 4:
		return {'ч', 'т'};
	case 5:
		return {'п', 'т'};
	case 6:
		return {'с', 'б'};
	default:
		return {'н', 'н'};
	}
}
