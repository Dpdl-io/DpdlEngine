# Dpdl resolve

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	



Below the list of java classes where a path prefix needs to be specified when using the functions **`loadObj(..)`** and **`getObj(..)`**.

For example to load 'java.sql.Array', the corresponding resolve entry is 'sql.Array', because 'Array' will resolve to 'java.lang.reflect.Array' per default as specified in the **`class definition`** file.

### Class naming exception:

```
java.awt.List awt.List
java.awt.geom.Arc2D.Double Arc2D.Double
java.awt.geom.Arc2D.Float Arc2D.Float
java.awt.geom.CubicCurve2D.Double CubicCurve2D.Double
java.awt.geom.CubicCurve2D.Float CubicCurve2D.Float
java.awt.geom.Ellipse2D.Double Ellipse2D.Double
java.awt.geom.Ellipse2D.Float Ellipse2D.Float
java.awt.geom.Line2D.Double Line2D.Double
java.awt.geom.Line2D.Float Line2D.Float
java.awt.geom.Point2D.Double Point2D.Double
java.awt.geom.Point2D.Float Point2D.Float
java.awt.geom.QuadCurve2D.Double QuadCurve2D.Double
java.awt.geom.QuadCurve2D.Float QuadCurve2D.Float
java.awt.geom.Rectangle2D.Double Rectangle2D.Double
java.awt.geom.Rectangle2D.Float Rectangle2D.Float
java.awt.geom.RoundRectangle2D.Double RoundRectangle2D.Double
java.awt.geom.RoundRectangle2D.Float RoundRectangle2D.Float
java.beans.Statement beans.Statement
java.lang.reflect.Proxy reflect.Proxy
java.net.Proxy.Type Proxy.Type
java.rmi.ConnectException rmi.ConnectException
java.rmi.UnknownHostException rmi.UnknownHostException
java.security.Key security.Key
java.security.KeyRep.Type KeyRep.Type
java.security.KeyStore.Builder KeyStore.Builder
java.security.KeyStore.Entry KeyStore.Entry
java.security.acl.Permission acl.Permission
java.sql.Array sql.Array
java.sql.Connection sql.Connection
java.sql.Date sql.Date
java.sql.Timestamp sql.Timestamp
java.text.Annotation text.Annotation
java.text.AttributedCharacterIterator.Attribute AttributedCharacterIterator.Attribute
java.text.DateFormat.Field DateFormat.Field
java.text.Format.Field Format.Field
java.text.MessageFormat.Field MessageFormat.Field
java.text.NumberFormat.Field NumberFormat.Field
java.util.logging.Formatter logging.Formatter
javafx.beans.Observable beans.Observable
javafx.beans.binding.Binding beans.Binding
javafx.beans.value.ChangeListener value.ChangeListener
javafx.concurrent.Service concurrent.Service
javafx.css.Selector css.Selector
javafx.css.Style css.Style
javafx.css.converter.StringConverter converter.StringConverter
javafx.event.ActionEvent event.ActionEvent
javafx.event.Event event.Event
javafx.event.EventHandler event.EventHandler
javafx.event.EventType event.EventType
javafx.geometry.Dimension2D geometry.Dimension2D
javafx.geometry.Insets geometry.Insets
javafx.geometry.Point2D geometry.Point2D
javafx.geometry.Rectangle2D geometry.Rectangle2D
javafx.print.Paper print.Paper
javafx.print.PrintQuality print.PrintQuality
javafx.print.PrinterJob print.PrinterJob
javafx.scene.AccessibleAction scene.AccessibleAction
javafx.scene.AccessibleRole scene.AccessibleRole
javafx.scene.Cursor scene.Cursor
javafx.scene.control.Button control.Button
javafx.scene.control.Dialog control.Dialog
javafx.scene.control.Label control.Label
javafx.scene.control.ListView control.ListView
javafx.scene.control.Menu control.Menu
javafx.scene.control.MenuBar control.MenuBar
javafx.scene.control.MenuItem control.MenuItem
javafx.scene.control.ScrollPane control.ScrollPane
javafx.scene.control.Separator control.Separator
javafx.scene.control.SingleSelectionModel control.SingleSelectionModel
javafx.scene.control.TableColumn control.TableColumn
javafx.scene.control.TableView control.TableView
javafx.scene.control.TextArea control.TextArea
javafx.scene.control.TextField control.TextField
javafx.scene.image.Image image.Image
javafx.scene.image.ImageView image.ImageView
javafx.scene.input.Clipboard input.Clipboard
javafx.scene.input.InputEvent input.InputEvent
javafx.scene.input.InputMethodEvent input.InputMethodEvent
javafx.scene.input.InputMethodHighlight input.InputMethodHighlight
javafx.scene.input.InputMethodRequests input.InputMethodRequests
javafx.scene.input.KeyEvent input.KeyEvent
javafx.scene.input.MouseEvent input.MouseEvent
javafx.scene.layout.Border layout.Border
javafx.scene.layout.Region layout.Region
javafx.scene.media.AudioClip media.AudioClip
javafx.scene.media.Media media.Media
javafx.scene.media.Track media.Track
javafx.scene.robot.Robot robot.Robot
javafx.scene.shape.Line shape.Line
javafx.scene.shape.Polygon shape.Polygon
javafx.scene.shape.Rectangle shape.Rectangle
javafx.scene.shape.Shape shape.Shape
javafx.scene.text.Font text.Font
javafx.stage.Popup stage.Popup
javafx.stage.Window stage.Window
javafx.stage.WindowEvent stage.WindowEvent
javafx.util.Duration util.Duration
javax.bluetooth.UUID bluetooth.UUID
javax.imageio.spi.ServiceRegistry.Filter ServiceRegistry.Filter
javax.management.Attribute management.Attribute
javax.management.IntrospectionException management.IntrospectionException
javax.management.loading.DefaultLoaderRepository loading.DefaultLoaderRepository
javax.management.openmbean.InvalidKeyException openmbean.InvalidKeyException
javax.management.openmbean.OpenType openmbean.OpenType
javax.management.timer.Timer timer.Timer
javax.naming.Name naming.Name
javax.naming.Reference naming.Reference
javax.naming.directory.Attribute directory.Attribute
javax.naming.directory.Attributes directory.Attributes
javax.naming.directory.InvalidAttributeValueException directory.InvalidAttributeValueException
javax.naming.spi.DirStateFactory.Result DirStateFactory.Result
javax.obex.Operation obex.Operation
javax.obex.PasswordAuthentication obex.PasswordAuthentication
javax.print.DocFlavor.URL DocFlavor.URL
javax.print.attribute.Attribute attribute.Attribute
javax.print.attribute.AttributeSet attribute.AttributeSet
javax.security.auth.Policy auth.Policy
javax.security.cert.X509Certificate cert.X509Certificate
javax.security.sasl.AuthenticationException sasl.AuthenticationException
javax.sound.midi.MidiDevice.Info MidiDevice.Info
javax.sound.sampled.AudioFileFormat.Type AudioFileFormat.Type
javax.sound.sampled.BooleanControl.Type BooleanControl.Type
javax.sound.sampled.CompoundControl.Type CompoundControl.Type
javax.sound.sampled.Control.Type Control.Type
javax.sound.sampled.DataLine.Info DataLine.Info
javax.sound.sampled.EnumControl.Type EnumControl.Type
javax.sound.sampled.FloatControl.Type FloatControl.Type
javax.sound.sampled.Line.Info Line.Info
javax.sound.sampled.LineEvent.Type LineEvent.Type
javax.sound.sampled.Mixer.Info Mixer.Info
javax.sound.sampled.Port.Info Port.Info
javax.swing.DefaultListCellRenderer.UIResource DefaultListCellRenderer.UIResource
javax.swing.JPopupMenu.Separator JPopupMenu.Separator
javax.swing.ScrollPaneLayout.UIResource ScrollPaneLayout.UIResource
javax.swing.Timer swing.Timer
javax.swing.event.DocumentEvent.EventType DocumentEvent.EventType
javax.swing.filechooser.FileFilter filechooser.FileFilter
javax.swing.plaf.basic.BasicComboBoxEditor.UIResource BasicComboBoxEditor.UIResource
javax.swing.plaf.basic.BasicComboBoxRenderer.UIResource BasicComboBoxRenderer.UIResource
javax.swing.plaf.metal.MetalBorders.ButtonBorder MetalBorders.ButtonBorder
javax.swing.plaf.metal.MetalBorders.MenuBarBorder MetalBorders.MenuBarBorder
javax.swing.plaf.metal.MetalBorders.RolloverButtonBorder MetalBorders.RolloverButtonBorder
javax.swing.plaf.metal.MetalBorders.ToggleButtonBorder MetalBorders.ToggleButtonBorder
javax.swing.plaf.metal.MetalComboBoxEditor.UIResource MetalComboBoxEditor.UIResource
javax.swing.plaf.synth.ColorType synth.ColorType
javax.swing.table.DefaultTableCellRenderer.UIResource DefaultTableCellRenderer.UIResource
javax.swing.text.NavigationFilter.FilterBypass NavigationFilter.FilterBypass
javax.swing.text.html.CSS.Attribute CSS.Attribute
javax.swing.text.html.HTMLDocument.Iterator HTMLDocument.Iterator
javax.swing.text.html.HTMLEditorKit.Parser HTMLEditorKit.Parser
javax.swing.text.html.ParagraphView html.ParagraphView
javax.swing.text.html.parser.AttributeList parser.AttributeList
javax.swing.text.html.parser.Element parser.Element
javax.xml.datatype.DatatypeConstants.Field DatatypeConstants.Field

com.sun.jna.Platform jna.Platform
```

