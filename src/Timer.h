//
//  Timer.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <stdio.h>
class Timer{
private:
    int minute;
    int second;
    
public:
    int getminute();
    int getsecond();
    void setMinute(int New_Minute);
    void setSecond(int New_Second);
    
};

#endif /* Timer_hpp */
