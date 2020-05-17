#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void SendLeftTemp(int value);
    void SendLeftTime(int value);
    void SendLeftOn(int address);
    void SendLeftOff(int address);

    void SendRightTemp(int value);
	void SendRightTime(int value);
	void SendRightOn(int address);
	void SendRightOff(int address);

	int AddNewEvent(int day, int hour, int minute, int duration_f, int duration_s, int temp);

    //методы задания и проверки пользовательского времени
    int ClockChecker();
    void SetClock(int hours, int minutes, int weekDay);

protected:
    ModelListener* modelListener;
    void DisplayTime();

    int leftTempAddress = 101;
};

#endif // MODEL_HPP
