package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"sync"
	"time"
	"crypto/tls"
)

var (
    httpClient *http.Client
)

const (
    MaxIdleConnections int = 500
    RequestTimeout     int = 100000
)

// init HTTPClient
func init() {
    httpClient = createHTTPClient()
}

// createHTTPClient for connection re-use
func createHTTPClient() *http.Client {
    client := &http.Client{
        Transport: &http.Transport{
            MaxIdleConnsPerHost: MaxIdleConnections,
			IdleConnTimeout : time.Duration(120) * time.Second,
			TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
        },
        Timeout: time.Duration(RequestTimeout) * time.Second,
    }

    return client
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Pass the url to get data")
		os.Exit(-1)
	}
	var wg sync.WaitGroup
	var url = os.Args[1]
	
	for i :=0; i < 5000; i+=1 {
		wg.Add(1)
	go func() {
		defer wg.Done()
		 getDataFromURL(url)
	}()

}
	wg.Wait()
}

func getDataFromURL(url string) string {
	req, err := http.NewRequest("GET", url, nil)
	if err != nil{
		fmt.Println("Error:" + err.Error())
		return ""
	}
	req.Header.Set("Connection", "Keep-Alive")
	req.Header.Set("Keep-Alive", "timeout:1200")
	response, error := httpClient.Do(req)
	
	if error != nil {
		fmt.Println(error.Error())
		return error.Error()
	}
	defer response.Body.Close()
	body, error := ioutil.ReadAll(response.Body)
	if error != nil {
		fmt.Println(error.Error())
		return error.Error()
	}else{
		fmt.Println(response.StatusCode)
		
	}
	return string(body[:])
}
