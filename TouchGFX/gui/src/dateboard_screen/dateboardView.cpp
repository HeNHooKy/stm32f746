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
	  listElementClickedCallback(this, &dateboardView::DelEvent),
	  dressmodulCallback(this, &dateboardView::StopDryLeft),
	  shoesmodulCallback(this, &dateboardView::StopDryRight)
{

}



void dateboardView::setupScreen()
{

    dateboardViewBase::setupScreen();
    addevent1.setAction(addeventCallback);
    dressmodul1.setAction(dressmodulCallback);
    shoesmodul1.setAction(shoesmodulCallback);

    //обновляем данные списка
    list.removeAll();
    DisplayList(1);
    SetDay(1);
    list.invalidate();
}

void dateboardView::tearDownScreen()
{
    dateboardViewBase::tearDownScreen();
}


//показать окно добавления события
void dateboardView::CallAddEvent()
{

	addevent1.SetInDay(getDay());
	addevent1.setVisible(true);
	addevent1.invalidate();
}

//удаление события, вызвавшего этот метод
void dateboardView::DelEvent(CustomListElement& element)
{
	int day = element.day;
	int id = element.id;
	if(DelDryEvent(day, id) == EVENT_OK)
	{
		list.remove(element);
		list.invalidate();
		container.invalidate();
	}
}

//извлечение из окна addevent всех данных и передача их в метод CreateEvent
void dateboardView::AddEvent(addevent& element)
{
	//получаем данные о новой сушке
	int day = element.getDay();
	int hour = element.getHoursLeft();
	int minute = element.getMinutesLeft();
	int temp = element.getTemp();
	int durationLeft = element.getHoursTop() * 60;
	int durationRight = element.getHoursBottom() * 60;
	element.ResetData(); //сброс данных по умолчанию
	//добавляем новое событие в список событий
	CreateEvent(day, hour, minute, temp, durationLeft, durationRight);

}

//очищает всё расписание
void dateboardView::ClearAll()
{
	clearbox.setVisible(false);
	clearbox.invalidate();
	//очистка всех массивов
	for(int i = 0; i < 7; i++)
	{
		int maxId = GetMaxId(i);
		for(int j = 0; j <= maxId; j++)
		{
			DelDryEvent(i, j);

		}

	}
	SetDay(1);
	DisplayList(1);
	list.invalidate();
	Container.invalidate();
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
		msgBox1.Show(1);
		msgBox1.setVisible(true);
		msgBox1.invalidate();
	}
}

//обновление списка событий
void dateboardView::DisplayList(int day)
{
	list.removeAll();
	int dayId = GetMaxId(day);

	dryEvent *pointer = GetPointerArray(day);

	for(int i = 0; i <= dayId; i++)
	{
		customListElements[i].setupListElement(pointer[i].startDay, pointer[i].startHour, pointer[i].startMinut, pointer[i].temp_F,
					pointer[i].duration_F/60, pointer[i].duration_S/60, pointer[i].id);
		customListElements[i].setAction(listElementClickedCallback);
		list.add(customListElements[i]);
	}
	list.invalidate();
	container.invalidate();
}

//получить максимальный id, который есть в массиве заданного дня
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
	DisplayList(1);
}
void dateboardView::SetTwoD()
{
	DisplayList(2);
}
void dateboardView::SetWedD()
{
	DisplayList(3);
}
void dateboardView::SetThuD()
{
	DisplayList(4);
}
void dateboardView::SetFriD()
{
	DisplayList(5);
}
void dateboardView::SetSatD()
{
	DisplayList(6);
}
void dateboardView::SetSunD()
{
	DisplayList(0);
}

//Запуск работы по расписанию
void dateboardView::StartDryEvents()
{
	if(sundayID == -1 && mondayID == -1 && tuesdayID == -1 && wednesdayID == -1 &&
			thursdayID == -1 && fridayID == -1 && saturdayID == -1)
	{
		msgBox1.Show(4);
		msgBox1.setVisible(true);
		msgBox1.invalidate();
		return;
	}


	presenter->SetDryEventsFlag(true);
	//Показать штору
	startModul.setVisible(true);
	startModul.invalidate();
}

//остановка работы по расписанию
void dateboardView::StopDryEvents()
{
	presenter->SetDryEventsFlag(false);
	//останавливаем сушки
	StopDryLeft(dressmodul1);
	StopDryRight(shoesmodul1);
	//закрываем штору
	startModul.setVisible(false);
	startModul.invalidate();
}



//остановка сушки в левом отсеке
void dateboardView::StopDryLeft(dressmodul& element)
{
	presenter->StopDryLeft();

	//скрываем "штору"
	element.setVisible(false);
	element.invalidate();
}

//остановка сушки в правом отсеке
void dateboardView::StopDryRight(shoesmodul& element)
{
	presenter->StopDryRight(); //отправляем команду об остановке выполнения сушки

	//скрываем "штору"
	element.setVisible(false);
	element.invalidate();
}


//ОТОБРАЖЕНИЕ ДАННЫХ С GX:
void dateboardView::DisplayTimeLeft(int minute)
{
	dressmodul1.ChangeTime(minute);
}

void dateboardView::DisplayTimeRight(int minute)
{
	shoesmodul1.ChangeTime(minute);
}

void dateboardView::DisplayTempLeft(int value)
{
	dressmodul1.ChangeTemp(value);
}

void dateboardView::DisplayTempRight(int value)
{
	shoesmodul1.ChangeTemp(value);
}

//отображение данных о сушке
void dateboardView::DisplayStatusLeft(int status)
{
	dressmodul1.setVisible(status); //скрываем или отображаем dressmodul1
	dressmodul1.invalidate();
}

void dateboardView::DisplayStatusRight(int status)
{
	shoesmodul1.setVisible(status);
	shoesmodul1.invalidate();
}
//показать сообщение об ошибке
void dateboardView::ShowMessage(int num)
{
	msgBox1.Show(num);
	msgBox1.setVisible(true);
	msgBox1.invalidate();

	//скрываем все шторы
	StopDryLeft(dressmodul1);
	StopDryRight(shoesmodul1);
	startModul.setVisible(false);
	startModul.invalidate();
}

//экстренный возврат на главный экран
void dateboardView::GoToMain()
{
	StopDryLeft(dressmodul1);
	StopDryRight(shoesmodul1);
	application().gotomainboardScreenNoTransition();
}
























//отображает на экране выбранный день
void dateboardView::SetDay(int day)
{
	switch(day)
	{
	case Sunday:
		vsbt.setSelected(true);
		break;
	case Monday:
		pnbt.setSelected(true);
		break;
	case Tuesday:
		vtbt.setSelected(true);
		break;
	case Wednesday:
		srbt.setSelected(true);
		break;
	case Thursday:
		chtbt.setSelected(true);
		break;
	case Friday:
		ptbt.setSelected(true);
		break;
	case Saturday:
		sbbt.setSelected(true);
		break;
	}
}

