#include <stdio.h>
#include <string.h>

// Estrutura que representa a carta de cidade
typedef struct {
    char name[100];
    unsigned long int population;
    int touristAttractions;
    float pib, pibPerCapita, area, populationDensity, superPower, comparationPoints;
} City;

// Metodo que calcula a densidade populacional
float calculatePopulationDensity(int population, float area) {
    return (float)population / area;
}

// Metodo que calcula o PIB per capita
float calculatePibPerCapita(int population, float pib) {
    return (float)pib / population;
}

// Metodo que calcula o super poder da cidade
float calculateSuperPower(City city) {
    return (float)city.population + (float)city.touristAttractions + city.pib + city.pibPerCapita + city.area + city.populationDensity;
}

City setCity() {
    City city;
    printf("Digite o nome da cidade: \n");
    fgets(city.name, sizeof(city.name), stdin);

    // Remove o caractere de nova linha
    city.name[strcspn(city.name, "\n")] = '\0';

    // Insere informacoes da populacao
    printf("Digite a população de %s:\n", city.name);
    scanf("%lu", &city.population);

    // Insere dados da area
    printf("Digite a area de %s:\n", city.name);
    scanf("%f", &city.area);

    // Insere dados da PIB
    printf("Digite o PIB de %s:\n", city.name);
    scanf("%f", &city.pib);

    // Insere dados da quantidade de pontos turisticos
    printf("Digite a quantidade de pontos turísticos de %s:\n", city.name);
    scanf("%d", &city.touristAttractions);

    // Limpa o buffer de entrada
    while (getchar() != '\n');

    // Calculo de densidade populacional
    city.populationDensity = calculatePopulationDensity(city.population, city.area);

    // Calculo PIB per capita
    city.pibPerCapita = calculatePibPerCapita(city.population, city.pib);

    // Calculo do super poder
    city.superPower = calculateSuperPower(city);

    // Inicializa os pontos de comparacao
    city.comparationPoints = 0;

    // Exibe todas as informações
    printf("Informacoes Gerais de %s: \n\n", city.name);
    printf("População: %lu\n", city.population);
    printf("Area: %f\n", city.area);
    printf("Pib: %f\n", city.pib);
    printf("Numero de pontos turísticos: %d\n", city.touristAttractions);
    printf("Densidade Populacional: %f\n", city.populationDensity);
    printf("PIB per Capita: %f\n", city.pibPerCapita);
    printf("Super Poder: %f\n", city.superPower);

    return city;
}

void verifyPopulation(City *city1, City *city2) {
    // Nome da carta com a maior populacao
    char winnerName[100];
    strcpy(winnerName, city1->population > city2->population ? city1->name : city2->name);
    printf("A carta %s tem a maior população\n", winnerName);

    city1->comparationPoints += city1->population;
    city2->comparationPoints += city2->population;
}

void verifyArea(City *city1, City *city2) {
    // Nome da carta com a maior area
    char winnerName[100];
    strcpy(winnerName, city1->area > city2->area ? city1->name : city2->name);
    printf("A carta %s tem a maior área\n", winnerName);

    city1->comparationPoints += city1->area;
    city2->comparationPoints += city2->area;
}

void verifyPib(City *city1, City *city2) {
    char winnerName[100];
    // Nome da carta com o maior PIB
    strcpy(winnerName, city1->pib > city2->pib ? city1->name : city2->name);
    printf("A carta %s tem o maior PIB\n", winnerName);

    city1->comparationPoints += city1->pib;
    city2->comparationPoints += city2->pib;
}

void verifyTouristAttractions(City *city1, City *city2) {
    // Nome da carta com mais pontos turisticos
    char winnerName[100];
    strcpy(winnerName, city1->touristAttractions > city2->touristAttractions ? city1->name : city2->name);
    printf("A carta %s tem mais pontos turísticos\n", winnerName);

    city1->comparationPoints += city1->touristAttractions;
    city2->comparationPoints += city2->touristAttractions;
}

void verifyPopulationDensity(City *city1, City *city2) {
    // Nome da carta com a menor densidade populacional
    char winnerName[100];
    strcpy(winnerName, city1->populationDensity < city2->populationDensity ? city1->name : city2->name);
    printf("A carta %s tem a menor densidade populacional\n", winnerName);

    city1->comparationPoints += city1->populationDensity;
    city2->comparationPoints += city2->populationDensity;
}

void verifyPibPerCapita(City *city1, City *city2) {
    // Nome da carta com o maior PIB per capita
    char winnerName[100];
    strcpy(winnerName, city1->pibPerCapita > city2->pibPerCapita ? city1->name : city2->name);
    printf("A carta %s tem o maior PIB per capita\n", winnerName);

    city1->comparationPoints += city1->pibPerCapita;
    city2->comparationPoints += city2->pibPerCapita;
}

void verifySuperPower(City *city1, City *city2) {
    // Nome da carta com o maior super poder
    char winnerName[100];
    strcpy(winnerName, city1->superPower > city2->superPower ? city1->name : city2->name);
    printf("A carta %s tem o maior super poder\n", winnerName);

    city1->comparationPoints += city1->superPower;
    city2->comparationPoints += city2->superPower;
}

void verifyWinner(City city1, City city2) {
    printf("\nResultado final:\n");

    printf("\nPontos da carta %s: %f\n", city1.name, city1.comparationPoints);
    printf("Pontos da carta %s: %f\n", city2.name, city2.comparationPoints);

    if (city1.comparationPoints == city2.comparationPoints) {
        printf("\nOcorreu um Empate\n");
    } else if (city1.comparationPoints > city2.comparationPoints) {
        printf("\nA carta %s venceu a partida com o total de %f pontos \n", city1.name, city1.comparationPoints);
    } else {
        printf("\nA carta %s venceu a partida com o total de %f pontos \n", city2.name, city2.comparationPoints);
    }
}

void doComparation(City *city1, City *city2, int comparationOption) {
    switch (comparationOption) {
    case 1:
        verifyPopulation(city1, city2);
        break;
    case 2:
        verifyArea(city1, city2);
        break;
    case 3:
        verifyPib(city1, city2);
        break;
    case 4:
        verifyTouristAttractions(city1, city2);
        break;
    case 5:
        verifyPopulationDensity(city1, city2);
        break;
    case 6:
        verifyPibPerCapita(city1, city2);
        break;
    case 7:
        verifySuperPower(city1, city2);
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
}

void getMenu(const char *title) {
    printf("%s\n", title);
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
}

int main() {
    City city1, city2;
    int comparationOption, comparationOption2;

    printf("Cartas SuperTrufo de cidades:\n\n");

    printf("Cadastro da primeira carta:\n");
    city1 = setCity();

    printf("\nCadastro da segunda carta:\n");
    city2 = setCity();

    while (comparationOption < 1 || comparationOption > 7) {
        getMenu("\nEscolha uma opção para comparar as cartas:");
        scanf("%d", &comparationOption);
    }

    do {
        getMenu("\nEscolha uma segunda opção para comparar as cartas (diferente da primeira):");
        scanf("%d", &comparationOption2);

        if (comparationOption2 == comparationOption) {
            printf("\nOpção inválida. Escolha uma opção diferente da primeira.\n");
        }
    } while (comparationOption2 == comparationOption || comparationOption2 < 1 || comparationOption2 > 7);

    printf("\nResultado da partida:\n");

    doComparation(&city1, &city2, comparationOption);
    doComparation(&city1, &city2, comparationOption2);
    verifyWinner(city1, city2);

    return 0;
}
