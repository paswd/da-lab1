#include <stdio.h>
#include "data.h"

/* ATTENTION */
/* THIS CODE WAS SENT ON DEBUGGING. CODE STYLE CAN BE CORRECTED IN FUTURE */

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
    this->Key.Day = 0;
    this->Key.Month = 0;
    this->Key.Year = 0;

    this->DayNullsCnt = 0;
    this->MonthNullsCnt = 0;
    this->YearNullsCnt = 0;
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
    bool log[4] = {false, false, false, false};

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
                        log[0] = true;
                        if (pos >= 4 || sym == '\t') {
                            //printf("Braked: case 0\n");
                            return false;
                        }
                        //printf("%s\n", tmp);
                        for (size_t i = 0; i < pos; i++) {
                            this->Key.Day = (char) StrToInt(tmp, pos);
                            this->DayNullsCnt = this->PrenullsCnt(tmp);
                        }
                        //printf("Debug 1: %d\n", this->Key.Day);
                        element++;
                        pos = 0;
                        continue;
                    case 1:
                        log[1] = true;
                        if (pos >= 4 || sym == '\t') {
                            //printf("Braked: case 1\n");
                            return false;
                        }
                        //printf("%s\n", tmp);
                        //printf("\n");
                        for (size_t i = 0; i < pos; i++) {
                            this->Key.Month = (char) StrToInt(tmp, pos);
                            this->MonthNullsCnt = this->PrenullsCnt(tmp);
                        }
                        //printf("Debug 2: %d\n", this->Key.Month);
                        element++;
                        pos = 0;
                        continue;
                    case 2:
                        log[2] = true;
                        //printf("\nEl: in\n");
                        //printf("%s\n", tmp);
                        //printf("\n");
                        for (size_t i = 0; i < pos; i++) {
                            this->Key.Year = (short int) StrToInt(tmp, pos);
                            this->YearNullsCnt = this->PrenullsCnt(tmp);
                        }
                        element++;
                        //printf("Debug 3: %d\n", this->Key.Year);

                        mode = true;
                        pos = 0;

                        continue;
                    default:
                        continue;
                }
            }
            tmp[pos] = sym;
        } else {
            log[3] = true;
            //Value parse block
            this->Value[pos] = sym;
        }
        pos++;
    }
    if (pos > 64) {
        pos = 64;
    }
    this->Value[pos] = '\0';
    this->IsEmpty = !(log[0] && log[1] && log[2] && log[3]);
    return true;
}

void TNote::Print(void) {
    if (this->IsEmpty) {
        return;
    }
    for (char i = 0; i < this->DayNullsCnt; i++) {
        printf("0");
    }
    printf("%d.", (int) this->Key.Day);

    for (char i = 0; i < this->MonthNullsCnt; i++) {
        printf("0");
    }
    printf("%d.", (int) this->Key.Month);

    for (char i = 0; i < this->YearNullsCnt; i++) {
        printf("0");
    }
    printf("%d\t", (int) this->Key.Year);

    for (int i = 0; i < 65; i++) {
        if (this->Value[i] == '\0') {
            break;
        }
        printf("%c", this->Value[i]);
    }
    printf("\n");
}
