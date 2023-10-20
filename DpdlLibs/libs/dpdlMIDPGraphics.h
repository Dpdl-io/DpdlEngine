# Dpdl Lib V1.0     
#
# (c)opyright 2003
# SEE Solutions
#
# info@dpdl.io
#
#
# This library is implemented with Dpdl scripting and comes with the standard core DpdlEngine.
# It contains system abstraction functions and internal variables.
#
# Filename: dpdlMIDPGraphics.h
# This library provides functions for accessing MIDP/J2ME Graphics functionalities
#

func gSetCurrent(int component)
     return MIDPLIB_graphicsSetCurrent(component)
end

func gRepaint(int component)
     return MIDPLIB_graphicsRepaint(component)
end

func gClear(int component)
     return MIDPLIB_graphicsClear(component)
end

func gSetColor(int component, int r, int g, int b)
     return MIDPLIB_graphicsSetColor(component, r, g, b)
end

func gDrawLine(int component, int x1, int y1, int x2, int y2)
     return MIDPLIB_graphicsDrawLine(component, x1, y1, x2, y2)
end

func gDrawRect(int component, int x, int y, int w, int h)
     return MIDPLIB_graphicsDrawRect(component, x, y, w, h)
end

func gFillRect(int component, int x, int y, int w, int h)
    return MIDPLIB_graphicsFillRect(component, x, y, w, h)
end

func gDrawString(int component, string str, int x, int y, int anchor)
     return MIDPLIB_graphicsDrawString(component, str, x, y, anchor)
end


#params && anchor points
int BASELINE = 64
int BOTTOM = 32
int DOTTED = 1
int HCENTER = 1
int LEFT = 4
int RIGHT = 8
int SOLID = 0
int TOP = 16
int VCENTER = 2

#start


