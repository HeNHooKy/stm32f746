#ifndef DATEBOARDVIEW_HPP
#define DATEBOARDVIEW_HPP

#include <gui_generated/dateboard_screen/dateboardViewBase.hpp>
#include <gui/dateboard_screen/dateboardPresenter.hpp>
#include <gui/containers/CustomListElement.hpp>

class dateboardView : public dateboardViewBase
{
public:
    dateboardView();
    virtual ~dateboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    //user funcitons:
    virtual void ClearAll();
    virtual void CallAddEvent();
    void AddEvent(addevent& element);
    void DelEvent(CustomListElement& element);
    void CreateEvent(int day, int hour, int minute, int temp, int durationLeft, int durationRight);
    void SetDay(int day);
    void DisplayList(int day);
    void RemoveAll();
    int GetMaxId(int day);

    //запуск-остановка работы по расписанию
    virtual void StartDryEvents();
    virtual void StopDryEvents();

    //остановки для отсеков
    virtual void StopDryRight(shoesmodul& element);
    virtual void StopDryLeft(dressmodul& element);



    //данные с GX:
	virtual void DisplayTimeLeft(int minute);
	virtual void DisplayTimeRight(int minute);
	virtual void DisplayTempLeft(int value);
	virtual void DisplayTempRight(int value);
	virtual void DisplayStatusLeft(int status);
	virtual void DisplayStatusRight(int status);


    //функции переключения дней
    virtual void SetMonD();
    virtual void SetTwoD();
    virtual void SetWedD();
    virtual void SetThuD();
    virtual void SetFriD();
    virtual void SetSatD();
    virtual void SetSunD();

    //вывод сообщений
	virtual void ShowMessage(int num);

	//экстренный возврат на главный экран
	virtual void GoToMain();

protected:
    //колбек окна создания события
    Callback<dateboardView, addevent&> addeventCallback;
    //колбек строки события
    Callback<dateboardView, CustomListElement&> listElementClickedCallback;
    //контроль "штор"
	Callback<dateboardView, dressmodul&> dressmodulCallback;
	Callback<dateboardView, shoesmodul&> shoesmodulCallback;

    //массивы кнопок событий
    CustomListElement customListElements[10]; //массив элементов событий




    int getDay()
	{
		if(vsbt.getSelected())
		{
			return 0;
		}
		if(pnbt.getSelected())
		{
			return 1;
		}
		else if(vtbt.getSelected())
		{
			return 2;
		}
		else if(srbt.getSelected())
		{
			return 3;
		}
		else if(chtbt.getSelected())
		{
			return 4;
		}
		else if(ptbt.getSelected())
		{
			return 5;
		}
		else
		{
			return 6;
		}
	}


};

#endif // DATEBOARDVIEW_HPP
