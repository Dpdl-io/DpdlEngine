# File: ui/dpdlGUIExample_css.h
#
# Example: Dpdl script that uses JavaFX library to render GUI elements (Labels, Image, Button) via an fxml definition with css
#			FXML file: https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/ui/fxml/myGUIcss.fxml
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('thread')

func dpdl_javafx_start(object stage)
	stage.setTitle("Example GUI with Dpdl using CSS")
	stage.setScene(scene)
	stage.show()
end

func handleButtonAction(object event)
	println("button pressed")
	object type = event.getEventType()
	object cmd_name = type.getName()
	object cmd_source = event.getSource()
	object cmd_id = cmd_source.getId()
	println("cmd: " + cmd_name + " id: " + cmd_id)
end

# main
println("testing Dpdl using JavaFX to create amazing UI")

println("starting javafx runtime...")

object runtime = getObj("Platform")
runtime.startup(thread.getRunnable())

object file = new("File", "./DpdlLibs/ui/fxml/myGUIcss.fxml")
object file_uri = file.toURI()
object fxml_url = file_uri.toURL()

object fxml_load = getObj("FXMLLoader")
object parent_root = fxml_load.load(fxml_url)

raise(parent_root, "Error in loading fxml definition")

println("loading css...")
object css_file = new("File", "./DpdlLibs/ui/fxml/demo.css")
object css_file_uri = css_file.toURI()
object css_file_url = css_file_uri.toURL()
string css_url_str = css_file_url.toExternalForm()

object scene = new("Scene", parent_root, 800.0d, 450.0d)
object scene_css = scene.getStylesheets()
scene_css.add(css_url_str)

println("starting App....")
object app = new("DpdlJavaFXApp")
app.initApp()
