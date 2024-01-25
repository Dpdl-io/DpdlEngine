# File: graphics/dpdl3DJavaFX_molecule.h
#
# Example: Small Dpdl app that uses JavaFX library to render and animate chemical molecules in 3D.
#			This code makes use of a custom java class implementation 'DpdlTestForm.java' located in the folder './java'
#			The example is has bee ported from the Oracle javafx graphics tutorials at https://docs.oracle.com/javase/8/javafx/graphics-tutorial/sampleapp3d.htm#CJAHFAF
#
# Author: A.Costa
# e-mail: ac@dpdl.io
#
#
import('thread')

func dpdl_javafx_start(object stage)
	stage.setTitle("Dpdl Sample Application (Molecule 3D)")

	stage.setScene(scene)
	stage.show()
	scene.setCamera(camera)

end

func handleKeyEvent(object key)
	object key_code = key.getCode()
	int code = key_code.getCode()
	if(code == 90)
		cam2Trans.setX(0.0d)
		cam2Trans.setY(0.0d)
		camera.setTranslateZ(CAMERA_INITIAL_DISTANCE)
		camRotY.setAngle(CAMERA_INITIAL_Y_ANGLE)
		camRotX.setAngle(CAMERA_INITIAL_X_ANGLE)
	elseif(code == 88)
		axisGroup.setVisible(!axisGroup.isVisible())
	elseif(code == 86)
		moleculeGroup.setVisible(!moleculeGroup.isVisible())
	else
		println("unkown key command: " + code + "  press 'Z' 'V' or 'X' ")
	fi
end

func handleMouseEvent(object me)
	mouseOldX = mousePosX
	mouseOldY = mousePosY
	mousePosX = me.getSceneX()
	mousePosY = me.getSceneY()
	mouseDeltaX = (mousePosX - mouseOldX)
	mouseDeltaY = (mousePosY - mouseOldY)

	double modifier = 1.0d

	if (me.isControlDown())
		modifier = CONTROL_MULTIPLIER
	fi
	if (me.isShiftDown())
		modifier = SHIFT_MULTIPLIER
	fi
	if (me.isPrimaryButtonDown())
		camRotY.setAngle(camRotY.getAngle() - (mouseDeltaX * MOUSE_SPEED * modifier * ROTATION_SPEED))
		camRotX.setAngle(camRotX.getAngle() + (mouseDeltaY * MOUSE_SPEED * modifier * ROTATION_SPEED))
	elseif (me.isSecondaryButtonDown())
		double z = camera.getTranslateZ()
		double newZ = z + (mouseDeltaX * MOUSE_SPEED * modifier)
		camera.setTranslateZ(newZ)
	elseif (me.isMiddleButtonDown())
		cam2Trans.setX(cam2Trans.getX() + (mouseDeltaX * MOUSE_SPEED * modifier * TRACK_SPEED))
		cam2Trans.setY(cam2Trans.getY() + (mouseDeltaY * MOUSE_SPEED * modifier * TRACK_SPEED))
	else
		println("unknown mouse command")
	fi

end

func buildCamera()
	println("constructing camera...")

	object root_child = root.getChildren()
	root_child.add(cameraXform)

	object cameraxform_child = cameraXform.getChildren()
	cameraxform_child.add(cameraXform2)

	object cameraxform2_child = cameraXform2.getChildren()
	cameraxform2_child.add(cameraXform3)

	object cameraxform3_child = cameraXform3.getChildren()
	cameraxform3_child.add(camera)

	cameraXform3.setRotateZ(180.0d)

	camera.setNearClip(CAMERA_NEAR_CLIP)
	camera.setFarClip(CAMERA_FAR_CLIP)
	camera.setTranslateZ(CAMERA_INITIAL_DISTANCE)
	cameraXform.setAngleRotRY(CAMERA_INITIAL_Y_ANGLE)
	cameraXform.setAngleRotRX(CAMERA_INITIAL_X_ANGLE)
end

func buildAxes()
	println("constructing axes...")

	object color = getClass("paint.Color")

	object redMaterial = loadObj("PhongMaterial")
	redMaterial.setDiffuseColor(color.DARKRED)
	redMaterial.setSpecularColor(color.RED)

	object greenMaterial = loadObj("PhongMaterial")
	greenMaterial.setDiffuseColor(color.DARKGREEN)
	greenMaterial.setSpecularColor(color.GREEN)

	object blueMaterial = loadObj("PhongMaterial")
	blueMaterial.setDiffuseColor(color.DARKBLUE)
	blueMaterial.setSpecularColor(color.BLUE)

	object xAxis = loadObj("shape.Box", AXIS_LENGTH, 1.0d, 1.0d)
	object yAxis = loadObj("shape.Box", 1.0d, AXIS_LENGTH, 1.0d)
	object zAxis = loadObj("shape.Box", 1.0d, 1.0d, AXIS_LENGTH)

	xAxis.setMaterial(redMaterial)
	yAxis.setMaterial(greenMaterial)
	zAxis.setMaterial(blueMaterial)

	axisGroup.addAllTMP3(xAxis, yAxis, zAxis)

	bool bv = true
	axisGroup.setVisible(bv)

	world.addAllTMP1(axisGroup)
end

