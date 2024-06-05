# File: clj/dpdlCljCelsiusConverterGUI.h
#
# Example: This Dpdl script creates a simple UI to convert Celsius to Fahrenheit using embedded 'clojure' code
#			Some dummy parameters are passed and intecepted in the embedded clojure code, but currently unused
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

# main
println("testing embedded Clojure...")

dpdl_stack_var_put("my_parameters", "param1, param1")
dpdl_stack_var_put("my_config", "config_1, ... confi_n")

>>clj
(import '(javax.swing JFrame JLabel JTextField JButton)
        '(java.awt.event ActionListener)
        '(java.awt GridLayout))

(defn celsius []
  (let [frame (JFrame. "Celsius Converter")
        temp-text (JTextField.)
        celsius-label (JLabel. "Celsius")
        convert-button (JButton. "Convert")
        fahrenheit-label (JLabel. "Fahrenheit")]
    (.addActionListener
     convert-button
     (reify ActionListener
            (actionPerformed
             [_ evt]
             (let [c (Double/parseDouble (.getText temp-text))]
               (.setText fahrenheit-label
                         (str (+ 32 (* 1.8 c)) " Fahrenheit"))))))
    (doto frame
      (.setLayout (GridLayout. 2 2 3 3))
      (.add temp-text)
      (.add celsius-label)
      (.add convert-button)
      (.add fahrenheit-label)
      (.setSize 300 80)
      (.setVisible true))))


(ns dpdl)
	(defn dpdl_main[^objects param]
			(println (str "param: " (first param) " " ))

			(celsius)

			(int 1)
	)
<<

int exit_code = dpdl_exit_code()
println("embedded Clojure exit code: " + exit_code)
