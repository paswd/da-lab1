#include <stdio.h>
#include "data.h"

int CharToInt(int sym) {
	if (sym >= '0' && sym <= '9') {
		return sym - '0';
	}
	return 0;
}

int StrToInt(char *str, size_t size) {
	int res = 0;
	for (size_t i = 0; i < size; i++) {
		res *= 10;
		res += CharToInt(str[i]);
	}
	return res;
}

TNote::TNote() {
	this->key.day = 0;
	this->key.month = 0;
	this->key.year = 0;

	this->day_nulls_cnt = 0;
	this->month_nulls_cnt = 0;
	this->year_nulls_cnt = 0;
}

char TNote::PrenullsCnt(char *str) {
	char cnt = 0;
	for (size_t i = 0; i < 4; i++) {
		if (str[i] != '0') {
			break;
		}
		cnt++;
	}
	return cnt;
}

bool TNote::Input(void) {
	int sym = 0;
	char tmp[4];
	size_t pos = 0;
	char element = 0;
	bool mode = false;

	while ((sym = getchar()) != '\n') {
		if (sym == EOF) {
			return false;
		}
		if (!mode) {
			//Key parse block
			/*if (sym == '\t') {
				mode = true;
				pos = 0;
				continue;
			}*/
			//printf("Pos: %d\n", (int) pos);
			//printf("Sym: %c\n", sym);
			//printf("El: %d\n", (int) element);
			if (sym == '.' || pos >= 4 || sym == '\t') {
				switch (element) {
					case 0:
						if (pos >= 4 || sym == '\t') {
							//printf("Braked: case 0\n");
							return false;
						}
						//printf("%s\n", tmp);
						for (size_t i = 0; i < pos; i++) {
							this->key.day = (char) StrToInt(tmp, pos);
							this->day_nulls_cnt = this->PrenullsCnt(tmp);
						}
						printf("Debug 1: %d\n", this->key.day);
						element++;
						pos = 0;
						continue;
					case 1:
						if (pos >= 4 || sym == '\t') {
							//printf("Braked: case 1\n");
							return false;
						}
						//printf("%s\n", tmp);
						//printf("\n");
						for (size_t i = 0; i < pos; i++) {
							this->key.month = (char) StrToInt(tmp, pos);
							this->month_nulls_cnt = this->PrenullsCnt(tmp);
						}
						printf("Debug 2: %d\n", this->key.month);
						element++;
						pos = 0;
						continue;
					case 2:
						printf("\nEl: in\n");
						printf("%s\n", tmp);
						//printf("\n");
						for (size_t i = 0; i < pos; i++) {
							this->key.year = (short int) StrToInt(tmp, pos);
							this->year_nulls_cnt = this->PrenullsCnt(tmp);
						}
						element++;
						printf("Debug 3: %d\n", this->key.year);

						mode = true;
						pos = 0;

						continue;
					default:
						continue;
				}
			}
			tmp[pos] = sym;
		} else {
			//Value parse block
			this->value[pos] = sym;
		}
		pos++;
	}
	if (pos > 63) {
		pos = 63;
	}
	this->value[pos] = '\0';
	return true;
}

void TNote::Print(void) {
	for (char i = 0; i < this->day_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d.", (int) this->key.day);

	for (char i = 0; i < this->month_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d.", (int) this->key.month);

	for (char i = 0; i < this->year_nulls_cnt; i++) {
		printf("0");
	}
	printf("%d\t", (int) this->key.year);

	for (int i = 0; i < 64; i++) {
		printf("%c", this->value[i]);
		if (this->value[i] == '\0') {
			break;
		}
	}
}
