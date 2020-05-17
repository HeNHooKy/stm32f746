#include <gui/dateboard_screen/dateboardView.hpp>
#include "DryEvent.h"
#include "configuration.h"
#include <string>

//массивы событий
extern struct dryEvent sundayEvents[MAX_EVENTS];;
extern struct dryEvent mondayEvents[MAX_EVENTS];
extern struct dryEvent tuesdayEvents[MAX_EVENTS];
extern struct dryEvent wednesdayEvents[MAX_EVENTS];
extern struct dryEvent thursdayEvents[MAX_EVENTS];
extern struct dryEvent fridayEvents[MAX_EVENTS];
extern struct dryEvent saturdayEvents[MAX_EVENTS];

extern int sundayID; //id воскресений
extern int mondayID; //id понедельников
extern int tuesdayID; //id вторников
extern int wednesdayID; //id сред
extern int thursdayID;//id четвергов
extern int fridayID;//id пятниц
extern int saturdayID;//id суббот


extern char message[MSG_SIZE];

dateboardView::dateboardView()
	: addeventCallback(this, &dateboardView::AddEvent),
	  listElementClickedCallback(this, &dateboardView::DelEvent)
{

}



void dateboardView::setupScreen()
{
    dateboardViewBase::setupScreen();
    addevent1.setAction(addeventCallback);
}

void dateboardView::tearDownScreen()
{
    dateboardViewBase::tearDownScreen();
}


void dateboardView::CallClearWindow()
{

}

void dateboardView::CallAddEvent()
{
	addevent1.setVisible(true);
	addevent1.invalidate();
}

void dateboardView::DelEvent(CustomListElement& element)
{
	int day = element.day;
	int id = element.id;
	DelDryEvent(day, id);
	list.remove(element);
	list.invalidate();
}

void dateboardView::AddEvent(addevent& element)
{
	//получаем данные о новой сушке
	int day = element.getDay();
	int hour = element.getHoursLeft();
	int minute = element.getMinutesLeft();
	int temp = element.getTemp();
	int durationLeft = element.getHoursTop();
	int durationRight = element.getHoursBottom();
	element.ResetData(); //сброс данных по умолчанию
	//добавляем новое событие в список событий
	CreateEvent(day, hour, minute, temp, durationLeft, durationRight);
}

//добавление нового события в массив событий
void dateboardView::CreateEvent(int day, int hour, int minute, int temp, int durationLeft, int durationRight)
{
	if(AddDryEvent(day, hour, minute, durationLeft, temp, durationRight, temp) == EVENT_OK)
	{
		SetDay(day);
		DisplayList(day);
	}
	else
	{
		snprintf(message, MSG_SIZE, "Нельзя добавить новое событие!");
		msgBox1.Show(message);
		msgBox1.setVisible(true);
		msgBox1.invalidate();
	}
}

//обновление списка событий
void dateboardView::DisplayList(int day)
{
	int dayId = GetMaxId(day);

	dryEvent *pointer = GetPointerArray(day);

	for(int i = 0; i < dayId; i++)
	{
		customListElements[i].setupListElement();//pointer->startDay, pointer->startHour, pointer->temp_F, pointer->startMinut,
					//pointer->duration_F, pointer->duration_S, pointer->id);
		customListElements[i].setAction(listElementClickedCallback);
		//list.add(customListElements[i]);
	}
}

int dateboardView::GetMaxId(int day)
{
	switch(day)
	{	//надодим id нужного дня
	case Sunday:
		return sundayID;
	case Monday:
		return mondayID;
	case Tuesday:
		return tuesdayID;
	case Wednesday:
		return wednesdayID;
	case Thursday:
		return thursdayID;
	case Friday:
		return fridayID;
	case Saturday:
		return saturdayID;
	default:
		return  -1;
	}
}


//функции переключения дней
void dateboardView::SetMonD()
{
	list.removeAll();
	DisplayList(1);
}

void dateboardView::SetTwoD()
{
	list.removeAll();
	DisplayList(2);
}

void dateboardView::SetWedD()
{
	list.removeAll();
	DisplayList(3);
}

void dateboardView::SetThuD()
{
	list.removeAll();
	DisplayList(4);
}

void dateboardView::SetFriD()
{
	list.removeAll();
	DisplayList(5);
}

void dateboardView::SetSatD()
{
	list.removeAll();
	DisplayList(6);
}

void dateboardView::SetSunD()
{
	list.removeAll();
	DisplayList(0);
}







































//отображает на экране выбранный день
void dateboardView::SetDay(int day)
{
	switch(day)
	{
	case Sunday:
		pnbt.setSelected(true);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(true);
		break;
	case Monday:
		pnbt.setSelected(true);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case Tuesday:
		pnbt.setSelected(false);
		vtbt.setSelected(true);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case Wednesday:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(true);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case Thursday:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(true);
		ptbt.setSelected(false);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case Friday:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(true);
		sbbt.setSelected(false);
		vsbt.setSelected(false);
		break;
	case Saturday:
		pnbt.setSelected(false);
		vtbt.setSelected(false);
		srbt.setSelected(false);
		chtbt.setSelected(false);
		ptbt.setSelected(false);
		sbbt.setSelected(true);
		vsbt.setSelected(false);
		break;
	}
}

