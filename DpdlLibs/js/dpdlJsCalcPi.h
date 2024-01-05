# File: js/dpdlJsCalcPi.h
#
# Example:
# This Dpdl script executes an embedded 'qjs' javascript that calculates n (suppied as argument) digits of PI number
# The javascript code is from Fabrice Bellard's QuickJS repository (https://github.com/bellard/quickjs/blob/master/examples/pi_bigint.js)
#
# Note: This script exeeds the  'embedded code limit' on the trial version of 'DpdlEngine lite', in this case you may need to short it to fit 100 lines of code
#
# Author: AC
# e-mail: ac@dpdl.io
#
#

# main
println("testing quick js...")

dpdl_stack_push("dpdlbuf_var1", 1000)
>>qjs
"use strict";

function floor_log2(a)
{
    var k_max, a1, k, i;
    k_max = 0n;
    while ((a >> (2n ** k_max)) != 0n) {
        k_max++;
    }
    k = 0n;
    a1 = a;
    for(i = k_max - 1n; i >= 0n; i--) {
        a1 = a >> (2n ** i);
        if (a1 != 0n) {
            a = a1;
            k |= (1n << i);
        }
    }
    return k;
}

function ceil_log2(a)
{
    return floor_log2(a - 1n) + 1n;
}

function int_sqrt(a)
{
    var l, u, s;
    if (a == 0n)
        return a;
    l = ceil_log2(a);
    u = 1n << ((l + 1n) / 2n);
    for(;;) {
        s = u;
        u = ((a / s) + s) / 2n;
        if (u >= s)
            break;
    }
    return s;
}

/* return pi * 2**prec */
function calc_pi(prec) {
    const CHUD_A = 13591409n;
    const CHUD_B = 545140134n;
    const CHUD_C = 640320n;
    const CHUD_C3 = 10939058860032000n; /* C^3/24 */
    const CHUD_BITS_PER_TERM = 47.11041313821584202247; /* log2(C/12)*3 */

    /* return [P, Q, G] */
    function chud_bs(a, b, need_G) {
        var c, P, Q, G, P1, Q1, G1, P2, Q2, G2;
        if (a == (b - 1n)) {
            G = (2n * b - 1n) * (6n * b - 1n) * (6n * b - 5n);
            P = G * (CHUD_B * b + CHUD_A);
            if (b & 1n)
                P = -P;
            Q = b * b * b * CHUD_C3;
        } else {
            c = (a + b) >> 1n;
            [P1, Q1, G1] = chud_bs(a, c, true);
            [P2, Q2, G2] = chud_bs(c, b, need_G);
            P = P1 * Q2 + P2 * G1;
            Q = Q1 * Q2;
            if (need_G)
                G = G1 * G2;
            else
                G = 0n;
        }
        return [P, Q, G];
    }

    var n, P, Q, G;
    /* number of serie terms */
    n = BigInt(Math.ceil(Number(prec) / CHUD_BITS_PER_TERM)) + 10n;
    [P, Q, G] = chud_bs(0n, n, false);
    Q = (CHUD_C / 12n) * (Q << prec) / (P + Q * CHUD_A);
    G = int_sqrt(CHUD_C << (2n * prec));
    return (Q * G) >> prec;
}

function main(args) {
	console.log('PI computation in Javascript using the QuickJS bigdecimal type');
	console.log("");
    var r, n_digits, n_bits, out;
    if (args.length < 1) {
        print("usage: pi n_digits");
        return;
    }
    n_digits = args[0] | 0;

    /* we add more bits to reduce the probability of bad rounding for
      the last digits */
    n_bits = BigInt(Math.ceil(n_digits * Math.log2(10))) + 32n;
    r = calc_pi(n_bits);
    r = ((10n ** BigInt(n_digits)) * r) >> n_bits;
    out = r.toString();
    //print(out[0] + "." + out.slice(1));
    dpdl_stack_buf_put(out[0] + "." + out.slice(1))
}

var args;
if (typeof scriptArgs != "undefined") {
    args = scriptArgs;
    //args.shift();
} else if (typeof arguments != "undefined") {
    args = arguments;
} else {
    /* default: 1000 digits */
    args=[1000];
}

main(args);
<<
int exit_code = dpdl_exit_code()
println("Dpdl qjs terminated with exit code: " + exit_code)

string res_buf = dpdl_stack_buf_get("dpdlbuf_var1")
println("PI Number result: ")
println(res_buf)

