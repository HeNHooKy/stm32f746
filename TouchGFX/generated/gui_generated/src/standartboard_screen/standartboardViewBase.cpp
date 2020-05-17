/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/standartboard_screen/standartboardViewBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"
#include <touchgfx/Color.hpp>

standartboardViewBase::standartboardViewBase()
{

    fon1.setXY(0, 0);

    skin11.setXY(0, 0);

    digitaltimerleftbt.setPosition(76, 137, 95, 40);
    digitaltimerleftbt.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    digitaltimerleftbt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID29));
    digitaltimerleftbt.displayLeadingZeroForHourIndicator(true);
    digitaltimerleftbt.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR_NO_SECONDS);
    digitaltimerleftbt.setTime24Hour(8, 0, 0);

    digitaltimerrightbt.setPosition(320, 137, 95, 40);
    digitaltimerrightbt.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    digitaltimerrightbt.setTypedText(touchgfx::TypedText(T_SINGLEUSEID32));
    digitaltimerrightbt.displayLeadingZeroForHourIndicator(true);
    digitaltimerrightbt.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR_NO_SECONDS);
    digitaltimerrightbt.setTime24Hour(8, 0, 0);

    StartLeftBT.setXY(75, 185);
    StartLeftBT.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_ON_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_ON2_ID));

    StartRightBT.setXY(319, 185);
    StartRightBT.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_ON_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_ON2_ID));

    textArea1.setXY(31, 41);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID30));

    textArea1_1.setXY(278, 41);
    textArea1_1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1_1.setLinespacing(0);
    textArea1_1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID31));

    dressmodul1.setXY(0, 21);
    dressmodul1.setVisible(false);

    shoesmodul1.setXY(244, 21);
    shoesmodul1.setVisible(false);

    msgBox1.setXY(25, 61);
    msgBox1.setVisible(false);

    add(fon1);
    add(skin11);
    add(digitaltimerleftbt);
    add(digitaltimerrightbt);
    add(StartLeftBT);
    add(StartRightBT);
    add(textArea1);
    add(textArea1_1);
    add(dressmodul1);
    add(shoesmodul1);
    add(msgBox1);
}

void standartboardViewBase::setupScreen()
{
    fon1.initialize();
    skin11.initialize();
    dressmodul1.initialize();
    shoesmodul1.initialize();
    msgBox1.initialize();
}
