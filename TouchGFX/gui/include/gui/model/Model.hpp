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

	//включение-выключение сушки по расписанию
	void SetDryEventsFlag(bool flag);

    //методы задания и проверки пользовательского времени
    int ClockChecker();
    void SetClock(int hours, int minutes, int weekDay);
    void GetCurTimeDay(int *day, int *hour, int *minute);


protected:
    ModelListener* modelListener;
    void DisplayTime();

    int leftTempAddress = 101;
};

#endif // MODEL_HPP