func buildMolecule()
	println("building molecules...")

	object color = getClass("paint.Color")

	object redMaterial = loadObj("PhongMaterial")
	redMaterial.setDiffuseColor(color.DARKRED)
	redMaterial.setSpecularColor(color.RED)

	object whiteMaterial = loadObj("PhongMaterial")
	whiteMaterial.setDiffuseColor(color.WHITE)
	whiteMaterial.setSpecularColor(color.LIGHTBLUE)

	object greyMaterial = loadObj("PhongMaterial")
	greyMaterial.setDiffuseColor(color.DARKGREY)
	greyMaterial.setSpecularColor(color.GREY)

	object moleculeXform = loadObj("DpdlTestForm")
	object oxygenXform = loadObj("DpdlTestForm")
	object hydrogen1SideXform = loadObj("DpdlTestForm")
	object hydrogen1Xform = loadObj("DpdlTestForm")
	object hydrogen2SideXform = loadObj("DpdlTestForm")
	object hydrogen2Xform = loadObj("DpdlTestForm")

	object oxygenSphere = loadObj("Sphere", 40.0d)
	oxygenSphere.setMaterial(redMaterial)

	object hydrogen1Sphere = loadObj("Sphere", 30.0d)
	hydrogen1Sphere.setMaterial(whiteMaterial)
	hydrogen1Sphere.setTranslateX(0.0d)

	object hydrogen2Sphere = loadObj("Sphere", 30.0d)
	hydrogen2Sphere.setMaterial(whiteMaterial)
	hydrogen2Sphere.setTranslateZ(0.0d)

	object rotate = getClass("Rotate")

	object bond1Cylinder = loadObj("Cylinder", 5.0d, 100.0d)
	bond1Cylinder.setMaterial(greyMaterial)
	bond1Cylinder.setTranslateX(50.0d)
	bond1Cylinder.setRotationAxis(rotate.Z_AXIS)
	bond1Cylinder.setRotate(90.0d)

	object bond2Cylinder = loadObj("Cylinder", 5.0d, 100.0d)
	bond2Cylinder.setMaterial(greyMaterial)
	bond2Cylinder.setTranslateX(50.0d)
	bond2Cylinder.setRotationAxis(rotate.Z_AXIS)
	bond2Cylinder.setRotate(90.0d)

	object moleculeXform_child = moleculeXform.getChildren()
	moleculeXform_child.add(oxygenXform)
	moleculeXform_child.add(hydrogen1SideXform)
	moleculeXform_child.add(hydrogen2SideXform)

	object oxygenXform_child = oxygenXform.getChildren()
	oxygenXform_child.add(oxygenSphere)

	object hydrogen1SideXform_child = hydrogen1SideXform.getChildren()
	object hydrogen2SideXform_child = hydrogen2SideXform.getChildren()
	hydrogen1SideXform_child.add(hydrogen1Xform)
	hydrogen2SideXform_child.add(hydrogen2Xform)

	object hydrogen1Xform_child = hydrogen1Xform.getChildren()
	hydrogen1Xform_child.add(hydrogen1Sphere)

	object hydrogen2Xform_child = hydrogen2Xform.getChildren()
	hydrogen2Xform_child.add(hydrogen2Sphere)

	hydrogen1SideXform_child = hydrogen1SideXform.getChildren()
	hydrogen1SideXform_child.add(bond1Cylinder)

	hydrogen2SideXform_child = hydrogen2SideXform.getChildren()
	hydrogen2SideXform_child.add(bond2Cylinder)

	hydrogen1Xform.setTx(100.0d)
	hydrogen2Xform.setTx(100.0d)
	hydrogen2SideXform.setRotateY(HYDROGEN_ANGLE)

	moleculeGroup.addAllTMP1(moleculeXform)
	world.addAllTMP1(moleculeGroup)
end

double CAMERA_INITIAL_DISTANCE = -450.0d
double CAMERA_INITIAL_X_ANGLE = 70.0d
double CAMERA_INITIAL_Y_ANGLE = 320.0d
double CAMERA_NEAR_CLIP = 0.1d
double CAMERA_FAR_CLIP = 10000.0d
double AXIS_LENGTH = 250.0d
double HYDROGEN_ANGLE = 104.5d
double CONTROL_MULTIPLIER = 0.1d
double SHIFT_MULTIPLIER = 10.0d
double MOUSE_SPEED = 0.1d
double ROTATION_SPEED = 2.0d
double TRACK_SPEED = 0.3d

double mousePosX
double mousePosY
double mouseOldX
double mouseOldY
double mouseDeltaX
double mouseDeltaY

# main
println("starting...")

object runtime = getClass("Platform")
runtime.startup(thread.getRunnable())

object root = loadObj("scene.Group")
object axisGroup = loadObj("DpdlTestForm")
object moleculeGroup = loadObj("DpdlTestForm")
object world = loadObj("DpdlTestForm")

bool b = true

object camera = loadObj("PerspectiveCamera", b)

object cameraXform = loadObj("DpdlTestForm")
object cameraXform2 = loadObj("DpdlTestForm")
object cameraXform3 = loadObj("DpdlTestForm")

object depthtest = getClass("DepthTest")
object color = getClass("paint.Color")

object root_child = root.getChildren()
root_child.add(world)

root.setDepthTest(depthtest.ENABLE)

println("constructing scene...")

buildCamera()
buildAxes()
buildMolecule()

println("loading scene...")

raise(root, "root Group scene is null")

bool bs = true
object scene = loadObj("Scene", root, 1024.0d, 768.0d, bs)
scene.setFill(color.GREY)

println("starting App....")
object app = loadObj("DpdlJavaFXApp")
app.initApp()

# mouse & key event handling

object camRotY = cameraXform.ry
object camRotX = cameraXform.rx

object cam2Trans = cameraXform2.t

object mouse_event_handler = loadObj("MouseEventHandler")
scene.setOnMouseDragged(mouse_event_handler)

object key_event_handler = loadObj("KeyEventHandler")
scene.setOnKeyPressed(key_event_handler)

