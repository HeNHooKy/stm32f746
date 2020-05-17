#include <gui/containers/shoesmodul.hpp>

shoesmodul::shoesmodul() : viewCallback(0)
{

}

void shoesmodul::initialize()
{
    shoesmodulBase::initialize();
}

void shoesmodul::setAction(GenericCallback< shoesmodul& >& callback)
{
	viewCallback = &callback;
}

void shoesmodul::ChangeTemp(int value)
{
	Unicode::snprintf(tempBuffer, 10, "%02d", value);
	temp.invalidate();
}

void shoesmodul::ChangeTime(int value)
{
	time.setTime24Hour(value/60, value%60, 0);
	time.invalidate();
}

void shoesmodul::StopDry()
{
	if (viewCallback->isValid())
	{
		viewCallback->execute(*this);
	}
}
