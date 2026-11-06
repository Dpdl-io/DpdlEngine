# File: tcl/dpdlTclExample.h
#
# Example: dpdl example that makes use of an 'embedded code section' in 'Tcl' code to implement a heapsort algorithm
#
# author: A.Costa
# e-mail: ac@dpdl.io
#

println("testing embedded code section in 'Tcl' ...")

>>tcl
	set IM 139968
	set IA   3877
	set IC  29573

	set last 42

	proc make_gen_random {} {
		global IM IA IC
		set params [list IM $IM IA $IA IC $IC]
		set body [string map $params {
			global last
			expr {($max * [set last [expr {($last * IA + IC) % IM}]]) / IM}
		}]
		proc gen_random {max} $body
	}

	proc heapsort {ra_name} {
		upvar 1 $ra_name ra
		set n [llength $ra]
		set l [expr {$n / 2}]
		set ir [expr {$n - 1}]
		while 1 {
			if {$l} {
				set rra [lindex $ra [incr l -1]]
			} else {
			set rra [lindex $ra $ir]
			lset ra $ir [lindex $ra 0]
			if {[incr ir -1] == 0} {
					lset ra 0 $rra
			break
				}
			}
		set i $l
		set j [expr {(2 * $l) + 1}]
			while {$j <= $ir} {
			set tmp [lindex $ra $j]
			if {$j < $ir} {
			if {$tmp < [lindex $ra [expr {$j + 1}]]} {
				set tmp [lindex $ra [incr j]]
			}
			}
				if {$rra >= $tmp} {
			break
			}
			lset ra $i $tmp
			incr j [set i $j]
			}
			lset ra $i $rra
		}
	}

	proc dpdl_main {params} {
		set n 6100
		make_gen_random

		set data {}
		for {set i 1} {$i <= $n} {incr i} {
		lappend data [gen_random 1.0]
		}
		heapsort data
	}
<<
int exit_code = dpdl_exit_code()

println("embedded Tcl code section exit code: " + exit_code)

println("finished")
