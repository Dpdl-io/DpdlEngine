# DpdlAI

<p align="left">
	<img src="https://www.dpdl.io/images/dpdl-io_blue.png" width="35%">
</p>

				www.dpdl.io

by
**SEE Solutions**
&copy;	


## *Dpdl language plug-in* for AI generative code - **DpdlAINerd** (DAN)


'**DpdlAINerd**' (**DAN**) is a dedicated *Dpdl language plug-in* for <ins>**AI generative code**</ins> and <ins>**data**</ins>.

The provided *Dpdl language plug-in* allows to <ins>**automatically generate and execute**</ins> *embedded code sections* in <ins>various programming languages within Dpdl</ins> via a configurable **AI engines**, available either locally or via dedicated public services.

More generally, the *Dpdl language plug-in* allows for example also to <ins>**generate any kind of content or data**</ins> used during the code execution.

It includes a set of *knowledge* **Skills** that can be used for generating specific code, for example to generate valid and correct dpdl code. 

This enables to write code faster in the prototyping phase and it allows also to generate data on the fly needed for development or testing purposes.

The '*DpdlAINerd*' (**DAN**) Dpdl language plug-in can be embedded and executed within dpdl code via the keyword **`>>ai`**


```python
println("testing the Dpdl language plugin 'DpdlAINerd' to automatically generate and execute code...")

>>ai
	>>c
	write a console program in C that implements the famous SNAKE game, with colorful graphics using ncurses colors
<<
int exit_code = dpdl_exit_code()

raise(exit_code, "Error in generating code from natural language description")

println("exit code: " + exit_code)

println("finished")
```

## Index

