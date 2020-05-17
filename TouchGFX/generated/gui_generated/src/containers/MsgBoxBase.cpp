/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/MsgBoxBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

MsgBoxBase::MsgBoxBase() :
    buttonCallback(this, &MsgBoxBase::buttonCallbackHandler)
{
    setWidth(455);
    setHeight(164);
    tiledImage1.setBitmap(touchgfx::Bitmap(BITMAP_FON4_ID));
    tiledImage1.setPosition(0, 0, 455, 164);
    tiledImage1.setOffset(0, 0);

    Image1.setXY(0, 0);
    Image1.setBitmap(touchgfx::Bitmap(BITMAP_WARNING_ID));

    okbt.setXY(162, 115);
    okbt.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_PRESED_ID));
    okbt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID238));
    okbt.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    okbt.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    okbt.setAction(buttonCallback);

    message.setPosition(150, 9, 294, 100);
    message.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    message.setLinespacing(0);
    messageBuffer[0] = 0;
    message.setWildcard(messageBuffer);
    message.setTypedText(touchgfx::TypedText(T_SINGLEUSEID233));

    add(tiledImage1);
    add(Image1);
    add(okbt);
    add(message);
}

void MsgBoxBase::initialize()
{

}

void MsgBoxBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &okbt)
    {
        //Close
        //When okbt clicked call virtual function
        //Call CloseMessage
        CloseMessage();
    }
}
