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
		Unicode::strncpy(dayBuffer, text1.getVsBuf(), 10);
		break;
	case 1:
		Unicode::strncpy(dayBuffer, text1.getPnBuf(), 10);
		break;
	case 2:
		Unicode::strncpy(dayBuffer, text1.getVtBuf(), 10);
		break;
	case 3:
		Unicode::strncpy(dayBuffer, text1.getSrBuf(), 10);
		break;
	case 4:
		Unicode::strncpy(dayBuffer, text1.getChtBuf(), 10);
		break;
	case 5:
		Unicode::strncpy(dayBuffer, text1.getPtBuf(), 10);
		break;
	case 6:
		Unicode::strncpy(dayBuffer, text1.getSbBuf(), 10);
		break;
	default:
		Unicode::strncpy(dayBuffer, "??", 10);
	}
	day.invalidate();
}
