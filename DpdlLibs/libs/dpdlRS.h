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
# Filename: dpdlRS.h
# This library provides functions accessing Dpdl/J2ME/JavaME record store functions
#
# NOTE: When loading this module as part of dpdlMIDP.h, you have to include it in dpdlMIDPRS.h and remove all contained declarations.
#       This is useful to reuse the same Dpdl script on different targets (Linux/Win32 vs. MIDP/J2ME/JavaME).
#

func createRS(string name, int auth_mode, int write, int create)
    return DPDLLIB_openRS(name, auth_mode, write, create)
end

func closeRS(int rs_id)
    return DPDLLIB_closeRS(rs_id)
end

#return int status
func deleteRS(string rs_name)
    return DPDLLIB_deleteRS(rs_name)
end

#return int nr Records, -1 if error
func getNrRecords(int rs_id)
    return DPDLLIB_getNumRecords(rs_id)
end

#return int status
func enumRecords(int rs_id, int keepupdated)
      return DPDLLIB_enumRecords(rs_id, keepupdated)
end

#return int status
func resetEnum(int rs_id)
      return DPDLLIB_resetEnum(rs_id)
end

#return int nr Records
func getEnumNrRecords(int rs_id)
      return DPDLLIB_getEnumNumRecords(rs_id)
end

#return int next record ID
func getNextRecordID(int rs_id)
    return DPDLLIB_getNextRecordID(rs_id)
end

#return int record id added
func addRecord(int rs_id, string data)
    return DPDLLIB_addRSData(rs_id, data)
end

#return string record
func getRecord(int rs_id, int rec_id)
    return DPDLLIB_getRSData(rs_id, rec_id)
end

#return int status
func setRecord(int rs_id, int rec_id, string data)
    return DPDLLIB_setRSRecord(rs_id, rec_id, data)
end

#return int bytes
func getRecordSize(int rs_id, int rec_id)
    return DPDLLIB_getRecordSize(rs_id, rec_id)
end

#return int status
func deleteRecord(int rs_id, int rec_id)
    return DPDLLIB_deleteRSData(rs_id, rec_id)
end

#RS modes
int AUTHMODE_ANY = 1
int AUTHMODE_PRIVATE = 0
