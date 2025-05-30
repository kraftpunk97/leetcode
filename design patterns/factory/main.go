package main

import "fmt"






func printDetails(gun IGun) {
	fmt.Println("Gun:", gun.getName())
	fmt.Println("Power:", gun.getPower())
}

func main() {
	ak47, err := getGun("AK47")
	if err != nil {
		fmt.Println("Error:", err)
	}

	musket, err := getGun("Musket")
	if err != nil {
		fmt.Println("Error:", err)
	}

	printDetails(ak47)
	fmt.Println()
	printDetails(musket)
}
