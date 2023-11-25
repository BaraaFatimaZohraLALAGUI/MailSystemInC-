// LALAGUI Baraa Fatima Zohra

#include <iostream>

#include"SpacePartA.h"
#include"SpacePartB.h"
#include"SpacePartC.h"

#include <chrono>

#include <time.h>

#include <sstream>

#include <time.h>

#include <fstream>

using namespace std::chrono;

using namespace std;

double getAverageSendingTime(SpacePartA & space)

{

    auto start = high_resolution_clock::now();

    space.MakeEmpty();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    double num = space.getCurrentSize();

    double Average ;

    Average = duration.count()/num;

    space.ReSetCurrentSize();

    return Average;

}

double getAverageSendingTime(SpacePartB & space)

{

    auto start = high_resolution_clock::now();

    space.MakeEmpty();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    double num = space.getCurrentSize();

    double Average ;

    Average = duration.count()/num;

    space.ReSetCurrentSize();

    return Average;

}

double getAverageSendingTime(SpacePartC & space)

{

    auto start = high_resolution_clock::now();

    space.MakeEmpty();

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    double num = space.getCurrentSize();

    double Average ;

    Average = duration.count()/num;

    space.ReSetCurrentSize();

    return Average;

}