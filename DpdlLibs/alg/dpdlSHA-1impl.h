# File: alg/dpdlSHA-1impl.h
#
# Example: This is an implementation of the SHA-1 algorithm, ported to Dpdl from https://github.com/rcgabitanan/SHA-1-Implementation
#
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#
# Values in Hex:
#				H0 = 0x67452301
#				H1 = 0xEFCDAB89
#				H2 = 0x98BADCFE
#				H3 = 0x10325476
#				H4 = 0xC3D2E1F0
#
#				j < 20 -> k = 0x5A827999
#				j < 40 -> k = 0x6ED9EBA1
#				j < 60 -> k = 0x8F1BBCDC
#				j > 60 -> k = 0xCA62C1D6
#


int W[80]

int H0 = 1732584193
int H1 =  -271733879
int H2 = -1732584194
int H3 = 271733878
int H4 = -1009589776

int H[] = {H0, H1, H2, H3, H4}

int a, b, c, d, e


func toHexStr(var arr_val) string
	string hex_str = ""
	object integer = getObj("Integer")
	int i = 0
	while(i <= 4)
		hex_str = hex_str + integer.toHexString(arr_val[i])
		i=i+1
	endwhile
	return hex_str
end

func leftRotate(int value, int bits) int
	return (value << bits) | (value >>> (32 - bits))
end


func rotate(int offset) void
	int j = 0
	for(j < 16)
		W[j] = ((paddedMessage[offset + (j << 2)] & 255) << 24) | ((paddedMessage[offset + (j << 2) + 1] & 255) << 16) | ((paddedMessage[offset + (j << 2) + 2] & 255) << 8) | (paddedMessage[offset + (j << 2) + 3] & 255)
		j=j+1
	endfor

	j = 16
	for(j < 80)
		W[j] = leftRotate((W[j - 3] ^ W[j - 8] ^ W[j - 14] ^ W[j - 16]), 1)
		j=j+1
	endfor

	a = H[0]
	b = H[1]
	c = H[2]
	d = H[3]
	e = H[4]

	int f, k, temp
	j = 0
	for(j < 80)
		if(j < 20)
			f = (b & c) | ((~b) & d)
			k = 1518500249
		elseif(j < 40)
			f = b ^ c ^ d
			k = 1859775393
		elseif(j < 60)
			f = (b & c) | (b & d) | (c & d)
			k = -1894007588
		else
			f = b ^ c ^ d
			k = -899497514
		fi

		temp = leftRotate(a, 5) + f + e + k + W[j]
		e = d
		d = c
		c = leftRotate(b, 30)
		b = a
		a = temp

		j=j+1
	endfor
end

# main
println("testing SHA-1 algorithm on data string...")
println("")

string mydata = "This is my message HELLO ALGORITHM from DPDL"

println("data: " + mydata)

# we cast is to an object so we can access all methods of a JRE 'String'
object data = mydata

object messageBytes = data.getBytes()

int messageLenBytes = strlen(mydata)
int numBlocks = ((messageLenBytes + 8) >>> 6) + 1
int totalLen = numBlocks << 6

println("messageLenBytes: " + messageLenBytes + " totalLen: " + totalLen)

byte paddedMessage[totalLen]

println("copying buffer...")

object system = getObj("System")

system.arraycopy(messageBytes, 0, paddedMessage, 0, messageLenBytes)

println("done")

# Padding the message
paddedMessage[messageLenBytes] = to_byte(-128)

int messageLenBits = messageLenBytes << 3

int i
while(i < 8)
	paddedMessage[totalLen - 1 - i] = to_byte(((messageLenBits >>> (8 * i)) & 255))
	i=i+1
endwhile

println("computing hash...")

int offset
i = 0
for(i < numBlocks)
	offset = i << 6

	rotate(offset)

	H[0] = H[0] + a
	H[1] = H[1] + b
	H[2] = H[2] + c
	H[3] = H[3] + d
	H[4] = H[4] + e

	i=i+1
endfor

println("done")

println("converting hash to hex...")

println("SHA-1 hash: " + toHexStr(H))

# to highlight the powerful Dpdl features, we print the same hex string also via embedded java code

dpdl_stack_push(H)
>>java

String str = String.format("%08x%08x%08x%08x%08x", arg0[0], arg0[1], arg0[2], arg0[3], arg0[4]);

System.out.println("SHA-1 hash2: " + str);

return 1;

<<
int exit_code = dpdl_exit_code()

raise(exit_code, "Error in executing embedded java code")

println("finished")
