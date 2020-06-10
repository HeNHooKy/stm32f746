/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINBOARDVIEWBASE_HPP
#define MAINBOARDVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/mainboard_screen/mainboardPresenter.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/ModalWindow.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <gui/containers/text.hpp>
#include <gui/containers/MsgBox.hpp>

class mainboardViewBase : public touchgfx::View<mainboardPresenter>
{
public:
    mainboardViewBase();
    virtual ~mainboardViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void MsgServiceMaintenance()
    {
        // Override and implement this function in mainboard
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image fon;
    touchgfx::ButtonWithLabel manualbutton;
    touchgfx::ButtonWithLabel heatingboard;
    touchgfx::ButtonWithLabel Standartboard;
    touchgfx::ButtonWithLabel Dateboard;
    touchgfx::DigitalClock RealClock;
    touchgfx::Button WaringBT;
    touchgfx::TextAreaWithOneWildcard day;
    touchgfx::Image logo;
    touchgfx::ModalWindow servises;
    touchgfx::Image Image1;
    touchgfx::TextArea textArea1;
    touchgfx::ButtonWithLabel okbt;
    text text1;
    touchgfx::Button SetTimeBT;
    MsgBox msgBox1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t DAY_SIZE = 10;
    touchgfx::Unicode::UnicodeChar dayBuffer[DAY_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<mainboardViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MAINBOARDVIEWBASE_HPP
