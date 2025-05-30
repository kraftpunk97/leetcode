package main

type musket struct {
	Gun
}

func newMusket() IGun {
	return &musket{
		Gun: Gun{
			name:  "Musket Gun",
			power: 1,
		},
	}
}
