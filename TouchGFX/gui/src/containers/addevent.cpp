#include <gui/containers/addevent.hpp>

addevent::addevent() : viewCallback(0)
{

}

void addevent::initialize()
{
    addeventBase::initialize();
    ResetData();
}

void addevent::setAction(GenericCallback< addevent& >& callback)
{
	viewCallback = &callback;
}

void addevent::AddNewEvent()
{
	setDay();
	this->setVisible(false);
	this->invalidate();
	Add();
}

void addevent::Add()
{
	if (viewCallback->isValid())
	{
		viewCallback->execute(*this);
	}
}

void addevent::ResetData()
{
	setHoursBottom(8);
	setHoursTop(8);
	setHoursLeft(12);
	setMinutesLeft(0);
	UpdateLeft();
	UpdateRight();
}

void addevent::Close()
{
	this->setVisible(false);
	this->invalidate();
	ResetData();
}

//Управление клавишами
void addevent::HoursDownLeft()
{
	setHoursLeft(getHoursLeft() - 1);
	UpdateLeft();

}
void addevent::HoursUpLeft()
{
	setHoursLeft(getHoursLeft() + 1);
	UpdateLeft();

}
void addevent::MinutesDownLeft()
{
	setMinutesLeft(getMinutesLeft() - 1);
	UpdateLeft();

}
void addevent::MinutesUpLeft()
{
	setMinutesLeft(getMinutesLeft() + 1);
	UpdateLeft();
}



void addevent::HoursDownTop()
{
	setHoursTop(getHoursTop() - 1);
	UpdateRight();
}
void addevent::HoursUpTop()
{
	setHoursTop(getHoursTop() + 1);
	UpdateRight();
}
void addevent::HoursDownBottom()
{
	setHoursBottom(getHoursBottom() - 1);
	UpdateRight();
}
void addevent::HoursUpBottom()
{
	setHoursBottom(getHoursBottom() + 1);
	UpdateRight();
}

void addevent::UpdateLeft()
{
	Unicode::snprintf(timerHoursLeftBuffer, 10, "%02d", getHoursLeft());
	timerHoursLeft.invalidate();
	Unicode::snprintf(timerMinutesLeftBuffer, 10, "%02d", getMinutesLeft());
	timerMinutesLeft.invalidate();
}

void addevent::UpdateRight()
{
	Unicode::snprintf(timerHoursTopBuffer, 10, "%02d", getHoursTop());
	timerHoursTop.invalidate();
	Unicode::snprintf(timerHoursBottomBuffer, 10, "%02d", getHoursBottom());
	timerHoursBottom.invalidate();
}

void addevent::ChangeTemp(int value)
{
	setTemp(value);
	Unicode::snprintf(tempIndBuffer, 10, "%02d", getTemp());
	tempInd.invalidate();
}
