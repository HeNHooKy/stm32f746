#ifndef STANDARTBOARDVIEW_HPP
#define STANDARTBOARDVIEW_HPP

#include <gui_generated/standartboard_screen/standartboardViewBase.hpp>
#include <gui/standartboard_screen/standartboardPresenter.hpp>

class standartboardView : public standartboardViewBase
{
public:
    standartboardView();
    virtual ~standartboardView() {}
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
	virtual void ShowMessage(int num);
protected:
	Callback<standartboardView, dressmodul&> dressmodulCallback;
	Callback<standartboardView, shoesmodul&> shoesmodulCallback;

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

#endif // STANDARTBOARDVIEW_HPP
