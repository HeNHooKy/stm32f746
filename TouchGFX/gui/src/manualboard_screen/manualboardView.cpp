#include <gui/manualboard_screen/manualboardView.hpp>

manualboardView::manualboardView()
{
	UpdateLeft();
	UpdateRight();
}

void manualboardView::setupScreen()
{
    manualboardViewBase::setupScreen();
}

void manualboardView::tearDownScreen()
{
    manualboardViewBase::tearDownScreen();
}


void manualboardView::HoursDownLeft()
{
	setHoursLeft(getHoursLeft() - 1);
	UpdateLeft();

}
void manualboardView::HoursUpLeft()
{
	setHoursLeft(getHoursLeft() + 1);
	UpdateLeft();

}
void manualboardView::MinutesDownLeft()
{
	setMinutesLeft(getMinutesLeft() - 1);
	UpdateLeft();

}
void manualboardView::MinutesUpLeft()
{
	setMinutesLeft(getMinutesLeft() + 1);
	UpdateLeft();
}



void manualboardView::HoursDownRight()
{
	setHoursRight(getHoursRight() - 1);
	UpdateRight();
}
void manualboardView::HoursUpRight()
{
	setHoursRight(getHoursRight() + 1);
	UpdateRight();
}
void manualboardView::MinutesDownRight()
{
	setMinutesRight(getMinutesRight() - 1);
	UpdateRight();
}
void manualboardView::MinutesUpRight()
{
	setMinutesRight(getMinutesRight() + 1);
	UpdateRight();
}

void manualboardView::UpdateLeft()
{
	Unicode::snprintf(timerHoursLeftBuffer, 10, "%d", getHoursLeft());
	timerHoursLeft.invalidate();
	Unicode::snprintf(timerMinutesLeftBuffer, 10, "%d", getMinutesLeft());
	timerMinutesLeft.invalidate();
}

void manualboardView::UpdateRight()
{
	Unicode::snprintf(timerHoursRightBuffer, 10, "%d", getHoursRight());
	timerHoursRight.invalidate();
	Unicode::snprintf(timerMinutesRightBuffer, 10, "%d", getMinutesRight());
	timerMinutesRight.invalidate();
}

void manualboardView::ChangeTempLeft(int value)
{
	setTempLeft(value);
	Unicode::snprintf(tempLeftIndBuffer, 10, "%d", getTempLeft());
	tempLeftInd.invalidate();
}

void manualboardView::ChangeTempRight(int value)
{
	setTempRight(value);
	Unicode::snprintf(tempRightIndBuffer, 10, "%d", getTempRight());
	tempRightInd.invalidate();
}

void manualboardView::StartDryLeft()
{
	int time = (getHoursRight()*60 + getMinutesRight()) * 60 * 10; //у.е. времени = 100мс
	int temp = getTempLeft();
	presenter->StartDryLeft(time, temp);
}

void manualboardView::uartMsgRdy(int value)
{
	setHoursLeft(value);
	UpdateLeft();
}
