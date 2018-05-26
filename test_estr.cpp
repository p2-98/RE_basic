#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Enter_str(char *str, int x, int y, char *e_str)
{
	int tmp = 0;
	for (int i = x; i < y; i++){
		e_str[tmp] = str[i];
		tmp++;
	};
	e_str[tmp] = '\0';
}

float Enter_num(char *str, int x, int y)
{
	int p_dot = 0;
	float num = 0, div = 1;
	for (int i = x; i < y; i++){
		if (str[i] == '.'){
			p_dot = i;
			break;
		}
	}

	if (p_dot == 0) p_dot = y;

	for (int i = x; i < p_dot; i++){
		num = num*10 + (str[i] - 48);
	}
	for (int i = p_dot + 1; i < y; i++){
		num = num*10 + (str[i] - 48);
		div = div * 10;
	}
	num = num /div;

	return num;
}

int main()
{
	char str[] = "Code:2|Name:2|Price:2.69|Quantity:2|Date product:2|Place product:2";

	for (int i = 0; i < strlen(str); i++){
		if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z')) || (str[i] == ':') || (str[i] == '|')){
			str[i] = ' ';
		} 
	}

	float price;
	int quantity;
	char code[255], name[255], date_product[255], place_product[255];

	int count_data = 1, j, i = 0;

	int n = strlen(str);

	str[n] = ' ';

	while (i < n){		
		if (str[i] != ' ') {
			j = i;
			while (str[i] != ' '){
				i++;
			};
			switch (count_data){
				case 1:
					Enter_str(str, j, i, code);
					break;
				case 2:
					Enter_str(str, j, i, name);
					break;
				case 3:
					price = Enter_num(str, j, i);
					break;
				case 4:
					quantity = (int)Enter_num(str, j, i);
					break;
				case 5:
					Enter_str(str, j, i, date_product);
					break;
				case 6:
					Enter_str(str, j, i, place_product);
					break;
			}
			count_data++;
		}
		else {
			i++;
		}
	}

	printf("Code: %s\nName: %s\nPrice: %.2f\nQuantity: %d\nDate Product: %s\nPlace Procduct: %s\n", code, name, price, quantity, date_product, place_product);
}
