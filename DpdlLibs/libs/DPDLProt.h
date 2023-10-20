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
# Filename: DPDLProt.h
# This library provides some standard commands to interact with a Dpdl console
#

func init()
    println("Dpdl command protocol loaded")
end

string dpdl_echo = "dpdl_echo"
string dpdl_list = "dpdl_list"
string dpdl_install = "dpdl_install"
string dpdl_get = "dpdl_get"
string dpdl_update = "dpdl_update"
string dpdl_restore = "dpdl_restore"
string dpdl_run = "dpdl_run"
string dpdl_reboot = "dpdl_reboot"

string dpdl_console_cmd = "dpdl_console_cmd"
string dpdl_ok_cmd = "dpdl_ok_cmd"
string dpdl_end_cmd = "dpdl_end_cmd"
string dpdl_exec_cmd = "dpdl_exec_cmd"
string dpdl_save_cmd = "dpdl_save_cmd"
string dpdl_reg_cmd = "dpdl_reg_cmd"
string dpdl_savers_cmd = "dpdl_savers_cmd"
string dpdl_del_cmd = "dpdl_del_cmd"

#module entry point
init()


