/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/shoesmodulBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

shoesmodulBase::shoesmodulBase() :
    buttonCallback(this, &shoesmodulBase::buttonCallbackHandler)
{
    setWidth(235);
    setHeight(205);
    image3.setXY(0, 0);
    image3.setBitmap(touchgfx::Bitmap(BITMAP_FON6_ID));

    shoestext.setXY(84, 19);
    shoestext.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    shoestext.setLinespacing(0);
    shoestext.setTypedText(touchgfx::TypedText(T_SINGLEUSEID191));

    animatedImage2.setXY(27, 0);
    animatedImage2.setBitmaps(BITMAP_BULBGRAPHON_ID, BITMAP_BULBGRAPHON_ID);
    animatedImage2.setUpdateTicksInterval(1);

    time.setPosition(76, 116, 98, 36);
    time.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    time.setTypedText(touchgfx::TypedText(T_SINGLEUSEID192));
    time.displayLeadingZeroForHourIndicator(true);
    time.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR_NO_SECONDS);
    time.setTime24Hour(10, 10, 0);

    stop2.setXY(75, 164);
    stop2.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_OFF2_ID));
    stop2.setAction(buttonCallback);

    image1.setXY(46, 50);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_THERMOMETER_ICON_ICONS_COM_62485_ID));

    temp.setXY(105, 57);
    temp.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    temp.setLinespacing(0);
    Unicode::snprintf(tempBuffer, TEMP_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID194).getText());
    temp.setWildcard(tempBuffer);
    temp.resizeToCurrentText();
    temp.setTypedText(touchgfx::TypedText(T_SINGLEUSEID193));

    textArea3.setXY(146, 57);
    textArea3.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea3.setLinespacing(0);
    textArea3.setTypedText(touchgfx::TypedText(T_SINGLEUSEID195));

    shoes.setXY(76, 103);
    shoes.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    shoes.setLinespacing(0);
    shoes.setTypedText(touchgfx::TypedText(T_SINGLEUSEID196));

    add(image3);
    add(shoestext);
    add(animatedImage2);
    add(time);
    add(stop2);
    add(image1);
    add(temp);
    add(textArea3);
    add(shoes);
}

void shoesmodulBase::initialize()
{

}

void shoesmodulBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &stop2)
    {
        //StopDry
        //When stop2 clicked call virtual function
        //Call StopDry
        StopDry();
    }
}
