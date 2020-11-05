#include <bits/stdc++.h>
using namespace std;

int countSundays()
{
    vector<int> daysInEachMonth({31,
                                 28,
                                 31,
                                 30,
                                 31,
                                 30,
                                 31,
                                 31,
                                 30,
                                 31,
                                 30,
                                 31});

    int currentYear = 1900;
    int currentDay = 7;
    int currentMonth = 0;
    int numberOfSundays = 0;

    while (currentYear < 2001)
    {
        currentDay += 7;
        int daysInMonth =
            currentMonth == 1 ? ((currentYear % 4 == 0) ? 29 : 28) : daysInEachMonth[currentMonth];

        if (daysInEachMonth[currentMonth] < currentDay)
        {
            currentDay -= daysInEachMonth[currentMonth];
            currentMonth++;

            if (currentMonth >= 12)
            {
                currentMonth = 0;
                currentYear++;
            }
            if (currentDay == 1 && currentYear > 1900)
            {
                numberOfSundays++;
            }
        }
    }

    return numberOfSundays;
}

int main()
{
    cout << countSundays();
    return 0;
}
