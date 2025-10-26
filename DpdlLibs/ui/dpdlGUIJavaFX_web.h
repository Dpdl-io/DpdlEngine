# File: ui/dpdlGUIJavaFX_web.h
#
# Example: Dpdl app that uses JavaFX library to display a website within a WebView
#
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('thread')

func dpdl_javafx_start(object stage)
	stage.setTitle("Dpdl Web View")

	println("loading WebView")

	object browser = new("WebView")
	object web_engine = browser.getEngine()

	web_engine.load("https://www.dpdl.io")

	object root_child = root.getChildren()
	root_child.add(browser)


	object color = getObj("paint.Color")

	object scene = new("Scene", browser, 750.0d, 800.0d, color.web("#666970"))

	stage.setScene(scene)
	stage.show()
end

# main
println("starting web app...")

object runtime = getObj("Platform")
runtime.startup(thread.getRunnable())

object root = new("scene.Group")
object style = root.getStyleClass()

style.add("browser")

println("starting App....")

object app = new("DpdlJavaFXApp")
app.initApp()
