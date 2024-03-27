# File: js/dpdlQJsPoint.h
#
# Example:
# This Dpdl script executes an embedded 'qjs' javascript that make use of a Point class implemented in a native C library
# The coordinates of the poins are pushed on the dpdl stack
# This javascript example is from the QuickJS repository https://github.com/bellard/quickjs/tree/master/examples
#
# Note: point.c needs to be compiled first
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedded qjs with import of native library...")

dpdl_stack_push(3, 6, 9, 12)
>>qjs

import { Point } from "./DpdlLibs/js/point.so";

function assert(b, str)
{
    if (b) {
        return;
    } else {
        throw Error("assertion failed: " + str);
    }
}

class ColorPoint extends Point {
    constructor(x, y, color) {
        super(x, y);
        this.color = color;
    }
    get_color() {
        return this.color;
    }
};

function main(point1x, point1y, point2x, point2y)
{
    var pt, pt2;
    pt = new Point(point1x, point1y);
    assert(pt.x === 3);
    assert(pt.y === 6);
    std.printf("Point.x=%d Point.y=%d\n", pt.x, pt.y);
    pt.x = 4;
    //assert(pt.x === 4);
    std.printf("pt.norm()=%f\n", pt.norm());
    std.printf("Point.x=%d Point.y=%d\n", pt.x, pt.y);

    pt2 = new ColorPoint(point2x, point2y, 0xac33ff);
    assert(pt2.x === 9);
    assert(pt2.y === 12);
    assert(pt2.color === 0xac33ff);
    assert(pt2.get_color() === 0xac33ff);
    std.printf("Point.color=%x\n", pt2.get_color());
}

console.log('-------------------------------------');
var p1x, p1y, p2x, p2y;
if(scriptArgs.length >= 3){
	p1x = scriptArgs[0];
	p1y = scriptArgs[1];
	p2x = scriptArgs[2];
	p2y = scriptArgs[3];
}else{
	p1x = 3;
	p1y = 6;
	p2x = 9;
	p2y = 12;
}
std.printf("p1x=%d, p1y=%d \n", p1x, p1y);
std.printf("p2x=%d, p2y=%d \n", p2x, p2y);
main(p1x, p1y, p2x, p2y);
console.log('-------------------------------------');
<<

int exit_code = dpdl_exit_code()
println("Dpdl qjs exited with exit code: " + exit_code)
