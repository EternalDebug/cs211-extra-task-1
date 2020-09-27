#include <iostream>
#include <assert.h>
#include <cmath>

using namespace std;



namespace Extra {

    //Return the number of seconds later that a time in seconds time_2 is than a time in seconds time_1.
    double seconds_difference(double time_1, double time_2)
    {
        // your implementation goes here...

        return time_2 - time_1;

        /*
            Return the number of seconds later that a time in seconds
            time_2 is than a time in seconds time_1.

            >>> seconds_difference(1800.0, 3600.0)
            1800.0

            >>> seconds_difference(3600.0, 1800.0)
            -1800.0

            >>> seconds_difference(1800.0, 2160.0)
            360.0

            >>> seconds_difference(1800.0, 1800.0)
            0.0
        */
    }


    //Return the number of hours later that a time in seconds time_2 is than a time in seconds time_1.
    double hours_difference(double time_1, double time_2)
    {

        return (time_2 - time_1) / 3600;
        /*
            Return the number of hours later that a time in seconds
            time_2 is than a time in seconds time_1.

            >>> hours_difference(1800.0, 3600.0)
            0.5

            >>> hours_difference(3600.0, 1800.0)
            -0.5

            >>> hours_difference(1800.0, 2160.0)
            0.1

            >>> hours_difference(1800.0, 1800.0)
            0.0
        */
    }


    //Return the total number of hours in the specified number of hours, minutes, and seconds.
    double to_float_hours(int hours, int minutes, int seconds)
    {
        assert(0 <= minutes);
        assert(minutes < 60);
        assert(0 <= seconds);
        assert(seconds < 60);

        return hours + minutes / 60.0 + seconds / 3600.0;
        /*
            Return the total number of hours in the specified number
            of hours, minutes, and seconds.

            Precondition: 0 <= minutes < 60  and  0 <= seconds < 60

            >>> to_float_hours(0, 15, 0)
            0.25

            >>> to_float_hours(2, 45, 9)
            2.7525

            >>> to_float_hours(1, 0, 36)
            1.01
        */
    }


    //hours is a number of hours since midnight. Return the hour as seen on a 24 - hour clock.
    double to_24_hour_clock(double hours)
    {
        assert(hours >= 0);

        double d = hours;

        while (d >= 24)
            d -= 24;

        return d;
        /*
            hours is a number of hours since midnight. Return the
            hour as seen on a 24-hour clock.

            Precondition: hours >= 0

            >>> to_24_hour_clock(24)
            0

            >>> to_24_hour_clock(48)
            0

            >>> to_24_hour_clock(25)
            1

            >>> to_24_hour_clock(4)
            4

            >>> to_24_hour_clock(28.5)
            4.5

            You may wish to inspect various function in <cmath> to work
            with integer and fractional part of a hours separately.

        */
    }

    /*
        Implement three functions
            * get_hours
            * get_minutes
            * get_seconds
        They are used to determine the hours part, minutes part and seconds part
        of a time in seconds. E.g.:

        >>> get_hours(3800)
        1

        >>> get_minutes(3800)
        3

        >>> get_seconds(3800)
        20

        In other words, if 3800 seconds have elapsed since midnight,
        it is currently 01:03:20 (hh:mm:ss).
    */

    int get_hours(double time)
    {
        int res = 0;
        double t = time;

        while (t >= 3600)
        {
            t -= 3600;
            res++;
        }

        return res;
    }

    int get_minutes(double time)
    {
        int res = 0;
        double t = time;

        t -= get_hours(time) * 3600;

        while (t >= 60)
        {
            t -= 60;
            res++;
        }


        return res;
    }

    double get_seconds(double time)
    {
        return time - get_hours(time) * 3600 - get_minutes(time) * 60;
    }




    double time_to_utc(int utc_offset, double time)
    {
        double res = time - utc_offset;

        if (res >= 24)
            res -= 24;
        if (res < 0)
            res += 24;

        return res;

        /*
            Return time at UTC+0, where utc_offset is the number of hours away from
            UTC+0.
            You may be interested in:
            https://en.wikipedia.org/wiki/Coordinated_Universal_Time

            >>> time_to_utc(+0, 12.0)
            12.0

            >>> time_to_utc(+1, 12.0)
            11.0

            >>> time_to_utc(-1, 12.0)
            13.0

            >>> time_to_utc(-11, 18.0)
            5.0

            >>> time_to_utc(-1, 0.0)
            1.0

            >>> time_to_utc(-1, 23.0)
            0.0
        */
    }

