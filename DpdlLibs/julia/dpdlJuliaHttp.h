# File: julia/dpdlJuliaHttp.h
#
# Example: This Dpdl script executes an embedded Julia script that downloads data via HTTP and saves the result in a file
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("Testing HTTP get data with embedded Julia code...")

string url_to_download_1 = "{    \"file_name\": \"see_solutions.html\" , \"url_download\": \"http://www.seesolutions.it\"    }"
string url_to_download_2 = "{    \"file_name\": \"info_see.jpg\" , \"url_download\": \"http://www.seesolutions.it/images/intro_see.jpg\"    }"

object url1 = new("String", url_to_download_1)
object url2 = new("String", url_to_download_2)

dpdl_stack_push(url1, url2)
>>julia
using JSON
using HTTP

function download_content_from_url(json_file::String)
	println("parsing json data...")
    data = JSON.parse(json_file)
	println("done")
	println("")

	file_n = data["file_name"]
	url = data["url_download"]

	println("file: $file_n")
	println("url: $url")

	println("")

	response = HTTP.get(url)

    if response.status == 200
		println("data downloaded successfully, saving file...")

        filename = "./Test/$file_n"
        open(filename, "w") do file
            write(file, response.body)
        end

        println("Content saved in file $filename")
    else
		println("Failed to download content. HTTP status code: $(response.status)")
    end
end

function dpdl_main(param)
	for p in param
		println("param: $p")
		json = p
		println("download data contained in json: ")
		println(json)
		download_content_from_url(json)
	end

	dispose_status = @ccall dpdl_julia_dispose()::Int32

	return 1
end

<<

int exit_code = dpdl_exit_code()
println("embedded julia code finished with exit code: " + exit_code)
