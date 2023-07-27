package main

import "try"

func f() (n int, err error) {
  n = 7
  try(errors.New("x"))
  // ...
}
