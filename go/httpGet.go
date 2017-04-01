package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
)

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Pass the url to get data")
		os.Exit(-1)
	}
	var url = os.Args[1]
	result := make(chan string)
	go func() {
		result <- getDataFromURL(url)
	}()
	fmt.Println(<-result)
}

func getDataFromURL(url string) string {
	response, error := http.Get(url)
	if error != nil {
		return error.Error()
	}
	defer response.Body.Close()
	body, error := ioutil.ReadAll(response.Body)
	if error != nil {
		return error.Error()
	}
	return string(body[:])
}
