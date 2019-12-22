#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct Flight{
    char destination[20];
    unsigned char number[5];
    unsigned char airplane_type[20];
};

int flights_counter = 0;

int write_flights_data_to_file(const char *filename){
    struct Flight flight1 = {"Keln", "2334", "Airbus 770"};
    struct Flight flight2 = {"Moscow", "1231", "Airbus 769"};
    FILE *outfile;
    outfile = fopen(filename, "wb");
    if (!outfile)
        return 1;
    if (fwrite(&flight1, sizeof(struct Flight), 1, outfile) != 0)
        if (fwrite(&flight2, sizeof(struct Flight), 1, outfile) != 0)
            return 1;

    return 0;
}

struct Flight* read_flights_data_from_file(const char *filename){
    FILE *infile;
    struct Flight* flights;
    unsigned int cur_size = 10;
    unsigned int i = 0;
    struct Flight tmp;

    flights = malloc(sizeof(struct Flight)*cur_size);

    infile = fopen(filename, "rb");
    if (!infile){
        printf("can't read input file");
        exit(EXIT_FAILURE);
    }
    while (fread(&tmp, sizeof(struct Flight), 1, infile)){
        flights[i++] = tmp;
    }
    flights_counter = i;
    return flights;
}

void search_for_flights(struct Flight* all_flights, char *dest_point){
    char flag = 1;
    for (int i = 0; i < flights_counter; i++){
        if (strcmp(all_flights[i].destination, dest_point) == 0){
            if (flag) printf("Founded flights:\n");
            printf("%s\t%s\t%s", all_flights[i].destination, all_flights[i].number, all_flights[i].airplane_type);
            flag=0;
        }
    }
    if (flag) printf("No flight was found.");
}

int main() {
    struct Flight* flights;
    char target_flight[20];
//    write_flights_data_to_file("Spravka.dat"); //You can use this function to write to file

    flights = read_flights_data_from_file("Spravka.dat");
    printf("Enter flight destination point:");
    scanf("%s",target_flight);
    search_for_flights(flights, target_flight);

    return 0;
}