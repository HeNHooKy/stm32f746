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
    virtual void CallClearWindow();
    virtual void CallAddEvent();
    void AddEvent(addevent& element);
    void DelEvent(CustomListElement& element);
    void CreateEvent(int day, int hour, int minute, int temp, int durationLeft, int durationRight);
    void SetDay(int day);
    void DisplayList(int day);
    void RemoveAll();
    int GetMaxId(int day);


    //функции переключения дней
    virtual void SetMonD();
    virtual void SetTwoD();
    virtual void SetWedD();
    virtual void SetThuD();
    virtual void SetFriD();
    virtual void SetSatD();
    virtual void SetSunD();


protected:
    Callback<dateboardView, addevent&> addeventCallback;
    Callback<dateboardView, CustomListElement&> listElementClickedCallback;

    //массивы кнопок событий
    CustomListElement customListElements[10]; //массив элементов событий


};

#endif // DATEBOARDVIEW_HPP
