#include <string.h>

const char * expected_UUIDs[] = {
	"S001",
	"S002",
	"S003",
	"S005"
};

char * found_UUIDs[] = {
    "S004",
    "S001",
    "S027",
    "S003",
    "S002",
    "S005"
};

/*
La función compare_UUIDs recibe los siguientes parámetros:
 - expected: lista de strings que se esperan recibir
 - expected_amount: cantidad de elementos que se esperan recibir
 - available: lista de strings que se poseen
 - available_amount: cantidad de elementos que se poseen

Retorno:
 - Si todos los strings que se esperan recibir existen en "available", retorna 0
 - Si algún string de "expected" no existe en "available", retorna -1
*/

int8_t compare_UUIDs(const char ** expected, uint8_t expected_amount, const char ** available, uint8_t available_amount) {
	for(uint8_t e = 0; e < expected_amount; e++) {
		uint8_t found = 0;
		
		for(uint8_t a = 0; a < available_amount; a++) {
			if(!strcmp(expected[e],available[a])) {
				found = 1;
				printf("Match!\n");
				break;
			}
		}

		if(!found) {
			return -1;
		}
	}
	return 0;
}

void setup() {
    Serial.begin(9600);

    // Para probar la función, modificar los valores dentro de la lista "found_UUIDs"
    // Si se agregan o quitan elementos, se debe también modificar el último parámetro de la función
    //  de acá abajo, para que coincida con la cantidad de elementos de dicha lista.
    uint8_t matched_all = compare_UUIDs(expected_UUIDs, 4, found_UUIDs, 6);

    if(matched_all == 0) {
      Serial.println("UUIDs encontrados");
    } else {
      Serial.println("UUIDs no encontrados");
    }
}

void loop() {

}