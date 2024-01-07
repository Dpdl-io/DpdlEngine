# Dpdl resolve

![Dpdl](https://www.dpdl.io/images/dpdl-io.png)

				www.dpdl.io

developed by
**SEE Solutions**
&copy; 2003	



Below the list of java classes where a path prefix needs to be specified when using the functions **`loadObj(..)`** and **`getClass(..)`**.

For example to load 'java.sql.Array', the corresponding resolve entry is 'sql.Array', because 'Array' will resolve to 'java.lang.reflect.Array' per default as specified in the **`class definition`** file.

These are the Exceptions:
```
java.sql.Array sql.Array
java.text.Annotation text.Annotation
javax.management.Attribute management.Attribute
javax.naming.directory.Attribute directory.Attribute
javax.print.attribute.Attribute attribute.Attribute
java.text.AttributedCharacterIterator.Attribute AttributedCharacterIterator.Attribute
javax.swing.text.html.CSS.Attribute CSS.Attribute
javax.swing.text.html.parser.AttributeList parser.AttributeList
javax.print.attribute.AttributeSet attribute.AttributeSet
javax.naming.directory.Attributes directory.Attributes
javax.security.sasl.AuthenticationException sasl.AuthenticationException
javax.swing.plaf.metal.MetalBorders.ButtonBorder MetalBorders.ButtonBorder
javax.swing.plaf.synth.ColorType synth.ColorType
java.sql.Date sql.Date
java.awt.geom.Arc2D.Double Arc2D.Double
java.awt.geom.CubicCurve2D.Double CubicCurve2D.Double
java.awt.geom.Ellipse2D.Double Ellipse2D.Double
java.awt.geom.Line2D.Double Line2D.Double
java.awt.geom.Point2D.Double Point2D.Double
java.awt.geom.QuadCurve2D.Double QuadCurve2D.Double
java.awt.geom.Rectangle2D.Double Rectangle2D.Double
java.awt.geom.RoundRectangle2D.Double RoundRectangle2D.Double
java.awt.geom.Arc2D.Float Arc2D.Float
java.awt.geom.CubicCurve2D.Float CubicCurve2D.Float
java.awt.geom.Ellipse2D.Float Ellipse2D.Float
java.awt.geom.Line2D.Float Line2D.Float
java.awt.geom.Point2D.Float Point2D.Float
java.awt.geom.QuadCurve2D.Float QuadCurve2D.Float
java.awt.geom.Rectangle2D.Float Rectangle2D.Float
java.awt.geom.RoundRectangle2D.Float RoundRectangle2D.Float
javax.sound.sampled.AudioFileFormat.Type AudioFileFormat.Type
javax.sound.sampled.BooleanControl.Type BooleanControl.Type
javax.sound.sampled.CompoundControl.Type CompoundControl.Type
javax.sound.sampled.Control.Type Control.Type
javax.sound.sampled.EnumControl.Type EnumControl.Type
javax.sound.sampled.FloatControl.Type FloatControl.Type
java.security.KeyRep.Type KeyRep.Type
javax.sound.sampled.LineEvent.Type LineEvent.Type
java.net.Proxy.Type Proxy.Type
javax.print.DocFlavor.URL DocFlavor.URL
javax.swing.text.html.HTMLDocument.Iterator HTMLDocument.Iterator
javax.swing.text.html.parser.Element parser.Element
java.awt.List awt.List
java.security.KeyStore.Entry KeyStore.Entry
java.sql.Timestamp sql.Timestamp
java.sql.Connection sql.Connection
javax.swing.event.DocumentEvent.EventType DocumentEvent.EventType
javax.xml.datatype.DatatypeConstants.Field DatatypeConstants.Field
java.text.DateFormat.Field DateFormat.Field
java.text.Format.Field Format.Field
java.text.MessageFormat.Field MessageFormat.Field
java.text.NumberFormat.Field NumberFormat.Field
javax.swing.filechooser.FileFilter filechooser.FileFilter
javax.imageio.spi.ServiceRegistry.Filter ServiceRegistry.Filter
javax.swing.text.NavigationFilter.FilterBypass NavigationFilter.FilterBypass
java.util.logging.Formatter logging.Formatter
javax.sound.sampled.DataLine.Info DataLine.Info
javax.sound.sampled.Line.Info Line.Info
javax.sound.midi.MidiDevice.Info MidiDevice.Info
javax.sound.sampled.Mixer.Info Mixer.Info
javax.sound.sampled.Port.Info Port.Info
javax.swing.JPopupMenu.Separator JPopupMenu.Separator
javax.naming.spi.DirStateFactory.Result DirStateFactory.Result
javax.management.timer.Timer timer.Timer
javax.swing.Timer swing.Timer
javax.bluetooth.UUID bluetooth.UUID
java.beans.Statement beans.Statement
java.security.Key security.Key
javax.swing.text.html.HTMLEditorKit.Parser HTMLEditorKit.Parser
javax.swing.plaf.metal.MetalBorders.MenuBarBorder MetalBorders.MenuBarBorder
javax.obex.PasswordAuthentication obex.PasswordAuthentication
javax.naming.Name naming.Name
java.security.acl.Permission acl.Permission
java.lang.reflect.Proxy reflect.Proxy
javax.security.auth.Policy auth.Policy
javax.obex.Operation obex.Operation
javax.naming.Reference naming.Reference
javax.swing.plaf.metal.MetalBorders.RolloverButtonBorder MetalBorders.RolloverButtonBorder
javax.swing.plaf.metal.MetalBorders.ToggleButtonBorder MetalBorders.ToggleButtonBorder
javax.swing.text.html.ParagraphView html.ParagraphView
javax.security.cert.X509Certificate cert.X509Certificate
javax.management.openmbean.OpenType openmbean.OpenType
javax.swing.plaf.basic.BasicComboBoxEditor.UIResource BasicComboBoxEditor.UIResource
javax.swing.plaf.basic.BasicComboBoxRenderer.UIResource BasicComboBoxRenderer.UIResource
javax.swing.DefaultListCellRenderer.UIResource DefaultListCellRenderer.UIResource
javax.swing.table.DefaultTableCellRenderer.UIResource DefaultTableCellRenderer.UIResource
javax.swing.plaf.metal.MetalComboBoxEditor.UIResource MetalComboBoxEditor.UIResource
javax.swing.ScrollPaneLayout.UIResource ScrollPaneLayout.UIResource

```

