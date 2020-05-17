#include <gui/containers/CustomListElement.hpp>

CustomListElement::CustomListElement() :
    viewCallback(0)
{
}

void CustomListElement::setupListElement()//int day, int hour, int minute, int temp, int durationLeft, int durationRight, int id)
{
	return;
	//создание нового элемента видимого списка
	//this->id = id;
	//this->day = day;
	//this->hour = hour;
	//this->minute = minute;
	//this->temp = temp;
	//this->durationLeft = durationLeft;
	//this->durationRight = durationRight;
	//отображение новых данных
	//SetDay(day);
	//Unicode::snprintf(hourTextBuffer, 10, "%02d", hour);
	//Unicode::snprintf(minuteTextBuffer, 10, "%02d", minute);
	//Unicode::snprintf(tempTextBuffer, 10, "%02d", temp);
	//Unicode::snprintf(durationLeftTextBuffer, 10, "%02d", durationLeft);
	//Unicode::snprintf(durationRightTextBuffer, 10, "%02d", durationRight);
	invalidate();
}

void CustomListElement::setAction(GenericCallback< CustomListElement& >& callback)
{
    viewCallback = &callback;
}

void CustomListElement::deleteAction()
{
    // Inform the view of the event
    if (viewCallback->isValid())
    {
        viewCallback->execute(*this);
    }
}

void CustomListElement::SetDay(int d)
{
	switch(d)
	{
	case 0:
		Unicode::strncpy(dayTextBuffer, "вс", 4);
		break;
	case 1:
		Unicode::strncpy(dayTextBuffer, "пн", 4);
		break;
	case 2:
		Unicode::strncpy(dayTextBuffer, "вт", 4);
		break;
	case 3:
		Unicode::strncpy(dayTextBuffer, "ср", 4);
		break;
	case 4:
		Unicode::strncpy(dayTextBuffer, "чт", 4);
		break;
	case 5:
		Unicode::strncpy(dayTextBuffer, "пт", 4);
		break;
	case 6:
		Unicode::strncpy(dayTextBuffer, "сб", 4);
		break;
	default:
		Unicode::strncpy(dayTextBuffer, "нн", 4);
	}
}
