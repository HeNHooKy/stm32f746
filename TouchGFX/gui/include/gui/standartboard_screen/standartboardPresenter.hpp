#ifndef STANDARTBOARDPRESENTER_HPP
#define STANDARTBOARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class standartboardView;

class standartboardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    standartboardPresenter(standartboardView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    //контроль сушки
	virtual void StartDryLeft();
	virtual void StopDryLeft();
	virtual void StartDryRight();
	virtual void StopDryRight();

	//отображения данных GX
	virtual void DisplayTimeLeft(int minute);
	virtual void DisplayTimeRight(int minute);
	virtual void DisplayTempLeft(int value);
	virtual void DisplayTempRight(int value);
	virtual void DisplayStatusLeft(int status);
	virtual void DisplayStatusRight(int status);

	//вывод сообщений
	virtual void ShowMessage(int num);
	//экстренный возврат на главный экран
	virtual void GoToMain();

    virtual ~standartboardPresenter() {};

private:
    standartboardPresenter();

    standartboardView& view;
};

#endif // STANDARTBOARDPRESENTER_HPP
