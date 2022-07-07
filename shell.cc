#include "shell.hh"
#include <string>

int main()
{ std::string input;

  // ToDo: Vervang onderstaande regel: Laad prompt uit bestand
  std::string prompt = "ToDo: Laad de prompt uit een bestand! ";

  while(true)
  { std::cout << prompt;                   // Print het prompt
    std::getline(std::cin, input); 
    std::cout << input << std::endl;        // Lees een regel
    if (input == "new_file") new_file();   // Kies de functie
    else if (input == "ls") list();        //   op basis van
    else if (input == "src") src();        //   de invoer
    else if (input == "find") find();
    else if (input == "seek") seek();
    else if (input == "exit") return 0;
    else if (input == "quit") return 0;
    else if (input == "error") return 1;

    if (std::cin.eof()) return 0; } }      // EOF is een exit

void new_file() // ToDo: Implementeer volgens specificatie.
{ std::string bestandsnaam;
std::string bestandtekst;
std::cout << "schrijf een naam van het nieuwe bestand: ";
std::getline(std::cin, bestandsnaam);
std::cout << "Wat wil je schrijven in het bestand, eindig dit bericht met <EOF> : ";
std::getline(std::cin, bestandtekst);

int file = creat(bestandsnaam.c_str(), 0777);
ssize_t a = write(file, bestandtekst.c_str(), bestandtekst.size());

//open(bestandsnaam.c_str(), r_only)
 }

void list() // ToDo: Implementeer volgens specificatie.
{ std::cout << "ToDo: Implementeer hier list()" << std::endl;
if(fork() == 0){
char *args[] = {(char *) "/usr/bin/ls", (char *) "-la", (char *) 0};
execv("/usr/bin/ls", args);
}else{
int eindstatus;
wait(&eindstatus);
}}


void find() // ToDo: Implementeer volgens specificatie.
{ std::cout << "wat zoek je" << std::endl;
  std::string zoeken;
  std::getline(std::cin, zoeken);
  int pijpme[2];
  int status;
  int controle = pipe(pijpme);
  int id = fork();
  if(id == 0){
      char *arguments[] = {(char*)"find", (char*)"./",(char*)0};
      close(pijpme[0]);
      dup2(pijpme[1], STDOUT_FILENO);
      execv("/usr/bin/find",arguments);
  }
  id = fork();
  if(id == 0){
      char *parameter[]= {(char*)"grep", (char*)zoeken.c_str(), (char*)0};
      close(pijpme[1]);
      dup2(pijpme[0], STDIN_FILENO);
      execv("/usr/bin/grep",parameter);
  }
  close(pijpme[0]);
  close(pijpme[1]);
  waitpid(-1, &status, 0);
  waitpid(-1, &status, 0);
   }


void seek() // ToDo: Implementeer volgens specificatie.
{ std::cout << "ToDo: Implementeer hier seek()" << std::endl;
std::string loop = "loop.txt";
int seekCreated = creat("seek.txt", 0777);
int loopCreated = creat(loop.c_str(), 0777);
write(loopCreated, "x", 1);
std::string message = "\0";
for(int i = 0; i < 50000; i++){
write(loopCreated, "\0", 1);
}
write(loopCreated, "x", 1);

write(seekCreated, "x", 1);
lseek(seekCreated, 50000, SEEK_END);
write(seekCreated, "x", 1);

int id = fork();
if(id == 0){
char *args[] = {(char *) "/usr/bin/ls", (char *) "-lS", (char *) 0};
execv("/usr/bin/ls", args);
}else{
int eindstatus;
wait(&eindstatus);
}

//int pijpme[2];
//int status;
//int controle = pipe(pijpme);
//int id = fork();
//if(id == 0){ 
 // char *arguments[] = {(char*)"find", (char*)".",(char*)0};
 // close(pijpme[0]);
 // dup2(pijpme[1], STDOUT_FILENO);
 // execv("/usr/bin/find",arguments);
 // }
//id = fork();
//if(id == 0){
  //    char *parameter[]= {(char*)"grep", (char*)"*", (char*)0};
  //    close(pijpme[1]);
  //    dup2(pijpme[0], STDIN_FILENO);
  //    execv("/usr/bin/grep",parameter);
  //}
  //close(pijpme[0]);
  //close(pijpme[1]);
  //waitpid(-1, &status, 0);
  //waitpid(-1, &status, 0);
}












void src() // Voorbeeld: Gebruikt SYS_open en SYS_read om de source van de shell (shell.cc) te printen.
{ int fd = syscall(SYS_open, "shell.cc", O_RDONLY, 0755); // Gebruik de SYS_open call om een bestand te openen.
  char byte[1];                                           // 0755 zorgt dat het bestand de juiste rechten krijgt (leesbaar is).
  while(syscall(SYS_read, fd, byte, 1))                   // Blijf SYS_read herhalen tot het bestand geheel gelezen is,
    std::cout << byte; }                                  //   zet de gelezen byte in "byte" zodat deze geschreven kan worden.
