#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_PRODUCTIONS 10

// Üretim kurallarini tutacak olan yapi
typedef struct {
    char nonterminal;
    char production[MAX_LEN];
} ProductionRule;

// Üretim kurallarini parçalayarak dil agacini olusturan fonksiyon
void generateTree(char *current, int index, char *word, ProductionRule *rules, int ruleCount) {
    int i;
	if (index == strlen(word)) {
        printf("%s\n", current);
        return;
    }

    if (word[index] >= 'A' && word[index] <= 'Z') {
        char nonterminal = word[index];
        for ( i = 0; i < ruleCount; i++) {
            if (rules[i].nonterminal == nonterminal) {
                char newCurrent[MAX_LEN];
                strcpy(newCurrent, current);
                strcat(newCurrent, rules[i].production);
                generateTree(newCurrent, index, word, rules, ruleCount);
            }
        }
    } else {
        generateTree(current, index + 1, word, rules, ruleCount);
    }
}

int main() {
    char words[][MAX_LEN] = {
        "AB",
        "AAB",
        "ABAB",
        "ABBB",
        "AAABBB"
    };

    ProductionRule rules[MAX_PRODUCTIONS];
    int ruleCount = 0;

    printf("CFG Üretim Kurallarini Girin (Nonterminal->Production):\n");
    char input[MAX_LEN];
    while (fgets(input, sizeof(input), stdin) != NULL) {
        if (ruleCount >= MAX_PRODUCTIONS) {
            printf("Maksimum üretim kurali sayisina ulasildi.\n");
            break;
        }
        if (strlen(input) <= 1)
            continue;
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        sscanf(input, "%c->%s", &rules[ruleCount].nonterminal, rules[ruleCount].production);
        ruleCount++;
    }
    int i;
    printf("Dili Olusturan Kelimeler:\n");
    for ( i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        char current[MAX_LEN] = "";
        generateTree(current, 0, words[i], rules, ruleCount);
    }

    printf("\nTekrarlanan Kelimeler:\n");
    for (i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        if (isRepeated(words[i], i)) {
            printf("%s\n", words[i]);
        }
    }

    return 0;
}
