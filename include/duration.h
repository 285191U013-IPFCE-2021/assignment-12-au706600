#ifndef DURATION_H
#define DURATION_H


class Duration
{
    private:
        int time;
        int alarm;
        bool alarmHasBeenSet;
        bool checkAndUpdateAlarm();

    public:
            // constructors
        Duration();
        Duration(int t);

            // methods
        int getDuration();
        bool tick();
        bool tick(int dt);
        void setAlarm(int t);
        bool CheckAlarm(); // this is the function i made solely to test alarm in the tast cases
};
#endif