* [AI engines](#ai-engines)
* [Modes of execution](#modes-of-execution)
* [Options](#options)
* [Knowledge SKILL definitions](#knowledge-skill-definitions)
* [How to](#how-to)
* [Future Integrations](#future-integrations)


### AI engines

The '*DpdlAINerd*' can provide access to available AI engines via:

- Local AI engine
- Dedicated AI services at www.dpdl.ai
- Third party AI engine services


#### Local AI engine

As part of the *DpdlEngine* setup there is the possibility to request a local AI engine setup instance (based OpenSource components), for deployment on a local PC, workstation, virtual machine or server.

With the provided deployment you can autonomously choose from more than 900 open AI models available, it supports a wide range of AI back-ends, and you can install the models locally with a simple click as needed. 

The '*DpdlAINerd*' plug-in in this case connects only to this local AI engine instance and <ins>all requests and inference run completely locally<ins>.

- All requests are completely processed locally
- Provides access to many open source AI models and AI back-ends
- Management UI for installing and managing models and back-end processes
- comes as option with the *DpdlEngine* distribution

#### Dedicated AI services at www.dpdl.ai

In this case the '*DpdlAINerd*' plug-in connects via RESTful API to the cloud services at www.dpdl.ai

The user can access also a dedicated UI for installing and managing the AI models to be used within dpdl.

The use of this service requires a valid Dpdl Subscription.

<p align="center">
	<img src="https://www.dpdl.io/images/platform/DpdlAI_11.png" width="60%">
</p>

More than 900 open AI models are available

<p align="center">
	<img src="https://www.dpdl.io/images/platform/DpdlAI_22.png" width="60%">
</p>


#### Third party AI engine services

At current state the '*DpdlAINerd*' Dpdl language plug-in supports the following third party AI engines:

- DeepSeek (deepseek)
- OpenAI (openai)
- other OpenAI API compatible engines

The AI engine used can be specified and configured in the file 'DpdlPlugins.ini' under the section '*DpdlAINerd*'


[Index](#index)


### Modes of execution

The DAN language plug-in can be used in 2 different modes:

### 1) Generate a new dpdl source file containing the generated code sections (Mode 1)

By executing the dpdl script with the '@gen' parameter (see below), a new Dpdl source file (with '*_gen' suffix) is created containing the automatically AI generated code sections.

This mode allows to check and adapt the generated code before executing it.

#### Example:

The following example shows how code can be generated from a natural language description, in this case a function to sort a list of numbers using the 'Clojure' programming language:

```python
println("Dpdl example with generative AI code...")

string numbers_param = "1 43 63 634 64 21 3 6 346 34 1000 23 55"

dpdl_stack_push(numbers_param)

>>ai(dpdlbuf_result)
	>>clj
	Write a functions with clojure programming language named 'dpdl_main', with namespace 'dpdl', accepts as parameter a java array
	of objects, take the first string containing numbers, sorts the numbers and returns a string with the numbers sorted.
<<

int exit_code = dpdl_exit_code()

raise(exit_code, "Error in generating code")

println("embedded ai generated exit code: " + exit_code)

string my_result = dpdl_stack_buf_get("dpdlbuf_result")

```

#### Example result:

When executed, the Dpdl code above generates the following Dpdl source file.

```python
println("Dpdl example with generative AI code...")

string numbers_param = "1 43 63 634 64 21 3 6 346 34 1000 23 55"

dpdl_stack_push(numbers_param)

>>clj(dpdlbuf_result)
(ns dpdl)

(defn dpdl_main [^objects objs]
  (let [nums-str (first objs)
        nums (map #(Long/parseLong %) (clojure.string/split nums-str #"\s+"))]
    (->> nums
         sort
         (map str)
         (clojure.string/join " "))))
<<

raise(exit_code, "Error in generating code")

int exit_code = dpdl_exit_code()

println("embedded ai generated exit code: " + exit_code)

string my_result = dpdl_stack_buf_get("dpdlbuf_result")
```

In this case the generagted code was ready to execute right away, with no adaptions required, giving No errors:

### 2) Generate and execute generated code and access content or data directly (Mode 2)

The DAN Dpdl language plug-in can also be used to generate content or data used in the code execution, eg. a test file

#### Example for data generation:

This code generates a json file on-the fly for testing purposes:

```python
println("generating a json file with AI....")

dpdl_stack_push("dpdlai:-engine deepseek -model deepseek-chat")

>>ai(my_data)
	generate a sample json file which contains all fields for a personal identity document (ID)
<<

int exit_code = dpdl_exit_code()
println("generative ai exit code: " + exit_code)

string my_test_json = dpdl_stack_buf_get("my_data")

println("this is my sample json:")
println(my_test_json)
```

when executed the code above generates the following output:

this is my sample json:

```json
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

#### Example for alternative code generation:

The following example shows how code can be generated and than executed in a later point in the program.

**Example:**

```python
println("testing generative AI code with Dpdl....")

dpdl_stack_var_put("my_message", "Hello generative AI from Dpdl")

>>ai(my_code_c)
	Write a console application in C that converts the following string to upper case: {{my_message}}
<<
int exit_code = dpdl_exit_code()

println("generated ai code exit code: " + exit_code)

string my_code = dpdl_stack_buf_get("my_code_c")

dpdl_stack_var_put("my_code", my_code)

println("executing generated code...")

dpdl_stack_push("dpdl:applyvars", "dpdl:compile")

>>c
{{my_code}}
<<

exit_code = dpdl_exit_code()
println("embedded C code exit code: " + exit_code)

```

### more Examples

find more examples here: [./DpdlLibs/ai](https://github.com/Dpdl-io/DpdlEngine/tree/main/DpdlLibs/ai)


[Index](#index)


### Options

The following options can be passed to the '*DpdlAINerd*' plug-in, via the dpdl stack.

* **`engine`** the AI engine to be used -> the naming is mapped in the 'DpdlPlugins.ini' configuration file where related parameters are defined (key, api url, default model etc.)

* **`model`** The name of the model to be used

* **`skill`** The name of the 'skill' definition file (located in folder ./DpdlAI/skills/ ) to be applied in the request

**example:**

```python
println("generating some dpdl code...")

dpdl_stack_push("dpdlai:-engine deepseek -model deepseek-coder-v2-lite-instruct -skill dpdllang")

>>ai(my_code)
	generate a dpdl program that implements the quicksort algorithm
<<

int exit_code = dpdl_exit_code()

println("generative ai exit code: " + exit_code)
```

[Index](#index)


### Knowledge SKILL definitions

Knowledge Skill definitions serve the purpose to add knowledge to the AI engine prior executing a request.

Custom SKILL definitions can be defined for various purposes, and simply placed into a sub-folder  (ex. './DpdlAI/skills/my_custom_skill/SKILL.md')

When executing the '*DpdlAINerd*' plug-in the skill can than be defined as follows:

```python

dpdl_stack_push("dpdlai:-skill dpdl-api")

>>ai

<<

...
```


#### Skills shipped as default along with 'DpdlEngine'

- **`dpdl-lang`** -> knowledge for generating valid **dpdl** code that can be executed
- **`dpdl-api`** -> knowledge about Dpdl APIs and it's usage
- **`dpdl-libgen`** -> knowledge for generating Dpdl import libraries (dpdl and java)
- **`dpdl-lang-plugins`** -> knowledge about the interfaces for generating code for creating '*Dpdl language plug-ins*'
- **`dpdl-agent`** --> knowledge for generating 'Agent' code (dpdl and java)

- **`dpdl-plugin-js`** -> knowledge about the usage of the 'Dpdl language plug-in' for JavaScript


[Index](#index)


### How to

#### Generate a new file that contains generated code

This applies whenever there is the need to generate a new file containing the generated '*embedded code sections*'.

The code generation function can be activated by providing the '@gen' parameter to the code execution command.

The DpdlEngine will generate a new file, in the same directory, with the '_gen' suffix.

**Example:**

```
java -jar DpdlEngine_V1.0_release.jar -load ai/dpdlAITest.h @gen

```

[Index](#index)


### Future Integrations

The *Dpdl language plug-in* **DpdlAINerd** is in active development with huge improvements and features foreseen in near future. 

Stand-by for the coming innovation we're bringing to Dpdl with generative code.

#### some...

- Image generation for test data
- Speech to Code generation 
- Visual diagram/schema to code generation


[Index](#index) 


