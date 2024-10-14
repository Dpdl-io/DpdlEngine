# DpdlAINerd (DAN) AI language plug-in

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	


## DpdlAINerd (DAN) - Dpdl AI language plug-in for AI generative code


'**DpdlAINerd**' (**DAN**) is a dedicated Dpdl language plug-in for <ins>**AI generative code**</ins>.

The plug-in provided allows to <ins>**automatically generate and execute** embedded code sections in various programming languages within Dpdl</ins> via a configurable **AI engine**. Currently the OpenAI engine is supported, others like Google Vertex AI, CodePal, etc.. will be integrated in near future.

More generally, the plug-in <ins>allows also to **generate content or data**</ins> used during the code execution.

This enables to write code faster in the prototyping phase and allows also to generate data on the fly needed for example for development or testing.

The 'DpdlAINerd' (**DAN**) Dpdl language plug-in can be embedded and executed within Dpdl via the keyword **`>>ai`**

see Dpdl examples in: [./DpdlLibs/ai](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/ai)


### Modes of execution:

The DAN language plug-in can be used in 2 different modes:

### 1) Generate a new Dpdl source file containing the generated code (Mode 1)

By executing the Dpdl script with the '@gen' parameter (see below), a new Dpdl source file (with '*_gen' suffix) is created containing the automatically AI generated code sections.

This mode allows to check and adapt the generated code before executing it.

#### Example:

The following example shows how code can be generated from a natural language description, in this case a function to sort a list of numbers using the 'Clojure' programming language:

```python
println("Dpdl example with generative AI code...")

string numbers_param = "1 43 63 634 64 21 3 6 346 34 1000 23 55"
dpdl_stack_push("dpdlbuf_result", numbers_param)

>>ai
	>>clj
	Write a functions with clojure programming language named 'dpdl_main', with namespace 'dpdl', accepts as parameter a java array
	of objects, take the first string containing numbers, sorts the numbers and returns a string with the numbers sorted.
<<

int exit_code = dpdl_exit_code()
println("embedded ai generated exit code: " + exit_code)
```

#### Example result:

When executed, the Dpdl code above generates the following Dpdl source file.

```python
println("Dpdl example with generative AI code...")

string numbers_param = "1 43 63 634 64 21 3 6 346 34 1000 23 55"
dpdl_stack_push("dpdlbuf_result", numbers_param)

>>clj
(ns dpdl)

(defn dpdl_main [^objects objs]
  (let [nums-str (first objs)
        nums (map #(Long/parseLong %) (clojure.string/split nums-str #"\s+"))]
    (->> nums
         sort
         (map str)
         (clojure.string/join " "))))
<<

int exit_code = dpdl_exit_code()
println("embedded ai generated exit code: " + exit_code)
```

In this case the generagted code was ready to execute right away, with no adaptions required, giving No errors:

### 2) Generate and access generated content or data directly (Mode 2)

The DAN Dpdl language plug-in can also be used to generate content or data used in the code execution, eg. a test file

#### Example for data generation:

This code generates a json file on-the fly for testing purposes:

```python
println("generating a json file with AI....")

>>ai
generate a sample json file which contains all fields for a personal identity document (ID)
<<

int exit_code = dpdl_exit_code()
println("generative ai exit code: " + exit_code)

string my_test_json = dpdl_stack_buf_get("dpdlainerd_buf")

println("this is my sample json:")
println(my_test_json)
```

when executed the code above generates the following output:
```
this is my sample json:
{
   "id_number": "123456789",
   "first_name": "John",
   "last_name": "Doe",
   "birth_date": "1990-01-01",
   "sex": "male",
   "nationality": "American",
   "issue_date": "2021-01-01",
   "expiry_date": "2031-01-01",
   "issuing_authority": "State Department of Motor Vehicles",
   "address": {
      "street": "123 Main St",
      "city": "Anytown",
      "state": "CA",
      "postal_code": "12345"
   },
   "photo_url": "https://example.com/photo.jpg"
}
```

#### Example for alternative code generation

The following example shows how code can be generated and than executed in a later point in the program.

**Example:**
```python
println("testing generative AI code with Dpdl....")

dpdl_stack_var_put("my_message", "Hello generative AI from Dpdl")

>>ai
	Write a console application in C that converts the following string to upper case: {{my_message}}
<<
int exit_code = dpdl_exit_code()
println("generated ai code exit code: " + exit_code)

string my_code = dpdl_stack_buf_get("dpdlainerd_buf")

dpdl_stack_var_put("my_code", my_code)

println("executing generated code...")

dpdl_stack_push("dpdl:applyvars", "dpdl:compile")

>>c
{{my_code}}
<<

exit_code = dpdl_exit_code()
println("embedded C code exit code: " + exit_code)

```

As you see Dpdl allows a very flexible way to dynamically generate and execute code via AI


### How to execute

#### Generate a new file that contains generated code

The code generation function can be activated by providing the '@gen' parameter to the code execution command.

The DpdlEngine will generate a new file, in the same directory, with the '_gen' suffix.

**Example:**
```
java --add-opens java.base/sun.net.www.protocol.http=ALL-UNNAMED --add-opens java.base/sun.net.www.protocol.https=ALL-UNNAMED --add-opens java.base/java.lang=ALL-UNNAMED --add-opens java.base/java.util=ALL-UNNAMED -jar DpdlEngine_V1.0_release.jar -load ai/dpdlAITest.h @gen
```

NOTE: Currently, in the 'DpdlEngine lite' shareware/demo release the execution <ins>requires you to enter a password</ins> at each generation. A full registered version is required to disable the password prompt (password is **`123456`**)


#### Generating content or data on-the-fly inside the code execution

Content or data can also be generated on-the-fly with the DAN plug-in.

When embedding a natural language description with the keyword **`>>ai`** the content generated is available on the dpdl stack and can be
retrieved with the key **`dpdlainerd_buf`**

NOTE: The 'DpdlEngine lite' shareware/demo release has a response buffer limit of 500 characters only, the content is trimmed when exceeded.
A full registered version of Dpdl is required to have an unlimited buffer size.


### Supported AI engines

Currently 'DpdlAINerd' supports the following AI engines:

- OpenAI (Model: gpt-3.5-turbo)
- Google Vertex AI (supported soon)
- CodePal (supported soon)
- *support for more engines will follow


The engine used can be configured via the 'DpdlPlugins.ini' configuration file, along with the appropriate access key 

DpdlPlugins.ini sample:
```
[DpdlAINerd]
DAN_ENGINE=openai
DAN_API_KEY=put_your_openai_api_key_here
```


### Current status

DpdlAINerd is in a very first stage of development with huge improvements and features foreseen in near future. 

Stand-by for the coming innovation we're bringing to Dpdl with generative code.

The plan is to release the 'DpdlAINerd' language plug-in as fully Open Source software.


### Next integrations

- Image generation for test data
- Speech to Code generation 

 


