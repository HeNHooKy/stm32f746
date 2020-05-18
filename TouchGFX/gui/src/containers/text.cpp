#include <gui/containers/text.hpp>

text::text()
{

}

void text::initialize()
{
    textBase::initialize();
}

//дни недели
touchgfx::Unicode::UnicodeChar *text::getVsBuf()
{
	return vsBuffer;
}

touchgfx::Unicode::UnicodeChar *text::getPnBuf()
{
	return pnBuffer;
}

touchgfx::Unicode::UnicodeChar *text::getVtBuf()
{
	return vtBuffer;
}

touchgfx::Unicode::UnicodeChar *text::getSrBuf()
{
	return srBuffer;
}

touchgfx::Unicode::UnicodeChar *text::getChtBuf()
{
	return chtBuffer;
}

touchgfx::Unicode::UnicodeChar *text::getPtBuf()
{
	return ptBuffer;
}

touchgfx::Unicode::UnicodeChar *text::getSbBuf()
{
	return sbBuffer;
}

//пользовательские ошибки
touchgfx::Unicode::UnicodeChar *text::getError1Buf()
{
	return errorevent1Buffer;
}

touchgfx::Unicode::UnicodeChar *text::getError2Buf()
{
	return errorevent2Buffer;
}

touchgfx::Unicode::UnicodeChar *text::getError3Buf()
{
	return errorevent3Buffer;
}

touchgfx::Unicode::UnicodeChar *text::getError4Buf()
{
	return errorevent4Buffer;
}

