#ifndef CUSTOMLISTELEMENT_HPP
#define CUSTOMLISTELEMENT_HPP

#include <gui_generated/containers/CustomListElementBase.hpp>

class CustomListElement : public CustomListElementBase
{
public:
    CustomListElement();
    virtual ~CustomListElement() {}

    /**
     * Initialize this containers widgets
     */
    void setupListElement(int dayA, int hourA, int minuteA, int tempA, int durationLeftA, int durationRightA, int idA);

    /**
     * Setup the view callback
     */
    void setAction(GenericCallback< CustomListElement& >& callback);

    void SetDay(int d);

    virtual void deleteAction();

    //все данные о событии
    int day;
	int hour;
	int minute;
	int temp;
	int durationLeft;
	int durationRight;
	int id;
protected:

    /**
     * Callback that that notifies the creator of the list element of an event
     */
    GenericCallback< CustomListElement& >* viewCallback;
};

#endif // CUSTOMLISTELEMENT_HPP
