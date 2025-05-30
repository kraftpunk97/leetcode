package main

import "fmt"

func main() {
	normalBuilder := getBuilder("normal")
	iglooBuilder := getBuilder("igloo")

	director := newDirector(normalBuilder)
	normalHouse := director.buildHouse()

	fmt.Println("Normal House Door Type:", normalHouse.doorType)
	fmt.Println("Normal House Window Type:", normalHouse.windowType)
	fmt.Println("Normal House Floor :", normalHouse.floor)

	director = newDirector(iglooBuilder)
	iglooHouse := director.buildHouse()

	fmt.Println("Igloo House Door Type:", iglooHouse.doorType)
	fmt.Println("Igloo House Window Type:", iglooHouse.windowType)
	fmt.Println("Igloo House Floor:", iglooHouse.floor)

}
