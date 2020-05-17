/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/servicesBase.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

servicesBase::servicesBase()
{
    setWidth(480);
    setHeight(204);
    tiledImage1.setBitmap(touchgfx::Bitmap(BITMAP_FON4_ID));
    tiledImage1.setPosition(0, 0, 480, 204);
    tiledImage1.setOffset(0, 0);

    Image1.setXY(6, 17);
    Image1.setBitmap(touchgfx::Bitmap(BITMAP_WARNING_ID));

    textArea1.setXY(141, 20);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID168));

    okbt.setXY(176, 150);
    okbt.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_PRESED_ID));
    okbt.setLabelText(touchgfx::TypedText(T_SINGLEUSEID169));
    okbt.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    okbt.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));

    add(tiledImage1);
    add(Image1);
    add(textArea1);
    add(okbt);
}

void servicesBase::initialize()
{

}
