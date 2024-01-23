# File: ui/dpdlGUIJavaFX_web.h
#
# Example: Dpdl app that uses JavaFX library to display a website within a WebView
#			FXML file: https://github.com/Dpdl-io/DpdlEngine/blob/main/DpdlLibs/ui/fxml/myGUIreg.fxml
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('thread')

func dpdl_javafx_start(object stage)
	stage.setTitle("Dpdl Web View")

	println("loading WebView")

	object browser = loadObj("WebView")
	object web_engine = browser.getEngine()

	web_engine.load("https://www.dpdl.io")

	object root_child = root.getChildren()
	root_child.add(browser)


	object color = getClass("paint.Color")

	object scene = loadObj("Scene", browser, 750.0d, 800.0d, color.web("#666970"))

	stage.setScene(scene)
	stage.show()
end

# main
println("starting web app...")

object runtime = getClass("Platform")
runtime.startup(thread.getRunnable())

object root = loadObj("scene.Group")
object style = root.getStyleClass()

style.add("browser")

println("starting App....")
object app = loadObj("DpdlJavaFXApp")
app.initApp()
