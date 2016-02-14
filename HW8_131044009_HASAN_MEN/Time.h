/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: Hasan
 *
 * Created on 18 Aralik 2015 Cuma, 18:49
 */

#ifndef TIME_H
#define TIME_H

#include <ostream>

namespace GTU_HMENN {
    using std::ostream;

    class Time {
    public:
        Time(const Time& orig);
        Time(int day=1, int month = 1, int year = 1990);
        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear);
        void setTime(int day=1,int month=1,int year=1990);
        int getYear()const{return m_year;}
        int getDay()const{return m_day;}
        int getMonth()const{return m_month;}
      
        Time& operator=(const Time& object);
        friend ostream& operator<<(ostream& output, const Time& time);
    private:
        int m_day;
        int m_month;
        int m_year;
    };

}//end of GTU_HMENN

#endif /* TIME_H */

