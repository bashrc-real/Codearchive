package main

import (
	"fmt"
)

// NaN's behavior in go is similar to other languages.
// NaN isn't equal to itself.
func main() {
	value1 := 0.0 // if value1 and value2 are integer instead, the goroutine will terminate with integer division by 0 error which is similar to other languages
	value2 := 0.0
	nan := value1 / value2

	if nan == nan {
		fmt.Println("Nan's behavior is different from other languages. NaN == NaN")
	} else {
		fmt.Println("NaN != NaN in go")
	}
}
