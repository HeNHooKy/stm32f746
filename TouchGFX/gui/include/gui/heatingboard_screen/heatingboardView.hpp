#ifndef HEATINGBOARDVIEW_HPP
#define HEATINGBOARDVIEW_HPP

#include <gui_generated/heatingboard_screen/heatingboardViewBase.hpp>
#include <gui/heatingboard_screen/heatingboardPresenter.hpp>

class heatingboardView : public heatingboardViewBase
{
public:
    heatingboardView();
    virtual ~heatingboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    //контроль сушки
    virtual void StartDryLeft();
    virtual void StopDryLeft(dressmodul& element);
    virtual void StartDryRight();
    virtual void StopDryRight(shoesmodul& element);

    //отображения данных GX
    virtual void DisplayTimeLeft(int minute);
	virtual void DisplayTimeRight(int minute);
	virtual void DisplayTempLeft(int value);
	virtual void DisplayTempRight(int value);
	virtual void DisplayStatusLeft(int status);
	virtual void DisplayStatusRight(int status);

	//вывод сообщений
	virtual void ShowMessage(char* message);
protected:
	Callback<heatingboardView, dressmodul&> dressmodulCallback;
	Callback<heatingboardView, shoesmodul&> shoesmodulCallback;

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
private:
	bool sL = false, sR = false;
};

#endif // HEATINGBOARDVIEW_HPP
