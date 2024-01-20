# File: ui/dpdlGUIJavaFX.h
#
# Example: Dpdl script that uses JavaFX library to render GUI elements and graphics via an fxml definition
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('thread')

func dpdl_javafx_start(object stage)
	stage.setTitle("Example: registration form with Dpdl")
	stage.setScene(scene)
	stage.show()
end

func handleButtonAction(object event)
	println("button pressed")
	object type = event.getEventType()
	object cmd_name = type.getName()
	println("cmd: " + cmd_name)
end

# main
println("testing Dpdl using JavaFX to create amazing UI")

println("starting javafx runtime...")

object runtime = getClass("Platform")
runtime.startup(thread.getRunnable())

object file = loadObj("File", "./DpdlLibs/ui/fxml/myGUIreg.fxml")
object file_uri = file.toURI()
object fxml_url = file_uri.toURL()

object fxml_load = getClass("FXMLLoader")
object parent_root = fxml_load.load(fxml_url)

raise(parent_root, "Error in loading fxml definition")

object scene = loadObj("Scene", parent_root)

println("starting App....")
object app = loadObj("DpdlJavaFXApp")
app.initApp()
