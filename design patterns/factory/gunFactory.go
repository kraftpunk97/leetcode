package main

import "fmt"

func getGun(gunType string) (IGun, error) {
	switch gunType {
	case "AK47":
		return newAK47(), nil
	case "Musket":
		return newMusket(), nil
	default:
		return nil, fmt.Errorf("wrong gun type passed")
	}
}
