/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TEXTBASE_HPP
#define TEXTBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class textBase : public touchgfx::Container
{
public:
    textBase();
    virtual ~textBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextAreaWithOneWildcard pn;
    touchgfx::TextAreaWithOneWildcard vt;
    touchgfx::TextAreaWithOneWildcard sr;
    touchgfx::TextAreaWithOneWildcard cht;
    touchgfx::TextAreaWithOneWildcard pt;
    touchgfx::TextAreaWithOneWildcard sb;
    touchgfx::TextAreaWithOneWildcard vs;
    touchgfx::TextAreaWithOneWildcard errorevent1;
    touchgfx::TextAreaWithOneWildcard errorevent2;
    touchgfx::TextAreaWithOneWildcard errorevent3;
    touchgfx::TextAreaWithOneWildcard errorevent4;

    /*
     * Wildcard Buffers
     */
    static const uint16_t PN_SIZE = 10;
    touchgfx::Unicode::UnicodeChar pnBuffer[PN_SIZE];
    static const uint16_t VT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar vtBuffer[VT_SIZE];
    static const uint16_t SR_SIZE = 10;
    touchgfx::Unicode::UnicodeChar srBuffer[SR_SIZE];
    static const uint16_t CHT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar chtBuffer[CHT_SIZE];
    static const uint16_t PT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar ptBuffer[PT_SIZE];
    static const uint16_t SB_SIZE = 10;
    touchgfx::Unicode::UnicodeChar sbBuffer[SB_SIZE];
    static const uint16_t VS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar vsBuffer[VS_SIZE];
    static const uint16_t ERROREVENT1_SIZE = 256;
    touchgfx::Unicode::UnicodeChar errorevent1Buffer[ERROREVENT1_SIZE];
    static const uint16_t ERROREVENT2_SIZE = 256;
    touchgfx::Unicode::UnicodeChar errorevent2Buffer[ERROREVENT2_SIZE];
    static const uint16_t ERROREVENT3_SIZE = 256;
    touchgfx::Unicode::UnicodeChar errorevent3Buffer[ERROREVENT3_SIZE];
    static const uint16_t ERROREVENT4_SIZE = 256;
    touchgfx::Unicode::UnicodeChar errorevent4Buffer[ERROREVENT4_SIZE];

private:

};

#endif // TEXTBASE_HPP