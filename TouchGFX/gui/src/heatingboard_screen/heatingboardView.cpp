#include <gui/heatingboard_screen/heatingboardView.hpp>

heatingboardView::heatingboardView()
	: dressmodulCallback(this, &heatingboardView::StopDryLeft),
	  shoesmodulCallback(this, &heatingboardView::StopDryRight)
{

}

void heatingboardView::setupScreen()
{
    heatingboardViewBase::setupScreen();

    dressmodul1.setAction(dressmodulCallback);
    shoesmodul1.setAction(shoesmodulCallback);
}

void heatingboardView::tearDownScreen()
{
    heatingboardViewBase::tearDownScreen();
}


//Запуск - остановка сушки:
void heatingboardView::StartDryLeft()
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

void heatingboardView::StopDryLeft(dressmodul& element)
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

void heatingboardView::StartDryRight()
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

void heatingboardView::StopDryRight(shoesmodul& element)
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

void heatingboardView::DisplayTimeLeft(int minute)
{
	dressmodul1.ChangeTime(minute);
}

void heatingboardView::DisplayTimeRight(int minute)
{
	shoesmodul1.ChangeTime(minute);
}

void heatingboardView::DisplayTempLeft(int value)
{
	dressmodul1.ChangeTemp(value);
}

void heatingboardView::DisplayTempRight(int value)
{
	shoesmodul1.ChangeTemp(value);
}

void heatingboardView::DisplayStatusLeft(int status)
{
	setSL(status); //сохраняем статус
	dressmodul1.setVisible(status); //скрываем или отображаем dressmodul1
	dressmodul1.invalidate();

	fon1.SetVisibleClosebt(!getStatuses()); //скрываем или отображаем кнопку "закрыть"
	fon1.invalidate();
}

void heatingboardView::DisplayStatusRight(int status)
{
	setSR(status); //сохраняем статус
	shoesmodul1.setVisible(status);
	shoesmodul1.invalidate();
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

void heatingboardView::ShowMessage(char* message)
{
	msgBox1.Show(message);
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
