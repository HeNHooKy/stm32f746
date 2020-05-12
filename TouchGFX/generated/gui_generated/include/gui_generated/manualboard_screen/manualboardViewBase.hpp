/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MANUALBOARDVIEWBASE_HPP
#define MANUALBOARDVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/manualboard_screen/manualboardPresenter.hpp>
#include <gui/containers/fon.hpp>
#include <gui/containers/skin1.hpp>
#include <touchgfx/widgets/RepeatButton.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class manualboardViewBase : public touchgfx::View<manualboardPresenter>
{
public:
    manualboardViewBase();
    virtual ~manualboardViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void ChangeTempLeft(int value)
    {
        // Override and implement this function in manualboard
    }

    virtual void HoursDownLeft()
    {
        // Override and implement this function in manualboard
    }

    virtual void HoursUpLeft()
    {
        // Override and implement this function in manualboard
    }

    virtual void MinutesDownLeft()
    {
        // Override and implement this function in manualboard
    }

    virtual void MinutesUpLeft()
    {
        // Override and implement this function in manualboard
    }

    virtual void HoursDownRight()
    {
        // Override and implement this function in manualboard
    }

    virtual void HoursUpRight()
    {
        // Override and implement this function in manualboard
    }

    virtual void MinutesDownRight()
    {
        // Override and implement this function in manualboard
    }

    virtual void MinutesUpRight()
    {
        // Override and implement this function in manualboard
    }

    virtual void ChangeTempRight(int value)
    {
        // Override and implement this function in manualboard
    }

    virtual void StartDryLeft()
    {
        // Override and implement this function in manualboard
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    fon fon1;
    skin1 skin11;
    touchgfx::RepeatButton hoursDownLeft;
    touchgfx::RepeatButton hoursUpLeft;
    touchgfx::Slider TempSliderLeft;
    touchgfx::TextAreaWithOneWildcard timerHoursLeft;
    touchgfx::TextAreaWithOneWildcard tempLeftInd;
    touchgfx::ToggleButton startLeft;
    touchgfx::TextArea temp2;
    touchgfx::TextArea hour1;
    touchgfx::TextArea minute1;
    touchgfx::RepeatButton minutesDownLeft;
    touchgfx::TextAreaWithOneWildcard timerMinutesLeft;
    touchgfx::RepeatButton minutesUpLeft;
    touchgfx::RepeatButton hoursDownRight;
    touchgfx::RepeatButton hoursUpRight;
    touchgfx::Slider TempSliderRight;
    touchgfx::TextAreaWithOneWildcard timerHoursRight;
    touchgfx::TextAreaWithOneWildcard tempRightInd;
    touchgfx::ToggleButton startRight;
    touchgfx::TextArea temp24;
    touchgfx::TextArea hour;
    touchgfx::TextArea minute;
    touchgfx::RepeatButton minutesDownRight;
    touchgfx::TextAreaWithOneWildcard timerMinutesRight;
    touchgfx::RepeatButton minutesUpRight;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TIMERHOURSLEFT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timerHoursLeftBuffer[TIMERHOURSLEFT_SIZE];
    static const uint16_t TEMPLEFTIND_SIZE = 10;
    touchgfx::Unicode::UnicodeChar tempLeftIndBuffer[TEMPLEFTIND_SIZE];
    static const uint16_t TIMERMINUTESLEFT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timerMinutesLeftBuffer[TIMERMINUTESLEFT_SIZE];
    static const uint16_t TIMERHOURSRIGHT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timerHoursRightBuffer[TIMERHOURSRIGHT_SIZE];
    static const uint16_t TEMPRIGHTIND_SIZE = 10;
    touchgfx::Unicode::UnicodeChar tempRightIndBuffer[TEMPRIGHTIND_SIZE];
    static const uint16_t TIMERMINUTESRIGHT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timerMinutesRightBuffer[TIMERMINUTESRIGHT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<manualboardViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<manualboardViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];
};

#endif // MANUALBOARDVIEWBASE_HPP
