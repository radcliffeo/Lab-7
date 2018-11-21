//////////////////////////////////////////////////////////////////////////////
// Timer.cpp   UNIX SYSTEM VERSION
// =========
// High Resolution Timer.
// This timer is able to measure the elapsed time with 1 micro-second accuracy
// in both Windows, Linux and Unix system 
//
//  AUTHOR: Song Ho Ahn (song.ahn@gmail.com)
// CREATED: 2003-01-13
// UPDATED: 2006-01-13
//
// Copyright (c) 2003 Song Ho Ahn
//////////////////////////////////////////////////////////////////////////////
// MODIFIED: by tom bailey  1000  19 nov 2012
// change of method names
// change to bool for running flag
// change timeInSeconds from data member to local variable
//
// MODIFIED: by tom bailey   1500  28 feb 2013
// separate the Windows and Unix versions
//////////////////////////////////////////////////////////////////////////////

#include "unixTimer.h"
#include <cstdlib>

///////////////////////////////////////////////////////////////////////////////
// constructor
///////////////////////////////////////////////////////////////////////////////
Timer::Timer()
{
    running = false;
    elapsedTimeInSec = 0.0;
}



///////////////////////////////////////////////////////////////////////////////
// distructor
///////////////////////////////////////////////////////////////////////////////
Timer::~Timer()
{
}



///////////////////////////////////////////////////////////////////////////////
// start the timer.
// startTime will be set at this point.
///////////////////////////////////////////////////////////////////////////////
void Timer::start()
{
   if( ! running )
   {
      timeval startCount;                         //
      gettimeofday(&startCount, NULL);
      startTimeInSec = double( startCount.tv_sec ) + 0.000001 * double( startCount.tv_usec );
      running = true; 
   }
}



///////////////////////////////////////////////////////////////////////////////
// stop the timer.
// calculate time for this interval and add to elapsed time.
///////////////////////////////////////////////////////////////////////////////
void Timer::stop()
{
   if( running )
   {
      timeval endCount;                           //
      gettimeofday(&endCount, NULL);
      double endTimeInSec = double( endCount.tv_sec ) + 0.000001 * double( endCount.tv_usec );
      elapsedTimeInSec += endTimeInSec - startTimeInSec;
      running = false; 
   }
}



//////////////////////////////////////////////////////////////////////////////
// return elapsed time in seconds
//////////////////////////////////////////////////////////////////////////////
double Timer::operator()()
{
   if( running )
   {
      stop();
      start();
   }    
   return elapsedTimeInSec;    
}