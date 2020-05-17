/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/mainboard_screen/mainboardViewBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

mainboardViewBase::mainboardViewBase() :
    buttonCallback(this, &mainboardViewBase::buttonCallbackHandler)
{

    fon.setXY(0, 0);
    fon.setBitmap(touchgfx::Bitmap(BITMAP_FON_ID));

    manualbutton.setXY(18, 136);
    manualbutton.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_PRESSED_ID));
    manualbutton.setLabelText(touchgfx::TypedText(T_SINGLEUSEID26));
    manualbutton.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    manualbutton.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    manualbutton.setAction(buttonCallback);

    heatingboard.setXY(248, 136);
    heatingboard.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_PRESSED_ID));
    heatingboard.setLabelText(touchgfx::TypedText(T_SINGLEUSEID27));
    heatingboard.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    heatingboard.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    heatingboard.setAction(buttonCallback);

    Standartboard.setXY(18, 196);
    Standartboard.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_PRESSED_ID));
    Standartboard.setLabelText(touchgfx::TypedText(T_SINGLEUSEID28));
    Standartboard.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Standartboard.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Standartboard.setAction(buttonCallback);

    Dateboard.setXY(248, 196);
    Dateboard.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_M_PRESSED_ID));
    Dateboard.setLabelText(touchgfx::TypedText(T_SINGLEUSEID48));
    Dateboard.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Dateboard.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    Dateboard.setAction(buttonCallback);

    RealClock.setPosition(321, 16, 74, 23);
    RealClock.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    RealClock.setTypedText(touchgfx::TypedText(T_SINGLEUSEID209));
    RealClock.displayLeadingZeroForHourIndicator(true);
    RealClock.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR_NO_SECONDS);
    RealClock.setTime24Hour(10, 10, 0);

    SetTimeBT.setXY(436, 13);
    SetTimeBT.setBitmaps(touchgfx::Bitmap(BITMAP_ICONTIME_ID), touchgfx::Bitmap(BITMAP_ICONTIME_ID));
    SetTimeBT.setAction(buttonCallback);

    WaringBT.setXY(436, 60);
    WaringBT.setVisible(false);
    WaringBT.setBitmaps(touchgfx::Bitmap(BITMAP_WARNING_S_ID), touchgfx::Bitmap(BITMAP_WARNING_S_ID));

    day.setXY(396, 15);
    day.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    day.setLinespacing(0);
    Unicode::snprintf(dayBuffer, DAY_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID212).getText());
    day.setWildcard(dayBuffer);
    day.resizeToCurrentText();
    day.setTypedText(touchgfx::TypedText(T_SINGLEUSEID211));

    logo.setXY(153, 29);
    logo.setBitmap(touchgfx::Bitmap(BITMAP_LOGO_ID));

    servises.setBackground(touchgfx::BitmapId(BITMAP_FON4_ID), 28, 43);
    servises.setShadeColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    servises.setShadeAlpha(152);
    servises.hide();

    Image1.setXY(4, 3);
    Image1.setBitmap(touchgfx::Bitmap(BITMAP_WARNING_ID));
    servises.add(Image1);

    textArea1.setXY(169, 21);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID218));
    servises.add(textArea1);

    okbt.setXY(219, 102);
    okbt.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_PRESED_ID));
    okbt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID219));
    okbt.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    okbt.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    okbt.setAction(buttonCallback);
    servises.add(okbt);

    add(fon);
    add(manualbutton);
    add(heatingboard);
    add(Standartboard);
    add(Dateboard);
    add(RealClock);
    add(SetTimeBT);
    add(WaringBT);
    add(day);
    add(logo);
    add(servises);
}

void mainboardViewBase::setupScreen()
{

}

void mainboardViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &manualbutton)
    {
        //manual
        //When manualbutton clicked change screen to manualboard
        //Go to manualboard with no screen transition
        application().gotomanualboardScreenNoTransition();
    }
    else if (&src == &heatingboard)
    {
        //heating
        //When heatingboard clicked change screen to heatingboard
        //Go to heatingboard with no screen transition
        application().gotoheatingboardScreenNoTransition();
    }
    else if (&src == &Standartboard)
    {
        //standart
        //When Standartboard clicked change screen to standartboard
        //Go to standartboard with no screen transition
        application().gotostandartboardScreenNoTransition();
    }
    else if (&src == &Dateboard)
    {
        //dateboard
        //When Dateboard clicked change screen to dateboard
        //Go to dateboard with no screen transition
        application().gotodateboardScreenNoTransition();
    }
    else if (&src == &SetTimeBT)
    {
        //SetTime
        //When SetTimeBT clicked change screen to startboard
        //Go to startboard with no screen transition
        application().gotostartboardScreenNoTransition();
    }
    else if (&src == &okbt)
    {
        //Interaction1
        //When okbt clicked hide servises
        //Hide servises
        servises.setVisible(false);
        servises.invalidate();
    }
}
