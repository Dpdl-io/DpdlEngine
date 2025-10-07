# File: ui/dpdlGUIExample.h
#
# Example: GUI components and action listener interface
#
# Author: A.Costa
# e-mail: info@dpdl.io
#
#

# call back function for ActionListenerInterface
func actionPerformed(string event)
	if(event == "OK_cmd")
		isCheckbox1Enabled = check_box1.isSelected()
		isCheckbox2Enabled = check_box2.isSelected()
		println("check_box1: " + isCheckbox1Enabled)
		println("check_box2: " + isCheckbox2Enabled)
	elsif(event == "RESET_cmd")
		println("reset")
	else
		println("command not found")
	fi
end

func myUpdateProc()
	if(x < list_model.getSize())
		list_model.set(x, "" + cnt)
		x = x + 1
	else
		x = 0
		date = loadObj("Date")
		date_str = date.toString()
		date_time.setText(date_str)

		graphics = draw_canvas.getGraphics()
		graphics.setColor(color)
		x_ = randInt(16, 80)
		y_ = randInt(16, 80)
		graphics.clearRect(0, 0, draw_canvas.getWidth(), draw_canvas.getHeight())
		graphics.drawString("Hello Dpdl", x_, y_);
		graphics.drawRect(x_-15, y_-15, 100, 20)
		sleep(1000)
	fi
	cnt = cnt + 1
end

# main
int width = 250
int height = 500
bool isCheckbox1Enabled = false
bool isCheckbox2Enabled = false

object frame_class = getObj("JFrame")
object frame = loadObj("JFrame")
frame.setDefaultCloseOperation(frame_class.EXIT_ON_CLOSE)

object panel = loadObj("JPanel")
object layout = loadObj("GridLayout", 0, 1)
object panel_form = loadObj("JPanel")
object list_model = loadObj("DefaultListModel")
object list = loadObj("JList", list_model)
object check_box1 = loadObj("JCheckBox", "Option 1")
object check_box2 = loadObj("JCheckBox", "Option 2")
object button = loadObj("JButton")
object date_time = loadObj("JLabel", "Date:")
object draw_canvas = loadObj("JPanel")

object event_listener = loadObj("ActionListenerInterface")

list.setSize(width-20, height/2)
list_model.addElement("one")
list_model.addElement("two")
list_model.addElement("three")
list_model.addElement("four")
list_model.addElement("five")
list_model.addElement("six")

button.setLabel("OK")
button.setActionCommand("OK_cmd");
button.addActionListener(event_listener)

panel_form.add(check_box1)
panel_form.add(check_box2)

panel.setLayout(layout)
panel.add(list)
panel.add(panel_form)
panel.add(button)
panel.add(date_time)
panel.add(draw_canvas)

frame.add(panel)
frame.setSize(width, height)
frame.setVisible(true)

int x = 0
int cnt = 0
object date
string date_str
object graphics
object color = loadObj("Color", 0, 0, 255)

int x_, y_

int tid = Thread("myUpdateProc", 1000)

raise(tid, "Error in starting myUpdateProc thread")

println("myUpdateProc thread started with id: " + tid)

