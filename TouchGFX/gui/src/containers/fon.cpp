#include <gui/containers/fon.hpp>

fon::fon()
{

}

void fon::initialize()
{
    fonBase::initialize();
}

void fon::SetVisibleClosebt(bool visible)
{
	closebt.setVisible(visible);
}
