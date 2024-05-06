#include <stdio.h>
#include <stdlib.h>

void main()
{
  char buff[255];
    FILE *dormFile = fopen("./storage/dorm-repository.txt", "r");;

  // membuka file
  if (dormFile == NULL){
      printf("Error: File tidak ada!");
      // Tutup program karena file gak ada.
      exit(1);
  }

  // baca isi file dengan gets lalu simpan ke buff
  fgets(buff, 255, dormFile);
  // tampilkan isi file
  printf("%s", buff);

    fgets(buff, sizeof(buff), dormFile);
    printf("%s", buff);
    fgets(buff, sizeof(buff), dormFile);
    printf("%s", buff);
    fgets(buff, sizeof(buff), dormFile);
    printf("%s", buff);

  // tutup file
  fclose(dormFile);
}