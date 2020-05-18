#include <gui/standartboard_screen/standartboardView.hpp>
#include "configuration.h"

extern char message[MSG_SIZE];

standartboardView::standartboardView()
	: dressmodulCallback(this, &standartboardView::StopDryLeft),
	  shoesmodulCallback(this, &standartboardView::StopDryRight)
{

}

void standartboardView::setupScreen()
{
    standartboardViewBase::setupScreen();

    dressmodul1.setAction(dressmodulCallback);
    shoesmodul1.setAction(shoesmodulCallback);
}

void standartboardView::tearDownScreen()
{
    standartboardViewBase::tearDownScreen();
}

//Запуск - остановка сушки:
void standartboardView::StartDryLeft()
{	//запуск сушки в ЛЕВОМ отсеке
	presenter->StartDryLeft(); //отправляем запрос на выполнение

	//информируем пользователя
	//показываем "штору"
	dressmodul1.setVisible(true);
	dressmodul1.invalidate();

	//скрываем кнопку "закрыть"
	setSL(true);
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

void standartboardView::StopDryLeft(dressmodul& element)
{
	presenter->StopDryLeft();

	//скрываем штору
	element.setVisible(false);
	element.invalidate();

	//отображаем кнопку "закрыть"
	setSL(false);
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

void standartboardView::StartDryRight()
{
	presenter->StartDryRight();

	//показываем "штору"
	shoesmodul1.setVisible(true);
	shoesmodul1.invalidate();

	//скрываем кнопку "закрыть"
	setSR(true);	//скрываем кнопку закрыть, если идет хотя бы одна сушка
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

void standartboardView::StopDryRight(shoesmodul& element)
{
	presenter->StopDryRight(); //отправляем команду об остановке выполнения сушки

	//скрываем "штору"
	element.setVisible(false);
	element.invalidate();

	//отображаем кнопку "закрыть"
	setSR(false);
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

//ОТОБРАЖЕНИЕ ДАННЫХ С GX:

void standartboardView::DisplayTimeLeft(int minute)
{
	dressmodul1.ChangeTime(minute);
}

void standartboardView::DisplayTimeRight(int minute)
{
	shoesmodul1.ChangeTime(minute);
}

void standartboardView::DisplayTempLeft(int value)
{
	dressmodul1.ChangeTemp(value);
}

void standartboardView::DisplayTempRight(int value)
{
	shoesmodul1.ChangeTemp(value);
}

void standartboardView::DisplayStatusLeft(int status)
{
	setSL(status); //сохраняем статус
	dressmodul1.setVisible(status); //скрываем или отображаем dressmodul1
	dressmodul1.invalidate();

	fon1.SetVisibleClosebt(!getStatuses()); //скрываем или отображаем кнопку "закрыть"
	fon1.invalidate();
}

void standartboardView::DisplayStatusRight(int status)
{
	setSR(status); //сохраняем статус
	shoesmodul1.setVisible(status);
	shoesmodul1.invalidate();
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

void standartboardView::ShowMessage(int num)
{
	//TODO: подготовить сообщение об ошибке к показу

	msgBox1.Show(num);
	msgBox1.setVisible(true);
	msgBox1.invalidate();

	//скрываем все шторы
	dressmodul1.setVisible(false);
	dressmodul1.invalidate();
	shoesmodul1.setVisible(false);
	shoesmodul1.invalidate();

	//показываем кнопку "закрыть"
	fon1.SetVisibleClosebt(true);
	fon1.invalidate();

}
