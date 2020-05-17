#include <gui/containers/clearbox.hpp>

clearbox::clearbox()
{

}

void clearbox::initialize()
{
    clearboxBase::initialize();
}

void clearbox::Close()
{
	this->setVisible(false);
	this->invalidate();
}
