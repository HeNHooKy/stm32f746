#ifndef STARTBOARDVIEW_HPP
#define STARTBOARDVIEW_HPP

#include <gui_generated/startboard_screen/startboardViewBase.hpp>
#include <gui/startboard_screen/startboardPresenter.hpp>

class startboardView : public startboardViewBase
{
public:
    startboardView();
    virtual ~startboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void HoursDown();
    void HoursUp();
    void MinutesDown();
    void MinutesUp();

    void SetTimeDate();
    void SetDay(int day);

    //экстренный возврат на главный экран
    virtual void GoToMain();
protected:
    void Update();
    int getHours()
	{
		return hoursTimer;
	}
	void setHours(int value)
	{
		if(value == 24)
		{
			hoursTimer = value;
			setMinutes(0);
		}
		else if(value == 0 && minutesTimer == 0)
		{
			hoursTimer = value;
			setMinutes(1);
		}
		else if(value >= 0 && value < 24)
		{
			hoursTimer = value;
		}
	}
	int getMinutes()
	{
		return minutesTimer;
	}
	void setMinutes(int value)
	{
		if(value >= 0 && value < 60 && hoursTimer < 24 && hoursTimer > 0)
		{
			minutesTimer = value;
		}
		else if(value == 60 && hoursTimer < 24 && hoursTimer >= 0)
		{
			minutesTimer = 0;
			setHours(getHours() + 1);
		}
		else if(value < 0 && hoursTimer != 0)
		{
			minutesTimer = 59;
			setHours(getHours() - 1);
		}
		else if(hoursTimer == 0 && value > 0 && value < 60)
		{
			minutesTimer = value;
		}
		else if(hoursTimer == 24)
		{
			minutesTimer = 0;
		}
	}
private:
	int hoursTimer = 12;
	int minutesTimer = 00;
};

#endif // STARTBOARDVIEW_HPP
