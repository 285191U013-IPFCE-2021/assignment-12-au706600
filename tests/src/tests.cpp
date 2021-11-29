#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

#include <stdio.h>

extern "C"
{
#include "Duration.h"
}

TEST_CASE("Duration")
{

    //Testcase for duration 

            // First test 
    Duration *test = new Duration();
    int g = test->getDuration();
    REQUIRE(g == 0);
            // Second test 
    Duration *Dura = new Duration(1);
    g = Dura->getDuration();
    REQUIRE(g == 1);
    
    for(int i = 0; i < 6; i++)
    {
        Dura->tick();
    }

    g = Dura->getDuration();
    REQUIRE(g == 7);

            // testing (f)  
    Duration *DuraTest = new Duration(1);
    g = DuraTest->getDuration();
    REQUIRE(g == 1);
    DuraTest->tick(4);
    g = DuraTest->getDuration();
    REQUIRE(g == 5);    
}

TEST_CASE("alarm")
{
    Duration d0 = Duration();
    Duration d1(8);
    Duration d2(13);

    d0.setAlarm(10);
    REQUIRE(d0.tick(6) == false);
    REQUIRE(d0.CheckAlarm()== true);

    d1.setAlarm(20);
    REQUIRE(d1.tick(11) == false);
    REQUIRE(d1.CheckAlarm()== true);

    d2.setAlarm(30);
    REQUIRE(d2.tick(11) == false);
    REQUIRE(d2.CheckAlarm()== true);

    d0.setAlarm(15);
    REQUIRE(d0.tick() == false);

    Duration d4(1);
    d4.setAlarm(4);
    d4.tick(5);
    REQUIRE(d4.CheckAlarm() == false);

}
