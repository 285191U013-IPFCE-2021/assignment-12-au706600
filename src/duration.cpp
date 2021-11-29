#include "../include/Duration.h"
#include <assert.h>

int Duration::getDuration()
// a) 
{
    return time;
}


Duration::Duration()
// b) 
{
    time = 0;
}

Duration::Duration(int t)
// c) 
{
    assert(t>=0);
    time = t;
}

bool Duration::tick()
// e) 
{
    assert(time >= 0);
    time++;
    if (alarmHasBeenSet == true)
        checkAndUpdateAlarm();
    else 
    return false;
}

bool Duration::tick(int dt)
// f) 
{
    assert(dt >= 0);
    time = time + dt;
    if (alarmHasBeenSet == true)
        checkAndUpdateAlarm();
    else 
    return false;
}

void Duration::setAlarm(int t)
// g) 
{
    assert(t > time);
    alarmHasBeenSet = true;
    alarm = t;
}

bool Duration::checkAndUpdateAlarm() 
// i)
{
    if (time >= alarm) // if the time has surpassed alarms value it resets alarms value and returns true, meaning that alarm was reset
    {
        alarm = 1000000000;
        alarmHasBeenSet = false;
        return true;
    }
    else 
    return false; // the alarm has been set, but if alarms value is still greater than time, it returns false 
}

bool Duration::CheckAlarm()
{
    return alarmHasBeenSet;
}




