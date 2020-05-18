#ifndef TEXT_HPP
#define TEXT_HPP

#include <gui_generated/containers/textBase.hpp>

class text : public textBase
{
public:
    text();
    virtual ~text() {}

    virtual void initialize();

    //дни недели
    touchgfx::Unicode::UnicodeChar *getVsBuf();
    touchgfx::Unicode::UnicodeChar *getPnBuf();
    touchgfx::Unicode::UnicodeChar *getVtBuf();
    touchgfx::Unicode::UnicodeChar *getSrBuf();
    touchgfx::Unicode::UnicodeChar *getChtBuf();
    touchgfx::Unicode::UnicodeChar *getPtBuf();
    touchgfx::Unicode::UnicodeChar *getSbBuf();

    //пользовательские ошибки
    touchgfx::Unicode::UnicodeChar *getError1Buf();
    touchgfx::Unicode::UnicodeChar *getError2Buf();
    touchgfx::Unicode::UnicodeChar *getError3Buf();
    touchgfx::Unicode::UnicodeChar *getError4Buf();
protected:
};

#endif // TEXT_HPP