    double time_from_utc(int utc_offset, double time)
    {
        double res = time + utc_offset;
        if (res >= 24)
            res -= 24;
        if (res < 0)
            res += 24;

        return res;
        /*
            Return UTC time in time zone utc_offset.

            >>> time_from_utc(+0, 12.0)
            12.0

            >>> time_from_utc(+1, 12.0)
            13.0

            >>> time_from_utc(-1, 12.0)
            11.0

            >>> time_from_utc(+6, 6.0)
            12.0

            >>> time_from_utc(-7, 6.0)
            23.0

            >>> time_from_utc(-1, 0.0)
            23.0

            >>> time_from_utc(-1, 23.0)
            22.0

            >>> time_from_utc(+1, 23.0)
            0.0
        */
    }
}

using namespace Extra;

int main()
{
    cout << "seconds_difference asserts:" << endl;
    cout << "seconds_difference (1800.0, 3600.0):" << endl;
    assert(abs(Extra::seconds_difference(1800.0, 3600.0) - 1800.0) < DBL_EPSILON);
    cout << "seconds_difference (3600.0, 1800.0):" << endl;
    assert(abs(Extra::seconds_difference(3600.0, 1800.0) + 1800.0) < DBL_EPSILON);
    cout << "seconds_difference (1800.0, 2160.0):" << endl;
    assert(abs(Extra::seconds_difference(1800.0, 2160.0) - 360.0) < DBL_EPSILON);
    cout << "seconds_difference (1800.0, 1800.0):" << endl;
    assert(abs(Extra::seconds_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
    cout << "Are Done." << endl;

    cout << endl;

    cout << "hours_difference asserts:" << endl;
    cout << "hours_difference (1800.0, 3600.0):" << endl;
    assert(abs(Extra::hours_difference(1800.0, 3600.0) - 0.5) < DBL_EPSILON);
    cout << "hours_difference (3600.0, 1800.0):" << endl;
    assert(abs(Extra::hours_difference(3600.0, 1800.0) + 0.5) < DBL_EPSILON);
    cout << "hours_difference (1800.0, 2160.0):" << endl;
    assert(abs(Extra::hours_difference(1800.0, 2160.0) - 0.1) < DBL_EPSILON);
    cout << "hours_difference (1800.0, 1800.0):" << endl;
    assert(abs(Extra::hours_difference(1800.0, 1800.0) - 0.0) < DBL_EPSILON);
    cout << "Are Done." << endl;

    cout << endl;
    cout << "to_float_hours asserts:" << endl;
    cout << "to_float_hours(0, 15, 0):" << endl;
    //cout << to_float_hours(0, 15, 0) << endl;
    assert(abs(to_float_hours(0, 15, 0) - 0.25) < DBL_EPSILON);
    cout << "to_float_hours(2, 45, 9):" << endl;
    assert(abs(to_float_hours(2, 45, 9) - 2.7525) < DBL_EPSILON);
    cout << "to_float_hours(1, 0, 36):" << endl;
    assert(abs(to_float_hours(1, 0, 36) - 1.01) < DBL_EPSILON);
    cout << "Are Done." << endl;


    cout << endl;
    cout << "to_float_hours asserts:" << endl;
    cout << "to_24_hour_clock(24):" << endl;
    assert(abs(to_24_hour_clock(24) - 0.0) < DBL_EPSILON);
    cout << "to_24_hour_clock(48):" << endl;
    assert(abs(to_24_hour_clock(48) - 0.0) < DBL_EPSILON);
    cout << "to_24_hour_clock(25):" << endl;
    assert(abs(to_24_hour_clock(25) - 1.0) < DBL_EPSILON);
    cout << "to_24_hour_clock(4):" << endl;
    assert(abs(to_24_hour_clock(4) - 4.0) < DBL_EPSILON);
    cout << "to_24_hour_clock(28.5):" << endl;
    assert(abs(to_24_hour_clock(28.5) - 4.5) < DBL_EPSILON);
    cout << "Are Done." << endl;



    cout << endl;
    cout << "get_hours, get_minutes, get_seconds asserts:" << endl;
    cout << "get_hours(3800):" << endl;
    assert(abs(get_hours(3800) - 1) < DBL_EPSILON);
    cout << "get_minutes(3800):" << endl;
    assert(abs(get_minutes(3800) - 3) < DBL_EPSILON);
    cout << "get_seconds(3800):" << endl;
    assert(abs(get_seconds(3800) - 20) < DBL_EPSILON);
    cout << "Are Done." << endl;


    cout << endl;
    cout << "time_to_utc asserts:" << endl;
    cout << "time_to_utc(+0, 12.0):" << endl;
    assert(abs(time_to_utc(+0, 12.0) - 12) < DBL_EPSILON);
    cout << "time_to_utc(+1, 12.0):" << endl;
    assert(abs(time_to_utc(+1, 12.0) - 11) < DBL_EPSILON);
    cout << "time_to_utc(-1, 12.0):" << endl;
    assert(abs(time_to_utc(-1, 12.0) - 13) < DBL_EPSILON);
    cout << "time_to_utc(-11, 18.0):" << endl;
    assert(abs(time_to_utc(-11, 18.0) - 5) < DBL_EPSILON);
    cout << "time_to_utc(-1, 0.0):" << endl;
    assert(abs(time_to_utc(-1, 0.0) - 1) < DBL_EPSILON);
    cout << "time_to_utc(-1, 23.0):" << endl;
    assert(abs(time_to_utc(-1, 23.0) - 0) < DBL_EPSILON);
    cout << "Are Done." << endl;


    cout << endl;
    cout << "time_from_utc asserts:" << endl;
    cout << "time_from_utc(+0, 12.0):" << endl;
    assert(abs(time_from_utc(+0, 12.0) - 12) < DBL_EPSILON);
    cout << "time_from_utc(+1, 12.0):" << endl;
    assert(abs(time_from_utc(+1, 12.0) - 13) < DBL_EPSILON);
    cout << "time_from_utc(-1, 12.0):" << endl;
    assert(abs(time_from_utc(-1, 12.0) - 11) < DBL_EPSILON);
    cout << "time_from_utc(+6, 6.0):" << endl;
    assert(abs(time_from_utc(+6, 6.0) - 12) < DBL_EPSILON);
    cout << "time_from_utc(-7, 6.0):" << endl;
    assert(abs(time_from_utc(-7, 6.0) - 23) < DBL_EPSILON);
    cout << "time_from_utc(-1, 0.0):" << endl;
    assert(abs(time_from_utc(-1, 0.0) - 23) < DBL_EPSILON);
    cout << "time_from_utc(-1, 23.0):" << endl;
    assert(abs(time_from_utc(-1, 23.0) - 22) < DBL_EPSILON);
    cout << "time_from_utc(+1, 23.0):" << endl;
    assert(abs(time_from_utc(+1, 23.0) - 0) < DBL_EPSILON);
    cout << "Are Done." << endl;

    cout << endl;
    cout << endl;
    cout << endl;
    cout <<"All Tasks succesfully done"<< endl;
}

/*
            seconds_difference asserts:
seconds_difference (1800.0, 3600.0):
seconds_difference (3600.0, 1800.0):
seconds_difference (1800.0, 2160.0):
seconds_difference (1800.0, 1800.0):
Are Done.

hours_difference asserts:
hours_difference (1800.0, 3600.0):
hours_difference (3600.0, 1800.0):
hours_difference (1800.0, 2160.0):
hours_difference (1800.0, 1800.0):
Are Done.

to_float_hours asserts:
to_float_hours(0, 15, 0):
to_float_hours(2, 45, 9):
to_float_hours(1, 0, 36):
Are Done.

to_float_hours asserts:
to_24_hour_clock(24):
to_24_hour_clock(48):
to_24_hour_clock(25):
to_24_hour_clock(4):
to_24_hour_clock(28.5):
Are Done.

get_hours, get_minutes, get_seconds asserts:
get_hours(3800):
get_minutes(3800):
get_seconds(3800):
Are Done.

time_to_utc asserts:
time_to_utc(+0, 12.0):
time_to_utc(+1, 12.0):
time_to_utc(-1, 12.0):
time_to_utc(-11, 18.0):
time_to_utc(-1, 0.0):
time_to_utc(-1, 23.0):
Are Done.

time_from_utc asserts:
time_from_utc(+0, 12.0):
time_from_utc(+1, 12.0):
time_from_utc(-1, 12.0):
time_from_utc(+6, 6.0):
time_from_utc(-7, 6.0):
time_from_utc(-1, 0.0):
time_from_utc(-1, 23.0):
time_from_utc(+1, 23.0):
Are Done.



All Tasks succesfully done
        */
