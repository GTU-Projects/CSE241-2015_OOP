/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.cpp
 * Author: Hasan
 * 
 * Created on 18 Aralik 2015 Cuma, 18:49
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Time.h"
#include <climits>

namespace GTU_HMENN {
    using std::ostream;

    Time::Time(int newDay, int newMonth, int newYear) {
        setTime(newDay, newMonth, newYear);
    }

    Time::Time(const Time& orig) {
        setTime(orig.getDay(), orig.getMonth(), orig.getYear());
    }

    void Time::setDay(int newDay) {
        if (newDay > 0 && newDay <= 30)
            m_day = newDay;
        else m_day = 1;
    }

    void Time::setMonth(int newMonth) {
        if (newMonth > 0 && newMonth <= 12)
            m_month = newMonth;
        else m_month = 1;
    }
    
    void Time::setYear(int newYear){
        if(newYear>0 && newYear<INT_MAX)
            m_year=newYear;
        else m_year=1990;
    }
    
    void Time::setTime(int day, int month, int year){
        setDay(day);
        setMonth(month);
        setYear(year);
    }
    
    Time& Time::operator =(const Time& object){
        if(this!=&object)
            this->setTime(object.getDay(),object.getMonth(),object.getYear());        
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& output,const Time& object)
    {
        output<<" "<<object.getDay()
                <<" "<<object.getMonth()
                <<" "<<object.getYear()<<" ";
        return output;
    }

} // end of GTU_HMENN

