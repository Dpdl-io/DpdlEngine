# File: julia/dpdlJuliaPlot.h
#
# Example: This Dpdl script executes an embedded Julia script that downloads data via HTTP and saves the result in a file
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main

println("Testing HTTP get data with embedded Julia code...")

>>julia
using JSON
using HTTP

function download_content_from_url(json_file::String)
	println("parsing json...")
    data = JSON.parse(json_file)
	println("done")

    url = data["url_download"]

    response = HTTP.get(url)

    if response.status == 200
        filename = "./Test/downloaded_content.txt"
        open(filename, "w") do file
            write(file, response.body)
        end
        println("Content downloaded successfully to $filename")
    else
        println("Failed to download content. HTTP status code: $(response.status)")
    end
end

json = "{    \"url_download\": \"http://www.seesolutions.it\"   }"
println("download data in json: ")
println(json)
download_content_from_url(json)


dispose_status = @ccall dpdl_julia_dispose()::Int32
return 1
<<

int exit_code = dpdl_exit_code()
println("embedded julia code finished with exit code: " + exit_code)
