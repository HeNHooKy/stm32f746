#include <gui/containers/dressmodul.hpp>

dressmodul::dressmodul() : viewCallback(0)
{

}

void dressmodul::initialize()
{
    dressmodulBase::initialize();
}

void dressmodul::setAction(GenericCallback< dressmodul& >& callback)
{
	viewCallback = &callback;
}

void dressmodul::ChangeTemp(int value)
{
	Unicode::snprintf(tempBuffer, 10, "%02d", value);
	temp.invalidate();
}

void dressmodul::ChangeTime(int value)
{
	time.setTime24Hour(value/60, value%60, 0);
	time.invalidate();
}

void dressmodul::StopDry()
{
	if (viewCallback->isValid())
	{
		viewCallback->execute(*this);
	}
}
