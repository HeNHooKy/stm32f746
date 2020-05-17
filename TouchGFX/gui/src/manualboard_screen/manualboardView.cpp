#include <gui/manualboard_screen/manualboardView.hpp>

manualboardView::manualboardView()
	: dressmodulCallback(this, &manualboardView::StopDryLeft),
	  shoesmodulCallback(this, &manualboardView::StopDryRight)
{
	UpdateLeft();
	UpdateRight();
}

void manualboardView::setupScreen()
{
    manualboardViewBase::setupScreen();

    dressmodul1.setAction(dressmodulCallback);
    shoesmodul1.setAction(shoesmodulCallback);
}

void manualboardView::tearDownScreen()
{
    manualboardViewBase::tearDownScreen();
}

void manualboardView::HoursDownLeft()
{
	setHoursLeft(getHoursLeft() - 1);
	UpdateLeft();

}
void manualboardView::HoursUpLeft()
{
	setHoursLeft(getHoursLeft() + 1);
	UpdateLeft();

}
void manualboardView::MinutesDownLeft()
{
	setMinutesLeft(getMinutesLeft() - 1);
	UpdateLeft();

}
void manualboardView::MinutesUpLeft()
{
	setMinutesLeft(getMinutesLeft() + 1);
	UpdateLeft();
}



void manualboardView::HoursDownRight()
{
	setHoursRight(getHoursRight() - 1);
	UpdateRight();
}
void manualboardView::HoursUpRight()
{
	setHoursRight(getHoursRight() + 1);
	UpdateRight();
}
void manualboardView::MinutesDownRight()
{
	setMinutesRight(getMinutesRight() - 1);
	UpdateRight();
}
void manualboardView::MinutesUpRight()
{
	setMinutesRight(getMinutesRight() + 1);
	UpdateRight();
}

void manualboardView::UpdateLeft()
{
	Unicode::snprintf(timerHoursLeftBuffer, 10, "%02d", getHoursLeft());
	timerHoursLeft.invalidate();
	Unicode::snprintf(timerMinutesLeftBuffer, 10, "%02d", getMinutesLeft());
	timerMinutesLeft.invalidate();
}

void manualboardView::UpdateRight()
{
	Unicode::snprintf(timerHoursRightBuffer, 10, "%02d", getHoursRight());
	timerHoursRight.invalidate();
	Unicode::snprintf(timerMinutesRightBuffer, 10, "%02d", getMinutesRight());
	timerMinutesRight.invalidate();
}

void manualboardView::ChangeTempLeft(int value)
{
	setTempLeft(value);
	Unicode::snprintf(tempLeftIndBuffer, 10, "%02d", getTempLeft());
	tempLeftInd.invalidate();
}

void manualboardView::ChangeTempRight(int value)
{
	setTempRight(value);
	Unicode::snprintf(tempRightIndBuffer, 10, "%02d", getTempRight());
	tempRightInd.invalidate();
}

//ПЕРЕДАЧА ДАННЫХ НА GX:

void manualboardView::StartDryLeft()
{	//запуск сушки в ЛЕВОМ отсеке
	int time = getHoursLeft()*60 + getMinutesLeft(); //минут
	int temp = getTempLeft();
	presenter->StartDryLeft(time, temp); //отправляем запрос на выполнение

	//информируем пользователя
	//показываем "штору"
	dressmodul1.setVisible(true);
	dressmodul1.invalidate();

	//скрываем кнопку "закрыть"
	setSL(true);
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}


void manualboardView::StopDryLeft(dressmodul& element)
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

void manualboardView::StartDryRight()
{
	int time = getHoursRight()*60 + getMinutesRight(); //минут
	int temp = getTempRight();
	presenter->StartDryRight(time, temp);

	//показываем "штору"
	shoesmodul1.setVisible(true);
	shoesmodul1.invalidate();

	//скрываем кнопку "закрыть"
	setSR(true);	//скрываем кнопку закрыть, если идет хотя бы одна сушка
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

void manualboardView::StopDryRight(shoesmodul& element)
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

void manualboardView::DisplayTimeLeft(int minute)
{
	dressmodul1.ChangeTime(minute);
}

void manualboardView::DisplayTimeRight(int minute)
{
	shoesmodul1.ChangeTime(minute);
}

void manualboardView::DisplayTempLeft(int value)
{
	dressmodul1.ChangeTemp(value);
}

void manualboardView::DisplayTempRight(int value)
{
	shoesmodul1.ChangeTemp(value);
}

//отображение данных о сушке
void manualboardView::DisplayStatusLeft(int status)
{
	setSL(status); //сохраняем статус
	dressmodul1.setVisible(status); //скрываем или отображаем dressmodul1
	dressmodul1.invalidate();

	fon1.SetVisibleClosebt(!getStatuses()); //скрываем или отображаем кнопку "закрыть"
	fon1.invalidate();
}

void manualboardView::DisplayStatusRight(int status)
{
	setSR(status); //сохраняем статус
	shoesmodul1.setVisible(status);
	shoesmodul1.invalidate();
	fon1.SetVisibleClosebt(!getStatuses());
	fon1.invalidate();
}

void manualboardView::ShowMessage(char* message)
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

