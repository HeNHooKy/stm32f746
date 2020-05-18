#ifndef MANUALBOARDVIEW_HPP
#define MANUALBOARDVIEW_HPP

#include <gui_generated/manualboard_screen/manualboardViewBase.hpp>
#include <gui/manualboard_screen/manualboardPresenter.hpp>

class manualboardView : public manualboardViewBase
{
public:
    manualboardView();
    virtual ~manualboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    //user declared functions
	virtual void HoursDownLeft();
	virtual void HoursUpLeft();
	virtual void MinutesDownLeft();
	virtual void MinutesUpLeft();

	virtual void HoursDownRight();
	virtual void HoursUpRight();
	virtual void MinutesDownRight();
	virtual void MinutesUpRight();

	//temp
	virtual void ChangeTempLeft(int value);
	virtual void ChangeTempRight(int value);

	//контроль запуска сушки
	virtual void StartDryLeft();
	virtual void StopDryLeft(dressmodul& element);
	virtual void StartDryRight();
	virtual void StopDryRight(shoesmodul& element);


	//данные с GX:
	virtual void DisplayTimeLeft(int minute);
	virtual void DisplayTimeRight(int minute);
	virtual void DisplayTempLeft(int value);
	virtual void DisplayTempRight(int value);
	virtual void DisplayStatusLeft(int status);
	virtual void DisplayStatusRight(int status);

	//вывод уведомлений
	virtual void ShowMessage(int num);

protected:
	//контроль "штор"
	Callback<manualboardView, dressmodul&> dressmodulCallback;
	Callback<manualboardView, shoesmodul&> shoesmodulCallback;

	//сумма статусов
	bool getStatuses()
	{
		return sL || sR;
	}

	void setSL(bool status)
	{
		sL = status;
	}

	void setSR(bool status)
	{
		sR = status;
	}

	//temp
	int getTempLeft()
	{
		return tempLeft;
	}
	void setTempLeft(int value)
	{
		tempLeft = value;
	}
	int getTempRight()
	{
		return tempRight;
	}
	void setTempRight(int value)
	{
		tempRight = value;
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
    int getHoursRight()
    	{
    		return hoursRightTimer;
    	}
        void setHoursRight(int value)
        {
        	if(value == 24)
			{
				hoursRightTimer = value;
				setMinutesRight(0);
			}
			else if(value == 0 && minutesRightTimer == 0)
			{
				hoursRightTimer = value;
				setMinutesRight(1);
			}
			else if(value >= 0 && value < 24)
			{
				hoursRightTimer = value;
			}
        }
        int getMinutesRight()
        {
        	return minutesRightTimer;
        }
        void setMinutesRight(int value)
        {
        	if(value >= 0 && value < 60 && hoursRightTimer < 24 && hoursRightTimer > 0)
        	{
        		minutesRightTimer = value;
        	}
        	else if(value == 60 && hoursRightTimer < 24 && hoursRightTimer >= 0)
        	{
        		minutesRightTimer = 0;
        		setHoursRight(getHoursRight() + 1);
        	}
        	else if(value < 0 && hoursRightTimer != 0)
        	{
        		minutesRightTimer = 59;
        		setHoursRight(getHoursRight() - 1);
        	}
        	else if(hoursRightTimer == 0 && value > 0 && value < 60)
        	{
        		minutesRightTimer = value;
        	}
        	else if(hoursRightTimer == 24)
        	{
        		minutesRightTimer = 0;
        	}
        }
private:
    int tempLeft = 60;
    int tempRight = 60;
    int hoursLeftTimer = 12;
    int minutesLeftTimer = 0;
    int hoursRightTimer = 12;
    int minutesRightTimer = 0;

    bool sL = false, sR = false;
};

#endif // MANUALBOARDVIEW_HPP
