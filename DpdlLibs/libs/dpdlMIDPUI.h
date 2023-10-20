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
# Filename: dpdlMIDPUI.h
# This library provides functions for accessing MIDP/J2ME UI functions and components
#

func calendarGet(int field_name)
     return MIDPLIB_getCalendarField(field_name)
end

#return int status == 1 if display  activated else 0
func Alert(string title, string msg, int type)
      return MIDPLIB_Alert(title, msg, type)
end

#return int component id
func Form(int instance, string title)
      return MIDPLIB_Form(instance, title)
end

#return int status
func FormAppend(int component, string text)
    return MIDPLIB_FormAppend(component, text)
end

#return int status
func FormClear(int component)
     return MIDPLIB_FormClear(component)
end

#return int component id
func Canvas(int instance)
    return MIDPLIB_Canvas(instance)
end


#constraint modes
int CONSTRAINT_ANY = 0
int CONSTRAINT_EMAILADDR = 1
int CONSTRAINT_NUMERIC = 2
int CONSTRAINT_PHONENUMER = 3
int CONSTRAINT_URL = 4
int CONSTRAINT_DECIMAL = 5

#Calendar fields
int ERA = 0
int YEAR = 1
int MONTH = 2
int WEEK_OF_YEAR = 3
int WEEK_OF_MONTH = 4
int DATE = 5
int DAY_OF_MONTH = 5
int DAY_OF_YEAR = 6
int DAY_OF_WEEK = 7
int DAY_OF_WEEK_IN_MONTH = 8
int AM_PM = 9
int HOUR = 10
int HOUR_OF_DAY = 11
int MINUTE = 12
int SECOND = 13
int MILLISECOND = 14
int ZONE_OFFSET = 15
int DST_OFFSET = 16
int FIELD_COUNT = 17
int SUNDAY = 1
int MONDAY = 2
int TUESDAY = 3
int WEDNESDAY = 4
int THURSDAY = 5
int FRIDAY = 6
int SATURDAY = 7
int JANUARY = 0
int FEBRUARY = 1
int MARCH = 2
int APRIL = 3
int MAY = 4
int JUNE = 5
int JULY = 6
int AUGUST = 7
int SEPTEMBER = 8
int OCTOBER = 9
int NOVEMBER = 10
int DECEMBER = 11
int UNDECIMBER = 12
int AM = 0
int PM = 1

#Alert
int ALERT_INFO = 0
int ALERT_WARNING = 1
int ALERT_ALARM = 2

#system variable definition
string dpdlMIDPUIVersion = " <= 2.0"

#start Library execution
