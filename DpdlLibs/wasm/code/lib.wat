(module
  (func (export "add") (param i32 i32) (result i32)
    ;; Function to add 2 numbers and exported as "add".
    (i32.add (local.get 0) (local.get 1))
  )
  (func (export "mul") (param i32 i32) (result i32)
    ;; Function to mul 2 number and exported as "mul".
    (i32.mul (local.get 0) (local.get 1))
  )

