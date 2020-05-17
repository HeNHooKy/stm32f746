#ifndef ADDEVENT_HPP
#define ADDEVENT_HPP

#include <gui_generated/containers/addeventBase.hpp>

class addevent : public addeventBase
{
public:
    addevent();
    virtual ~addevent() {}

    virtual void initialize();

    //user declared functions
    virtual void Close();
    //controllers
	virtual void HoursDownLeft();
	virtual void HoursUpLeft();
	virtual void MinutesDownLeft();
	virtual void MinutesUpLeft();

	virtual void HoursDownTop();
	virtual void HoursUpTop();
	virtual void HoursDownBottom();
	virtual void HoursUpBottom();

	//temp
	virtual void ChangeTemp(int value);


	//save
	virtual void AddNewEvent();
	virtual void Add();

	//сброс данных
	void ResetData();

	void setAction(GenericCallback< addevent& >& callback);

    GenericCallback< addevent& >* viewCallback;

    //day
    int getDay()
    {
    	return day;
    }
    void setDay()
    {
    	int weekDay = 0;

		if(pnbt.getSelected())
		{
			weekDay = 0;
		}
		else if(vtbt.getSelected())
		{
			weekDay = 1;
		}
		else if(srbt.getSelected())
		{
			weekDay = 2;
		}
		else if(chtbt.getSelected())
		{
			weekDay = 3;
		}
		else if(ptbt.getSelected())
		{
			weekDay = 4;
		}
		else if(sbbt.getSelected())
		{
			weekDay = 5;
		}
		else
		{
			weekDay = 6;
		}

		day = weekDay;
    }

    //temp
	int getTemp()
	{
		return temp;
	}
	void setTemp(int value)
	{
		temp = value;
	}

	//LEFT
	void UpdateLeft();
	int getHoursLeft()
	{
		return hoursLeftTimer;
	}
	void setHoursLeft(int value)
	{
		if(value == 24)
		{
			hoursLeftTimer = value;
			setMinutesLeft(0);
		}
		else if(value == 0 && minutesLeftTimer == 0)
		{
			hoursLeftTimer = value;
			setMinutesLeft(1);
		}
		else if(value >= 0 && value < 24)
		{
			hoursLeftTimer = value;
		}
	}
	int getMinutesLeft()
	{
		return minutesLeftTimer;
	}
	void setMinutesLeft(int value)
	{
		if(value >= 0 && value < 60 && hoursLeftTimer < 24 && hoursLeftTimer > 0)
		{
			minutesLeftTimer = value;
		}
		else if(value == 60 && hoursLeftTimer < 24 && hoursLeftTimer >= 0)
		{
			minutesLeftTimer = 0;
			setHoursLeft(getHoursLeft() + 1);
		}
		else if(value < 0 && hoursLeftTimer != 0)
		{
			minutesLeftTimer = 59;
			setHoursLeft(getHoursLeft() - 1);
		}
		else if(hoursLeftTimer == 0 && value > 0 && value < 60)
		{
			minutesLeftTimer = value;
		}
		else if(hoursLeftTimer == 24)
		{
			minutesLeftTimer = 0;
		}
	}

	//RIGHT
	void UpdateRight();
	int getHoursTop()
	{
		return HoursTopTimer;
	}
	void setHoursTop(int value)
	{
		if(value >= 0 && value <= 24)
		{
			HoursTopTimer = value;
		}
	}
	int getHoursBottom()
	{
		return HoursBottomTimer;
	}
	void setHoursBottom(int value)
	{
		if(value >= 0 && value <= 24)
		{
			HoursBottomTimer = value;
		}
	}
private:
	int HoursBottomTimer = 8;
	int HoursTopTimer = 8;
	int hoursLeftTimer = 12;
	int minutesLeftTimer = 0;
	int temp = 60;
	int day = 0;

};

#endif // ADDEVENT_HPP
