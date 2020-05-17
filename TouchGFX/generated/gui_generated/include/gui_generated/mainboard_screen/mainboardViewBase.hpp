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
#include <touchgfx/widgets/Button.hpp>

class mainboardViewBase : public touchgfx::View<mainboardPresenter>
{
public:
    mainboardViewBase();
    virtual ~mainboardViewBase() {}
    virtual void setupScreen();
    virtual void afterTransition();

    /*
     * Virtual Action Handlers
     */
    virtual void WarningFunction()
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
    touchgfx::Image logo;
    touchgfx::Image Image2;
    touchgfx::Button SetTime;
    touchgfx::Button warning;

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
