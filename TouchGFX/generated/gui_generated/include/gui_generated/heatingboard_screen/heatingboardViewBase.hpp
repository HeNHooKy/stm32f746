/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef HEATINGBOARDVIEWBASE_HPP
#define HEATINGBOARDVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/heatingboard_screen/heatingboardPresenter.hpp>
#include <gui/containers/fon.hpp>
#include <gui/containers/skin1.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>

class heatingboardViewBase : public touchgfx::View<heatingboardPresenter>
{
public:
    heatingboardViewBase();
    virtual ~heatingboardViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    fon fon1;
    skin1 skin11;
    touchgfx::DigitalClock digitalClock1;
    touchgfx::TextArea textArea1;
    touchgfx::DigitalClock digitalClock1_1;
    touchgfx::ToggleButton Button1;
    touchgfx::ToggleButton Button2;
    touchgfx::TextArea textArea2;

private:

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // HEATINGBOARDVIEWBASE_HPP