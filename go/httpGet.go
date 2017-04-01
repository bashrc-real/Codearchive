package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	result := getDataFromURL("https://www.google.com")
	fmt.Println(result)
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
