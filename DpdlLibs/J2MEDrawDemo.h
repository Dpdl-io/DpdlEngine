# File: J2MEDrawDemo.h
# Date: 21.07.2007
# Dpdl example: This script implements a drawing canvas on J2ME devices
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#
import("dpdlMIDP.h")

func initDrawTest()
  println("test init()")
end

#this method draws a grid
func draw()
     if(CANVAS != -1)
       gClear(CANVAS)
       gSetCurrent(CANVAS)
       gSetColor(CANVAS, 20, 20, 20)
       int x_, y_, old_y_
       x_ = 0
       y_ = 0
       old_y_ = y_
       int value
       string id
       int time_
       setStartTime()
       while x_ < 150
                y_ = 0
                while y_ < 100
                   gDrawRect(CANVAS, x_, y_, 5, 5)
                   gRepaint(CANVAS)
                   y_ = y_ + 5
               endwhile
               x_ = x_ + 5
               gFillRect(CANVAS, x_, x_, 5, 5)
       endwhile
       time_ = getEndTime()
       gDrawString(CANVAS, "Hello World from Dpdl in (ms):", 10, y_+12, LEFT)
       string time_str = "" + time_
       gDrawString(CANVAS, time_str, 10, y_+22, LEFT)
     fi
end

#main()
int CANVAS = 0
initDrawTest()
draw()

