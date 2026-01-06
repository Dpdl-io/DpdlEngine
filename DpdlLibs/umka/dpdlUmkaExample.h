# File: umka/dpdlUmkaExample.h
#
# Example:
#		Dpdl example that executes an 'embedded code section' in Umka lang that implements a fractal demo (from Umka examples)
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing embedded Umka code section...")

>>umka
fn dpdl_main() {
	const (
		yMin = -0.2
		yMax =  0.1
		xMin = -1.5
		xMax = -1.1
	)

	for yPixel := 0; yPixel < 40; yPixel++ {
	  y0 := (yPixel / 40.0) * (yMax - yMin) + yMin

	  for xPixel := 0; xPixel < 79; xPixel++ {
		x0 := (xPixel / 78.0) * (xMax - xMin) + xMin
		x, y := x0, y0
		pixel := ' '

		for iter := 0; iter < 80; iter++ {
		  x, y = x * x - y * y + x0, 2 * x * y + y0

		  if x * x + y * y > 4 {
			const pixels = " .:;+=xX$&"
			pixel = pixels[iter / 8]
			break
		  }
		}
		printf("%c", pixel)
	  }
	  printf("\n")
	}
}
<<
int exit_code = dpdl_exit_code()

println("embedded code section exit code: " + exit_code)
