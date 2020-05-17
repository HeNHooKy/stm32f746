/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/CustomListElementBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

CustomListElementBase::CustomListElementBase() :
    buttonCallback(this, &CustomListElementBase::buttonCallbackHandler)
{
    setWidth(440);
    setHeight(25);
    fon.setXY(0, 0);
    fon.setBitmap(touchgfx::Bitmap(BITMAP_CALENDAR_ID));

    deletebt.setXY(418, 4);
    deletebt.setBitmaps(touchgfx::Bitmap(BITMAP_CLEAR_ID), touchgfx::Bitmap(BITMAP_CLEAR_ID));
    deletebt.setAction(buttonCallback);

    dayText.setPosition(15, 0, 46, 25);
    dayText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    dayText.setLinespacing(0);
    dayTextBuffer[0] = 0;
    dayText.setWildcard(dayTextBuffer);
    dayText.setTypedText(touchgfx::TypedText(T_SINGLEUSEID165));

    hourText.setPosition(61, 0, 40, 25);
    hourText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    hourText.setLinespacing(0);
    hourTextBuffer[0] = 0;
    hourText.setWildcard(hourTextBuffer);
    hourText.setTypedText(touchgfx::TypedText(T_SINGLEUSEID244));

    minuteText.setPosition(101, 0, 40, 25);
    minuteText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    minuteText.setLinespacing(0);
    minuteTextBuffer[0] = 0;
    minuteText.setWildcard(minuteTextBuffer);
    minuteText.setTypedText(touchgfx::TypedText(T_SINGLEUSEID245));

    tempText.setPosition(141, 0, 40, 25);
    tempText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    tempText.setLinespacing(0);
    tempTextBuffer[0] = 0;
    tempText.setWildcard(tempTextBuffer);
    tempText.setTypedText(touchgfx::TypedText(T_SINGLEUSEID246));

    durationLeftText.setPosition(181, 0, 40, 25);
    durationLeftText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    durationLeftText.setLinespacing(0);
    durationLeftTextBuffer[0] = 0;
    durationLeftText.setWildcard(durationLeftTextBuffer);
    durationLeftText.setTypedText(touchgfx::TypedText(T_SINGLEUSEID247));

    durationRightText.setPosition(221, 0, 40, 25);
    durationRightText.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    durationRightText.setLinespacing(0);
    durationRightTextBuffer[0] = 0;
    durationRightText.setWildcard(durationRightTextBuffer);
    durationRightText.setTypedText(touchgfx::TypedText(T_SINGLEUSEID248));

    add(fon);
    add(deletebt);
    add(dayText);
    add(hourText);
    add(minuteText);
    add(tempText);
    add(durationLeftText);
    add(durationRightText);
}

void CustomListElementBase::initialize()
{

}

void CustomListElementBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &deletebt)
    {
        //deleteInteraction
        //When deletebt clicked call virtual function
        //Call deleteAction
        deleteAction();
    }
}
