/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef PLUSZDBASE_HPP
#define PLUSZDBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/RepeatButton.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/widgets/RadioButtonGroup.hpp>

class PluszdBase : public touchgfx::Container
{
public:
    PluszdBase();
    virtual ~PluszdBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Image fon1;
    touchgfx::ButtonWithLabel closebt2;
    touchgfx::RepeatButton hoursDownLeftbt;
    touchgfx::RepeatButton hoursUpLeftbt;
    touchgfx::TextAreaWithOneWildcard timerHours;
    touchgfx::TextArea hour11;
    touchgfx::ButtonWithLabel savebt;
    touchgfx::TextArea minute1;
    touchgfx::RepeatButton minutesDownLeftbt;
    touchgfx::TextAreaWithOneWildcard timerMinutesLeft;
    touchgfx::RepeatButton minutesUpLeftbt;
    touchgfx::TextArea timestarttext;
    touchgfx::RepeatButton DownClockLeftbt;
    touchgfx::RepeatButton UpClockLeftbt;
    touchgfx::TextAreaWithOneWildcard ClockWorkLeft;
    touchgfx::TextArea hour2;
    touchgfx::TextArea timeclock1;
    touchgfx::RepeatButton DownClockRightbt;
    touchgfx::RepeatButton UpClockRightbt;
    touchgfx::TextAreaWithOneWildcard ClockWorkRight;
    touchgfx::TextArea hour1;
    touchgfx::TextArea timeclock2;
    touchgfx::RadioButton pnbt;
    touchgfx::RadioButton vtbt;
    touchgfx::RadioButton srbt;
    touchgfx::RadioButton chtbt;
    touchgfx::RadioButton ptbt;
    touchgfx::RadioButton sbbt;
    touchgfx::RadioButton vsbt;
    touchgfx::TextArea pntxt;
    touchgfx::TextArea vttxt;
    touchgfx::TextArea srtxt;
    touchgfx::TextArea chttxt;
    touchgfx::TextArea pttxt;
    touchgfx::TextArea sbtxt;
    touchgfx::TextArea vstxt;
    touchgfx::Slider TempSliderLeft;
    touchgfx::TextAreaWithOneWildcard tempLeftInd;
    touchgfx::TextArea temp2;
    touchgfx::RadioButtonGroup<7> day;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TIMERHOURS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timerHoursBuffer[TIMERHOURS_SIZE];
    static const uint16_t TIMERMINUTESLEFT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timerMinutesLeftBuffer[TIMERMINUTESLEFT_SIZE];
    static const uint16_t CLOCKWORKLEFT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ClockWorkLeftBuffer[CLOCKWORKLEFT_SIZE];
    static const uint16_t CLOCKWORKRIGHT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ClockWorkRightBuffer[CLOCKWORKRIGHT_SIZE];
    static const uint16_t TEMPLEFTIND_SIZE = 10;
    touchgfx::Unicode::UnicodeChar tempLeftIndBuffer[TEMPLEFTIND_SIZE];

private:

};

#endif // PLUSZDBASE_HPP
